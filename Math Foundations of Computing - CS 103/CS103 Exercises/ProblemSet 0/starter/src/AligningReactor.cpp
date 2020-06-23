#include "AligningReactor.h"
#include "FreeformEditorReactor.h"
#include "strlib.h"
#include <cmath>
#include <memory>
using namespace std;

namespace {
    const double kTimerDelay        = 25;    // ms
    const double kAnimationDuration = 2000;  // ms

    const size_t kAnimationFrames = kAnimationDuration / kTimerDelay;

    const double kWindowPadding = 20;

    /* Returns the angle formed by moving from the specified center point to the given
     * peripheral point.
     */
    double angleBetween(const GPoint& center, const GPoint& dest) {
        double dx = dest.getX() - center.getX();
        double dy = dest.getY() - center.getY();

        return atan2(dy, dx);
    }

    /* Maps a list of destination point angles to destination points by placing them
     * onto an appropriately-sized circle.
     */
    vector<GPoint> destinationsFor(const vector<double>& angles, double width, double height) {
        /* Compute the radius to use. This will be chosen so that the resulting figure
         * takes up the full canvas, minus the padding.
         */
        double radius = min(width, height) / 2.0 - StarPoint::kRadius - kWindowPadding;
        double centerX = width  / 2.0;
        double centerY = height / 2.0;

        vector<GPoint> result;
        for (auto angle: angles) {
            result.push_back({
                centerX + radius * cos(angle),
                centerY + radius * sin(angle)
            });
        }
        return result;
    }

    /* Given a number of points, returns the angles at which those points should end up getting
     * placed in the final layout.
     */
    vector<double> destinationAnglesFor(size_t numPoints) {
        /* Angle between points.
         *
         * We want to move clockwise, so we'd normally take a negative step. However,
         * we are also inverting the y axis, so by moving counterclockwise backwards,
         * we end up taking clockwise steps.
         */
        double thetaStep = 2 * M_PI / numPoints;

        /* Base angle. We want the first point to be at the bottom and slightly offset
         * from the vertical.
         */
        double thetaBase = 3 * M_PI / 2;

        /* Compute a layout of where everything goes. */
        vector<double> result;
        for (size_t i = 0; i < numPoints; i++) {
            result.push_back(thetaBase + thetaStep * i);
        }
        return result;
    }

    /* Interpolation function: given a real number in [0, 1], returns a new
     * real number in the range [0, 1] that maps to a smoother transition.
     *
     * This is the "smoothstep" function.
     */
    double interpolate(double alpha) {
        return -2 * alpha * alpha * alpha + 3 * alpha * alpha;
    }
}

AligningReactor::AligningReactor(shared_ptr<Star> star,
                                 const std::vector<StarPoint *>& order,
                                 const GPoint& center) :
    theStar(star), timer(kTimerDelay) {

    /* Get the final positions for each point in circular coordinate space. */
    auto angles = destinationAnglesFor(order.size());

    /* Assign each point to its target. The challenge is that the ordering of the points around
     * the circle might not perfectly sync up with the ordering of the points in the order
     * they were handed to us. Accordingly, we need to try to align them.
     *
     * The approach here works by picking an arbitrary point and then trying to align it so
     * that its angle is as close as possible to the target point's angle.
     */
    auto theta  = angleBetween(center, order[0]->center());

    /* Now, find the best point to match this point with. */
    size_t bestOffset = 0;
    double bestDistance = 2 * M_PI; // Something impossible

    for (size_t i = 0; i < angles.size(); i++) {
        double distance = fabs(angles[i] - theta);
        distance = min(distance, 2 * M_PI - distance);

        if (distance < bestDistance) {
            bestDistance = distance;
            bestOffset = i;
        }
    }

    /* With that in mind, map each point to its position. We'll iterate over the points in circle
     * order and assign each one its position, shifted over the the offset we determined above.
     */
    auto destinations = destinationsFor(angles, star->window().getCanvasWidth(), star->window().getCanvasHeight());
    for (size_t i = 0; i < order.size(); i++) {
        sources[order[i]] = order[i]->center();
        targets[order[i]] = destinations[(i + bestOffset) % destinations.size()];
    }

    timer.start();
}

AligningReactor::~AligningReactor() {
    timer.stop();
}

void AligningReactor::handleEvent(GEvent e) {
    /* We shouldn't do anything if we aren't in an animation. */
    if (done()) return;

    /* We shouldn't react to anything except timer events. */
    if (e.getEventClass() != TIMER_EVENT) return;

    /* Advance the animation one step forward. */
    frame++;

    /* Compute our interpolation factor. */
    double alpha = interpolate(frame / double(kAnimationFrames));

    /* Compute each point's new positions. */
    unordered_map<StarPoint *, GPoint> positions;
    for (auto point: theStar->points()) {
        double x = sources[point].getX() + alpha * (targets[point].getX() - sources[point].getX());
        double y = sources[point].getY() + alpha * (targets[point].getY() - sources[point].getY());
        positions[point] = { x, y };
    }

    /* Move all points. */
    theStar->window().setRepaintImmediately(false);
    for (auto point: theStar->points()) {
        point->graphicsPoint->setLocation(positions[point].getX() - StarPoint::kRadius,
                                          positions[point].getY() - StarPoint::kRadius);
    }

    /* Move all lines. */
    for (auto line: theStar->lines()) {
        line->graphicsLine->setStartPoint(positions[line->src].getX(),
                                          positions[line->src].getY());
        line->graphicsLine->setEndPoint(positions[line->dst].getX(),
                                        positions[line->dst].getY());
    }
    theStar->window().setRepaintImmediately(true);
    theStar->window().repaint();

    /* If we're done, stop the timer. */
    if (done()) timer.stop();
}

bool AligningReactor::done() const {
    return frame == kAnimationFrames;
}

/* Script integration. */
void AligningReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: No arguments. Steal the existing FreeformEditorReactor's fields. */
    builder.addReactor("AligningReactor", [](StateMachine& machine, const string &) {
        auto fer = dynamic_pointer_cast<FreeformEditorReactor>(machine.currentReactor());
        if (!fer) error("Previous reactor type was incorrect.");

        return make_shared<AligningReactor>(fer->star(), fer->pointsInOrder(), fer->center());
    });

    /* Transition: Check if we're done, and, if so, go to the indicated spot. */
    builder.addTransition("AligningReactor", "Done", [](const string& target) {
        return [target] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<AligningReactor>(reactor);
            return me->done()? trim(target) : "";
        };
    });
}
