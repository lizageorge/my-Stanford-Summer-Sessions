#include "Star.h"
#include <string>
#include <unordered_map>
using namespace std;

/* Graphics constants. */
const double StarPoint::kRadius   = 10;
const double StarLine::kThickness = 4;

namespace {
    const string kLineColor        = "#0000FF";

    const string kPointBorderColor = "#000040";
    const string kPointFillColor   = "#000080";

    const double kWindowPadding = 20;
}

StarPoint::StarPoint(GPoint pt) {
    graphicsPoint = new GOval(pt.getX() - kRadius, pt.getY() - kRadius, 2 * kRadius, 2 * kRadius);
    graphicsPoint->setFilled(true);
    graphicsPoint->setColor(kPointBorderColor);
    graphicsPoint->setFillColor(kPointFillColor);
}
StarPoint::StarPoint(double x, double y) : StarPoint(GPoint(x, y)) {
    // Handled by delegation
}

GPoint StarPoint::center() const {
    return {
        graphicsPoint->getX() + kRadius,
        graphicsPoint->getY() + kRadius
    };
}

StarLine::StarLine(StarPoint* src, StarPoint* dst) : src(src), dst(dst) {
    graphicsLine = new GLine(src->center().getX(), src->center().getY(),
                             dst->center().getX(), dst->center().getY());
    graphicsLine->setLineWidth(kThickness);
    graphicsLine->setColor(kLineColor);
}

/* StarGraphics constructor holds a handle to the window. */
Star::Star(GWindow& window) : theWindow(window) {

}

/* Destructor cleans up all pointers to points and edges. The window itself will take
 * care of deallocating the graphics objects.
 */
Star::~Star() {
    /* Disable graphics so that we don't see everything getting removed. */
    theWindow.setRepaintImmediately(false);

    for (auto obj: thePoints) {
        theWindow.remove(obj->graphicsPoint);
        delete obj;
    }
    for (auto obj: theLines) {
        theWindow.remove(obj->graphicsLine);
        delete obj;
    }

    theWindow.setRepaintImmediately(true);
    theWindow.repaint();
}

StarPoint* Star::add(StarPoint* pt) {
    thePoints.insert(pt);
    theWindow.add(pt->graphicsPoint);
    return pt;
}

StarLine* Star::add(StarLine* edge) {
    theLines.insert(edge);

    /* Adding the line to the window will put it in the wrong place - it'll overdraw the
     * points. To fix this, we'll push the line down to its proper position.
     */
    /* TODO: Save and restore old graphics state? */
    theWindow.setRepaintImmediately(false);

    theWindow.add(edge->graphicsLine);
    for (size_t i = 0; i < thePoints.size(); i++) {
        edge->graphicsLine->sendBackward();
    }

    theWindow.setRepaintImmediately(true);
    theWindow.repaint();

    return edge;
}

const unordered_set<StarPoint *>& Star::points() const {
    return thePoints;
}
const unordered_set<StarLine *>& Star::lines() const {
    return theLines;
}
GWindow& Star::window() {
    return theWindow;
}

StarPoint* pointAt(const Star& g, const GPoint& pt) {
    return pointAt(g, pt.getX(), pt.getY());
}
StarPoint* pointAt(const Star& g, double x, double y) {
    for (auto point: g.points()) {
        double dx = point->center().getX() - x;
        double dy = point->center().getY() - y;

        if (dx * dx + dy * dy <= StarPoint::kRadius * StarPoint::kRadius) return point;
    }
    return nullptr;
}

namespace {
    using Graph = unordered_map<StarPoint *, unordered_set<StarPoint *>>;

    /* Converts the edge-list representation of a star into an adjacency list. */
    Graph asGraph(const Star& graphics) {
        Graph result;

        /* Associate each point with an empty list so that we don't lose any nodes. */
        for (auto point: graphics.points()) {
            result.insert(Graph::value_type(point, {}));
        }

        /* Fill in the edges. */
        for (auto edge: graphics.lines()) {
            result[edge->src].insert(edge->dst);
            result[edge->dst].insert(edge->src);
        }

        return result;
    }

