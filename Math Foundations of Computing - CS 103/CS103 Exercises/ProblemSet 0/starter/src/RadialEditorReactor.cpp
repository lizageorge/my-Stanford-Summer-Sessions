#include "RadialEditorReactor.h"
#include "strlib.h"
#include <string>
#include <sstream>
using namespace std;

namespace {
    const double kLineWidth = 4;
    const string kLineColor = "#FF0000";

    /* Given a proposed pair of points to run an edge through, determines whether to go ahead
     * and actually put that edge in.
     */
    bool shouldMakeEdge(Star& graphics, StarPoint* src, StarPoint* dst) {
        if (src == nullptr || dst == nullptr) return false;

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

RadialEditorReactor::RadialEditorReactor(GWindow& window, size_t numPoints) {
    /* Set up our line. */
    currentLine = new GLine(0, 0, 0, 0);
    currentLine->setColor(kLineColor);
    currentLine->setLineWidth(kLineWidth);

    tie(star, points) = radialLayoutFor(window, numPoints);
}

RadialEditorReactor::~RadialEditorReactor() {
    star->window().remove(currentLine);
    delete currentLine;
}

StarType RadialEditorReactor::type() const {
    return theType;
}

void RadialEditorReactor::handleMouseEvent(GMouseEvent e) {
    /* Press: Initiate a new line. */
    if (e.getEventType() == MOUSE_PRESSED) {
        /* We may get a spurious mouse press if one button is already pressed
         * down and the other button goes down. We need to ignore that.
         */
        if (origin != nullptr) return;

        /* Ensure there's a source point. If there isn't, we should not do anything. */
        origin = pointAt(*star, e.getX(), e.getY());
        if (origin != nullptr) {
            currentLine->setStartPoint(origin->center().getX(), origin->center().getY());
            currentLine->setEndPoint(origin->center().getX(), origin->center().getY());

            /* Add the line back to the window, but push it way down under the points. */
            star->window().setRepaintImmediately(false);
            star->window().add(currentLine);
            for (size_t i = 0; i < star->points().size(); i++) {
                currentLine->sendBackward();
            }
            star->window().setRepaintImmediately(true);
        }
    }
    /* Drag: Move the endpoint. */
    else if (e.getEventType() == MOUSE_DRAGGED) {
        /* The mouse may be dragged when nothing is selected, which can happen if
         * one mouse button is pressed down, the other is pressed down, and the
         * first is then released.
         */
        if (origin == nullptr) return;

        currentLine->setEndPoint(e.getX(), e.getY());
    }
    /* Release: Finalize the line, if appropriate. */
    else if (e.getEventType() == MOUSE_RELEASED) {
        /* We can have a spurious mouse release if both mouse buttons are used
         * in tandem with one another.
         */
        if (origin == nullptr) return;

        /* See whether we know the endpoint. If not, create a new endpoint. */
        auto dest = pointAt(*star, e.getX(), e.getY());
        if (shouldMakeEdge(*star, origin, dest)) {
            star->add(new StarLine(origin, dest));

            /* Update our guess of what kind of star this is based on what we just saw. */
            theType = starTypeOf(*star, points);
        }

        /* Either way, deactivate the current line. */
        origin = nullptr;
        star->window().remove(currentLine);
    }
}

void RadialEditorReactor::handleHyperlinkEvent(GHyperlinkEvent e) {
    if (e.getRequestURL() == "reset") {
        tie(star, points) = radialLayoutFor(star->window(), star->points().size());
    }
}

void RadialEditorReactor::handleEvent(GEvent e) {
    if (e.getEventClass() == MOUSE_EVENT) {
        handleMouseEvent(GMouseEvent(e));
    } else if (e.getEventClass() == HYPERLINK_EVENT) {
        handleHyperlinkEvent(GHyperlinkEvent(e));
    }
}

/* Script integration. */
void RadialEditorReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: See how many points to use. */
    builder.addReactor("RadialEditorReactor", [](StateMachine& machine, const string& args) {
        return make_shared<RadialEditorReactor>(machine.graphicsSystem()->window, stringToInteger(args));
    });

    /* Transition: Check if we're done, and, if so, go to the indicated spot. */
    builder.addTransition("RadialEditorReactor", "Star", [](const string& args) {
        /* Extract a star type and a destination page. */
        StarType type;
        string destination;

        istringstream extractor(args);
        extractor >> type;
        getline(extractor, destination);

        if (!extractor) error("Could not parse star transition.");

        return [type, destination] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<RadialEditorReactor>(reactor);
            return me->type() == type? trim(destination) : "";
        };
    });
}

