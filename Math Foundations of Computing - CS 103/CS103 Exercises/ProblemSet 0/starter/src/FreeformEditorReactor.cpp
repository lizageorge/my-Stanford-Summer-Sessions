#include "FreeformEditorReactor.h"
#include "StarType.h"
#include "strlib.h"
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

namespace {
    /* Graphics constants. */
    const double kLineWidth = 4;
    const string kLineColor = "#FF0000";

    /* Given a collection of points, returns our best guess for where the center should be. */
    GPoint centerOf(const unordered_set<StarPoint *>& pts) {
        /* Return the barycenter. TODO: Investigate better ways to do this? */
        double x = 0;
        double y = 0;

        for (const auto& pt: pts) {
            x += pt->center().getX();
            y += pt->center().getY();
        }

        return { x / pts.size(), y / pts.size() };
    }

    /* Returns the angle formed by moving from the specified center point to the given
     * peripheral point.
     */
    double angleBetween(const GPoint& center, const GPoint& dest) {
        double dx = dest.getX() - center.getX();
        double dy = dest.getY() - center.getY();

        return atan2(dy, dx);
    }

    using OrderedPoints = unordered_map<StarPoint *, size_t>;

    /* Given a collection of points, returns the order in which they appear around the perimeter
     * of a circle - or, at least, our best guess.
     */
    OrderedPoints orderOf(const unordered_set<StarPoint *>& pts) {
        GPoint center = centerOf(pts);

        /* Sort the points by the angle they make with the circle center. */
        vector<StarPoint *> ordering(pts.begin(), pts.end());
        sort(ordering.begin(), ordering.end(), [&](StarPoint* lhs, StarPoint* rhs) {
            return angleBetween(center, lhs->center()) < angleBetween(center, rhs->center());
        });

        /* Map each star point to its index. */
        OrderedPoints result;
        for (size_t i = 0; i < ordering.size(); i++) {
            result[ordering[i]] = i;
        }

        return result;
    }

    /* Creates a new line that's the active line in the editor. */
    GLine* makeActiveLine(Star& graphics, const GPoint& pos) {
        GLine* result = new GLine(pos.getX(), pos.getY(), pos.getX(), pos.getY());
        result->setLineWidth(kLineWidth);
        result->setColor(kLineColor);

        graphics.window().add(result);

        /* Push this behind the points so it doesn't overdraw them. */
        for (size_t i = 0; i < graphics.points().size(); i++) {
            result->sendBackward();
        }

        return result;
    }

    /* Given a proposed pair of points to run an edge through, determines whether to go ahead
     * and actually put that edge in.
     */
    bool shouldMakeEdge(Star& graphics, StarPoint* src, StarPoint* dst) {
        /* Never make lines between a point and itself. */
        if (src == dst) return false;

        /* Don't make a copy of an edge we already have. */
        for (auto line: graphics.lines()) {
            if (line->src == src && line->dst == dst) return false;
            if (line->dst == src && line->src == dst) return false;
        }

        return true;
    }
}

void FreeformEditorReactor::handleEvent(GEvent e) {
    if (e.getEventClass() == MOUSE_EVENT) {
        handleMouseEvent(GMouseEvent(e));
    } else if (e.getEventClass() == HYPERLINK_EVENT) {
        handleHyperlinkEvent(GHyperlinkEvent(e));
    }
}

void FreeformEditorReactor::handleHyperlinkEvent(GHyperlinkEvent e) {
    if (e.getRequestURL() == "reset") {
        theStar = make_shared<Star>(theStar->window());
        if (active) {
            theStar->window().remove(active);
            delete active;
            active = nullptr;
        }
        theType = kNotAStar;
    }
}

void FreeformEditorReactor::handleMouseEvent(GMouseEvent e) {
    /* Press: Initiate a new line. */
    if (e.getEventType() == MOUSE_PRESSED) {
        /* It's possible that we're currently dragging and the mouse press
         * we're getting is from the other mouse button. If that's the case,
         * don't do anything.
         */
        if (active != nullptr) return;

        /* Ensure there's a source point. If there isn't, go make one. */
        origin = pointAt(*theStar, e.getX(), e.getY());
        if (origin == nullptr) origin = theStar->add(new StarPoint(e.getX(), e.getY()));

        active = makeActiveLine(*theStar, origin->center());
    }
    /* Drag: Move the endpoint. */
    else if (e.getEventType() == MOUSE_DRAGGED) {
        /* It's possible that there is no active line, which happens if, say,
         * both mouse buttons were pressed, one was released, and the other
         * is still down.
         */
        if (active == nullptr) return;

        active->setEndPoint(e.getX(), e.getY());
    }
    /* Release: Finalize the line, if appropriate. */
    else if (e.getEventType() == MOUSE_RELEASED) {
        /* Again, it's possible that there is no active line, which can happen if
         * two mouse buttons were independently pressed down.
         */
        if (active == nullptr) return;

        /* See whether we know the endpoint. If not, create a new endpoint. */
        auto dest = pointAt(*theStar, e.getX(), e.getY());
        if (dest == nullptr) {
            dest = theStar->add(new StarPoint(e.getX(), e.getY()));
        }

        if (shouldMakeEdge(*theStar, origin, dest)) {
            theStar->add(new StarLine(origin, dest));

            /* Update our guess of what kind of star this is based on what we just saw. */
            theType = starTypeOf(*theStar, pointsInOrder());
        }

        /* Either way, deactivate the current line. */
        origin = nullptr;

        theStar->window().remove(active);
        delete active;
        active = nullptr;
    }
}

/* Constructor stashes the window away for later use. */
FreeformEditorReactor::FreeformEditorReactor(GWindow& window) :
    theStar(make_shared<Star>(window)) {

}

shared_ptr<Star> FreeformEditorReactor::star() const {
    return theStar;
}

vector<StarPoint *> FreeformEditorReactor::pointsInOrder() const {
    auto inverse = orderOf(theStar->points());
    vector<StarPoint *> result(inverse.size());

    for (const auto& entry: inverse) {
        result[entry.second] = entry.first;
    }

    return result;
}

GPoint FreeformEditorReactor::center() const {
    return centerOf(theStar->points());
}

StarType FreeformEditorReactor::type() const {
    return theType;
}

/* Script integration. */
void FreeformEditorReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: No arguments. */
    builder.addReactor("FreeformEditorReactor", [](StateMachine& machine,
                                                   const string &) {
        return make_shared<FreeformEditorReactor>(machine.graphicsSystem()->window);
    });

    /* Transition: Check if we're done, and, if so, go to the indicated spot. */
    builder.addTransition("FreeformEditorReactor", "Star", [](const string& args) {
        /* Extract a star type and a destination page. */
        StarType type;
        string destination;

        istringstream extractor(args);
        extractor >> type;
        getline(extractor, destination);

        if (!extractor) error("Could not parse star transition.");

        return [type, destination] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<FreeformEditorReactor>(reactor);
            return me->type() == type? trim(destination) : "";
        };
    });
}