    /* Given a graph, guesses an origin point and step size for that graph. The first
     * component is the index of the starting point and the second is the hypothesized
     * step size.
     */
    tuple<size_t, size_t> stepSizeGuessFor(const Graph& graph, const vector<StarPoint *>& order) {
        /* Find some point that has edges leaving it, and some point it's adjacent to. */
        size_t source = 0;
        for (size_t i = 0; i < order.size(); i++) {
            if (!graph.at(order[i]).empty()) {
                source = i;
                break;
            }
        }

        /* Find some outgoing edge. */
        const auto& edges = graph.at(order[source]);
        size_t target = size_t(distance(order.begin(), find(order.begin(), order.end(), *edges.begin())));

        /* Pick either their difference, or the mirror value, whichever is smaller. */
        size_t stepSize = max(target, source) - min(target, source);
        return make_tuple(source, min(stepSize, graph.size() - stepSize));
    }
}

/* Determines the type of the current star and the circle ordering of each of the points. The
 * returned vector maps each point to its circle index and is only valid if the points form
 * a star.
 */
StarType starTypeOf(const Star& graphics, const vector<StarPoint *>& order) {
    /* If there are no points, there isn't a star. */
    if (graphics.points().size() == 0) return kNotAStar;

    /* If there is exactly one point, it's the 1/1 star. */
    if (graphics.points().size() == 1) return { 1, 1 };

    /* If there are no lines at all, this is the { p, 0 } star. */
    if (graphics.lines().empty()) return { graphics.points().size(), 0 };

    /* If there are two points, this is the { 2 / 1 } star because we know there's at least
     * one edge.
     */
    if (graphics.points().size() == 2) return { 2, 1 };

    /* Convert the edge list in insertion order into an adjacency list in circle order. */
    auto graph = asGraph(graphics);

    /* Get a guess of the step size. */
    size_t source, stepSize;
    tie(source, stepSize) = stepSizeGuessFor(graph, order);

    /* Confirm that this is a valid step size by seeing if we can trace around the circle.
     * As we do, we'll keep track of how many lines we visited.
     */
    size_t linesVisited = 0;
    size_t curr = source;
    do {
        size_t next = (curr + stepSize) % graphics.points().size();
        if (!graph[order[curr]].count(order[next])) return kNotAStar;

        curr = next;
        linesVisited++;
    } while (curr != source);

    /* If we visited every line, we have a star! */
    if (linesVisited == graphics.lines().size()) return { graphics.points().size(), stepSize };

    return kNotAStar;
}

/* Constructs a radial layout for a star, returning both a Star and a list of the
 * points in radial order.
 */
tuple<shared_ptr<Star>, vector<StarPoint *>> radialLayoutFor(GWindow& window, size_t numPoints) {
    /* Information about the angles to use. */
    double thetaStep = -2 * M_PI / numPoints;           // Negative so that we move clockwise
    double thetaBase =  3 * M_PI / 2 + (numPoints % 2) * thetaStep / 2.0; // Place point 0 at the bottom.

    /* Radius to use. */
    double radius  = min(window.getCanvasWidth(), window.getCanvasHeight()) / 2.0 - StarPoint::kRadius - kWindowPadding;
    double centerX = window.getCanvasWidth()  / 2.0;
    double centerY = window.getCanvasHeight() / 2.0;

    auto star = make_shared<Star>(window);
    vector<StarPoint *> points;

    window.setRepaintImmediately(false);
    for (size_t i = 0; i < numPoints; i++) {
        double theta = thetaBase + thetaStep * i;
        double x = centerX + radius * cos(theta);
        double y = centerY - radius * sin(theta); // Y coordinate is inverted
        points.push_back(star->add(new StarPoint(x, y)));
    }
    window.setRepaintImmediately(true);
    window.repaint();

    return make_tuple(star, points);
}
