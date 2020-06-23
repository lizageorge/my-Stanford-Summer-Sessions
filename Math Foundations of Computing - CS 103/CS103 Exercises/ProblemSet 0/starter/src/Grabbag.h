#ifndef Grabbag_Included
#define Grabbag_Included

#include <unordered_map>
#include <string>
#include <fstream>

/* A type that can read grabbag files. Each grabbag file represents the contents of
 * a particular directory tree compacted into a single file.
 */
class Grabbag {
public:
    /* Constructs a Grabbag from the specified input source. */
    explicit Grabbag(std::istream& source);

    /* Returns whether there is a file with the given name. */
    bool fileExists(const std::string& filename) const;

    /* Returns the contents of the file with the given name. If no such file exists,
     * an error is reported.
     */
    std::string contentsOf(const std::string& filename) const;

private:
    std::unordered_map<std::string, std::string> files;
};


#endif
