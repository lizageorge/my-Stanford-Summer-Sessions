#ifndef AnimatedStarReactor_Included
#define AnimatedStarReactor_Included

#include "Reactor.h"
#include "StateMachine.h"
#include "StarType.h"
#include "Star.h"
#include "gtimer.h"
#include "gobjects.h"
#include <memory>
#include <vector>

/* Reactor that steps through the animation of the construction of a particular
 * star.
 */
class AnimatedStarReactor: public Reactor {
public:
    AnimatedStarReactor(GWindow& window, StarType type);
    ~AnimatedStarReactor();

    /* Sets the underlying star type, resetting the animation. */
    void setType(StarType type);

    void handleEvent(GEvent e) override;

    static void installHandlers(StateMachineBuilder& builder);

private /* helpers */:
    void handleTimerEvent(GTimerEvent e);
    void handleHyperlinkEvent(GHyperlinkEvent e);

    /* Determines whether we're in the star-drawing phase of the animation. */
    bool isDrawingStar() const;

    /* Tells us how many lines have been completed up to this point. */
    size_t lastCompletedLine() const;

    /* Progress along the current line. */
    size_t currentLineProgress() const;

private /* state */:
    GWindow& window;

    /* Underlying star. */
    std::shared_ptr<Star> star;

    /* Order of the points in that star. */
    std::vector<StarPoint *> points;

    /* Current star type. */
    StarType type;

    /* Current frame. */
    std::size_t frame;

    /* Line currently under construction. */
    GLine* currentLine;

    /* Timer that keeps everything going. */
    GTimer timer;
};


#endif
