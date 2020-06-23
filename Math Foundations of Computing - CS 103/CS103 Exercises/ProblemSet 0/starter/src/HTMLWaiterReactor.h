#ifndef HTMLWaiterReactor_Included
#define HTMLWaiterReactor_Included

#include "Reactor.h"
#include "StateMachine.h"
#include <memory>

/* Reactor type that just waits for an HTML event that says "next."
 *
 * This Reactor holds on to a previous Reactor so as to preserve the graphics state and forwards
 * all underlying calls down to that reactor. This lets you stack reactors on top of one another
 * if you want to have something going while waiting for the user to click "next."
 */
class HTMLWaiterReactor: public Reactor {
public:
    HTMLWaiterReactor(std::shared_ptr<Reactor> previous);
    void handleEvent(GEvent e) override;
    bool done() const;

    static void installHandlers(StateMachineBuilder& builder);

private:
    std::shared_ptr<Reactor> previous;

    bool isDone = false;
};

#endif
