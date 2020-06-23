#include "Grabbag.h"
#include "error.h"
#include <cstdint>
#include <vector>
using namespace std;

namespace {
    /* Decodes a string that's been encoded using the COBS format. */
    const size_t kTooLong = 254;
    string decode(const string& data) {
      string result;

      size_t index = 0;
      uint8_t lastJump = 0;
      while (true) {
        /* If we're at a null byte, we're done. */
        if (data[index] == '\0') return result;

        /* Otherwise, this is the distance to the next zero byte. */
        uint8_t distance = static_cast<uint8_t>(data[index]);
        if (index + distance >= data.size()) error("Jump would take us out of packet?");

        /* Add in this zero byte if it wasn't artificially added in. We can tell if something
         * was artificially added because either
         *
         *  1. It's the very first byte, which is always artificial, or
         *  2. The jump size to reach this point exceeds what can happen naturally.
         */
        if (index != 0 && lastJump != kTooLong + 1) result += '\0';

        /* Add all the characters up to the next zero byte. */
        result += data.substr(index + 1, distance - 1);

        /* Scoot forward to this zero byte. */
        index += distance;

        lastJump = distance;
      }
    }

    /* Given a stream encoded in COBS format, converts that stream back into a list of strings. */
    vector<string> fromCOBS(istream& source) {
      vector<string> result;

      /* Keep pulling data, delimited by null bytes. */
      for (string entry; getline(source, entry, '\0'); ) {
        result.push_back(decode(entry + '\0'));
      }

      return result;
    }

    /* XORs one string with rotated copies of the given key. */
    string xorWith(const string& key, const string& input) {
      string result;

      for (size_t i = 0; i < input.size(); i++) {
        result += char(key[i % key.size()] ^ input[i]);
      }

      return result;
    }
}

Grabbag::Grabbag(istream& source) {
    /* Get a list of all the packets in the source stream. */
    auto packets = fromCOBS(source);

    /* There should be an odd number of packets here - the header contains an XOR key,
     * and then we're looking at pairs of filename/contents pairs.
     */
    if (packets.size() % 2 != 1) error("Expected an odd number of packets.");

    /* The first packet is the XOR key. */
    string key = packets[0];
    if (key.empty()) error("Empty XOR key?");

    /* Proceed to decode the rest of the packets. */
    for (size_t i = 1; i < packets.size(); i += 2) {
        string filename = xorWith(key, packets[i]);
        string contents = xorWith(key, packets[i + 1]);

        /* Confirm that this file doesn't already exist. */
        if (files.count(filename)) error("Duplicate file: " + filename);
        files[filename] = contents;
    }
}

bool Grabbag::fileExists(const string& filename) const {
    return files.count(filename);
}

string Grabbag::contentsOf(const string& filename) const {
    if (!fileExists(filename)) error("File does not exist: " + filename);
    return files.at(filename);
}
