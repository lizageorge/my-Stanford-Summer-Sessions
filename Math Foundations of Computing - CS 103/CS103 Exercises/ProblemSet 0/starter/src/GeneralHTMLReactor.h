#ifndef GeneralHTMLReactor_Included
#define GeneralHTMLReactor_Included

#include "Reactor.h"
#include "StateMachine.h"
#include <memory>

/* Reactor type that waits for HTML events and forwards them back as strings.
 *
 * This Reactor holds on to a previous Reactor so as to preserve the graphics state and forwards
 * all underlying calls down to that reactor. This lets you stack reactors on top of one another
 * if you want to have something going while waiting for the user to interact.
 */
class GeneralHTMLReactor: public Reactor {
public:
    void handleEvent(GEvent e) override;

    /* Returns whether a link has been clicked that hasn't been handled yet. */
    bool hasUnreadLink() const;

    /* Returns the last link clicked, or the empty string if nothing was clicked. */
    std::string lastLinkClicked() const;

    static void installHandlers(StateMachineBuilder& builder);

private:
    /* The last link clicked. */
    std::string lastLink;
};

#endif
