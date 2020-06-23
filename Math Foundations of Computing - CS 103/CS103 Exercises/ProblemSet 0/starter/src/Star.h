#ifndef StarGraphics_Included
#define StarGraphics_Included

#include "StarType.h"
#include "gobjects.h"
#include "gwindow.h"
#include <unordered_set>
#include <vector>
#include <utility>
#include <memory>

/* Type: StarPoint
 *
 * A type representing the point of a star.
 */
struct StarPoint {
    StarPoint(GPoint position);
    StarPoint(double x, double y);

    GPoint center() const;
    GOval* graphicsPoint;

    /* Radius of a StarPoint. */
    static const double kRadius;
};

/* Type: StarLine
 *
 * A type representing an edge in a star.
 */
struct StarLine {
    StarLine(StarPoint* src, StarPoint* dst);

    StarPoint* src;
    StarPoint* dst;
    GLine*     graphicsLine;

    /* Thickness of a line. */
    static const double kThickness;
};

/* Type: Star
 *
 * Collection of points and edges that make up a star graphics system.
 */
class Star {
public:
    Star(GWindow& window);
    ~Star();

    /* Adds a new point or line to the graphics system. */
    StarPoint* add(StarPoint* pt);
    StarLine*  add(StarLine*  edge);

    const std::unordered_set<StarPoint *>& points() const;
    const std::unordered_set<StarLine  *>& lines() const;
    GWindow& window();

private:
    GWindow& theWindow;
    std::unordered_set<StarPoint*> thePoints;
    std::unordered_set<StarLine *> theLines;
};

/* Hit testing. */
StarPoint* pointAt(const Star& g, double x, double y);
StarPoint* pointAt(const Star& g, const GPoint& pt);

/* Determines the star type of the given star, assuming the points are in the specified
 * order. If there isn't a star present, returns kNotAStar.
 */
StarType starTypeOf(const Star& graphics, const std::vector<StarPoint *>& order);

/* Utility function that produces a radial layout for a star, along with an ordering on the
 * points.
 */
std::tuple<std::shared_ptr<Star>, std::vector<StarPoint *>>
radialLayoutFor(GWindow& window, std::size_t numPoints);

#endif
