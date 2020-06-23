#ifndef FreeformEditorReactor_Included
#define FreeformEditorReactor_Included

/* A reactor that gives the student the ability to interactively draw a star.
 *
 * The transitions emitted by this reactor correspond to the type of star that's
 * currently drawn.
 */

#include "Reactor.h"
#include "StarType.h"
#include "Star.h"
#include "StateMachine.h"
#include "gwindow.h"
#include "gobjects.h"
#include "gtimer.h"
#include <memory>

class FreeformEditorReactor: public Reactor {
public:
    /* Constructs a new FreeformEditor for the given window in an empty context. */
    FreeformEditorReactor(GWindow& window);

    /* Returns the underlying star graphics. */
    std::shared_ptr<Star> star() const;

    /* The graphical editor lets students create points wherever they'd like, but in order to
     * tell whether we're looking at a star, we need to have those points ordered as if they were
     * placed around some imaginary curve. This function returns one possible ordering of those
     * points around one possible hypothetical curve. This is just a guess - there's no guarantee
     * that it's correct.
     */
    std::vector<StarPoint *> pointsInOrder() const;

    /* The above function assumes that those points are ordered around some central point. This
     * function returns that central point.
     */
    GPoint center() const;

    /* The type of the star being drawn. */
    StarType type() const;

    void handleEvent(GEvent e) override;

    static void installHandlers(StateMachineBuilder& builder);


private /* Helpers */:
    void handleMouseEvent(GMouseEvent e);
    void handleHyperlinkEvent(GHyperlinkEvent e);

private /* State */:
    std::shared_ptr<Star> theStar;

    /* Source point of this line, if any. */
    StarPoint* origin = nullptr;

    /* Currently-drawn line, if any. */
    GLine* active = nullptr;

    /* Underlying star type. */
    StarType theType = kNotAStar;
};

#endif
