#include "StarType.h"
#include "error.h"
#include <sstream>
#include <limits>
using namespace std;

/* Constant indicating something that isn't a star. */
const StarType kNotAStar = {
    numeric_limits<size_t>::max(),
    numeric_limits<size_t>::max()
};

bool operator== (const StarType& lhs, const StarType& rhs) {
    return lhs.numPoints == rhs.numPoints &&
           lhs.stepSize  == rhs.stepSize;
}
bool operator!= (const StarType& lhs, const StarType& rhs) {
    return !(lhs == rhs);
}

ostream& operator<< (ostream& out, const StarType& type) {
    if (type == kNotAStar) {
        return out << "(not a star)";
    }

    ostringstream result;
    result << "{ " << type.numPoints << " / " << type.stepSize << " }";
    return out << result.str();
}

istream& operator>> (istream& in, StarType& type) {
    istream::sentry sentry(in);
    if (sentry) {
        char brace, slash, closeBrace;
        size_t numPoints, stepSize;
        if (in >> brace >> numPoints >> slash >> stepSize >> closeBrace &&
            brace == '{' &&
            slash == '/' &&
            closeBrace == '}') {
            type.numPoints = numPoints;
            type.stepSize  = stepSize;
        } else {
            in.setstate(ios::failbit);
        }
    }
    return in;
}

string to_string(const StarType& star) {
    ostringstream result;
    result << star;
    return result.str();
}

StarType from_string(const string& text) {
    StarType result;

    istringstream extractor(text);
    if (extractor >> result, !extractor) error("Internal error: Can't parse " + text);
    for (char garbage; extractor >> garbage; ) error("Internal error: Unexpected " + string(1, garbage));

    return result;
}
