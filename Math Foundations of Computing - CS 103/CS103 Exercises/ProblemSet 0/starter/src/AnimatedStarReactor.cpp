#include "AnimatedStarReactor.h"
#include "HTMLWaiterReactor.h"
#include <cmath>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

namespace {
    const double kFrameDelay        = 25;  // ms
    const double kLineAnimationTime = 1000; // ms
    const size_t kFramesPerLine     = kLineAnimationTime / kFrameDelay;

    const double kTerminalPauseTime = 2000;
    const size_t kFramesAtEnd       = kTerminalPauseTime / kFrameDelay;

    const double kLineWidth = 4;
    const string kLineColor = "#FF0000";

    /* Interpolation function: given a real number in [0, 1], returns a new
     * real number in the range [0, 1] that maps to a smoother transition.
     *
     * This is the "smootheststep" function.
     */
    double interpolate(double alpha) {
        return -20 * pow(alpha, 7) + 70 * pow(alpha, 6) - 84 * pow(alpha, 5) + 35 * pow(alpha, 4);
    }
}

AnimatedStarReactor::AnimatedStarReactor(GWindow& window, StarType type)
    : window(window), timer(kFrameDelay) {

    /* Set up our line. */
    currentLine = new GLine(0, 0, 0, 0);
    currentLine->setLineWidth(kLineWidth);
    currentLine->setColor(kLineColor);
    window.add(currentLine);

    /* Kick things off! */
    setType(type);

    timer.start();
}

AnimatedStarReactor::~AnimatedStarReactor() {
    window.remove(currentLine);
    delete currentLine;

    timer.stop();
}

void AnimatedStarReactor::setType(StarType type) {
    this->type = type;

    tie(star, points) = radialLayoutFor(window, type.numPoints);
    frame = 0;

    /* Move the line to the center of the first point. */
    window.setRepaintImmediately(false);
    currentLine->setStartPoint(points[0]->center().getX(), points[0]->center().getY());
    currentLine->setEndPoint  (points[0]->center().getX(), points[0]->center().getY());
    window.setRepaintImmediately(true);
}

/* We're currently drawing a star if the current line hasn't been finished yet. */
bool AnimatedStarReactor::isDrawingStar() const {
    size_t lastLine = frame / kFramesPerLine;
    return lastLine < type.numPoints;
}

size_t AnimatedStarReactor::lastCompletedLine() const {
    if (!isDrawingStar()) error("Internal logic error: Should not be calling this function if done!");

    return frame / kFramesPerLine;
}

size_t AnimatedStarReactor::currentLineProgress() const {
    if (!isDrawingStar()) error("Internal logic error: Should not be calling this function if done!");

    return frame % kFramesPerLine;
}

void AnimatedStarReactor::handleTimerEvent(GTimerEvent) {
    frame++;

    /* If we hit the end, reset. */
    if (frame == kFramesPerLine * type.numPoints + kFramesAtEnd) {
        setType(type);
        return;
    }

    /* Otherwise, if we need to make progress on our line, go do so. */
    if (!isDrawingStar()) return;

    /* Where we're coming from and going to. */
    size_t src = (lastCompletedLine() * type.stepSize) % type.numPoints;
    size_t dst = (src + type.stepSize) % type.numPoints;

    size_t progress = currentLineProgress();

    /* On the last frame, officially add the line in and shift to the next point. */
    if (progress + 1 == kFramesPerLine) {
        star->add(new StarLine(points[src], points[dst]));
        currentLine->setStartPoint(points[dst]->center().getX(), points[dst]->center().getY());

        /* To keep the red line on top, move it higher up in the Z-ordering, putting it on top
         * of the newly-added line.
         */
        currentLine->sendForward();
    }
    /* Update the current line to show progress. */
    else {
        double alpha = interpolate(progress / (double) kFramesPerLine);

        double dx = points[dst]->center().getX() - points[src]->center().getX();
        double dy = points[dst]->center().getY() - points[src]->center().getY();

        double xEnd = points[src]->center().getX() + dx * alpha;
        double yEnd = points[src]->center().getY() + dy * alpha;

        currentLine->setEndPoint(xEnd, yEnd);
    }
}

void AnimatedStarReactor::handleHyperlinkEvent(GHyperlinkEvent e) {
    setType(from_string(e.getRequestURL()));
}

void AnimatedStarReactor::handleEvent(GEvent e) {
    /* Make sure this is a timer event that we're meant to receive. */
    if (e.getEventClass() == TIMER_EVENT) {
        handleTimerEvent(GTimerEvent(e));
    } else if (e.getEventClass() == HYPERLINK_EVENT) {
        handleHyperlinkEvent(GHyperlinkEvent(e));
    }
}

/* Script integration. */
void AnimatedStarReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: See what type of star to draw. Notice that we're always wrapped in an
     * HTMLWaiterReactor.
     */
    builder.addReactor("AnimatedStarReactor", [](StateMachine& machine,
                                                 const string& args) {
        return make_shared<HTMLWaiterReactor>(make_shared<AnimatedStarReactor>(machine.graphicsSystem()->window, from_string(args)));
    });

    /* Transition: Check if we're done, and, if so, go to the indicated spot. */
    builder.addTransition("AnimatedStarReactor", "Done", [](const string& target) {
        return [target] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<HTMLWaiterReactor>(reactor);
            return me->done()? trim(target) : "";
        };
    });
}
