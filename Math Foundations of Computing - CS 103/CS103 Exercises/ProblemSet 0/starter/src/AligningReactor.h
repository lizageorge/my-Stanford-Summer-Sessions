#ifndef AligningReactor_Included
#define AligningReactor_Included

#include "Reactor.h"
#include "StateMachine.h"
#include "Star.h"
#include "gtimer.h"
#include <vector>
#include <memory>
#include <unordered_map>

/* Reactor that shows an animation of an existing collection of points aligning themselves
 * to a circle.
 */
class AligningReactor: public Reactor {
public:
    AligningReactor(std::shared_ptr<Star> star,
                    const std::vector<StarPoint *>& order,
                    const GPoint& center);

    ~AligningReactor();

    void handleEvent(GEvent e) override;

    /* Reports whether the animation has finished. */
    bool done() const;


    static void installHandlers(StateMachineBuilder& builder);

private:
    /* Underlying star. */
    std::shared_ptr<Star> theStar;

    /* Source and destination locations for each point. */
    std::unordered_map<StarPoint *, GPoint> sources;
    std::unordered_map<StarPoint *, GPoint> targets;

    /* Frame counter. */
    std::size_t frame = 0;

    /* Timer to advance the animation. */
    GTimer timer;
};

#endif
