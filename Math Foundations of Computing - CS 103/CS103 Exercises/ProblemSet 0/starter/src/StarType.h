#ifndef Star_Included
#define Star_Included

#include <cstddef> // For std::size_t
#include <istream>
#include <ostream>
#include <string>

/* Type encoding a star using { s / p } notation. */
struct StarType {
    std::size_t numPoints;
    std::size_t stepSize;
};

extern const StarType kNotAStar;

bool operator== (const StarType& lhs, const StarType& rhs);
bool operator!= (const StarType& lhs, const StarType& rhs);

std::ostream& operator<< (std::ostream& out, const StarType& star);
std::istream& operator>> (std::istream& in,  StarType& star);

/* Utility functions to convert StarTypes to and from strings. */
std::string to_string(const StarType& star);
StarType  from_string(const std::string& text);

#endif
