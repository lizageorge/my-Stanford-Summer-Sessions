#include "HTMLWaiterReactor.h"
#include "strlib.h"
using namespace std;

HTMLWaiterReactor::HTMLWaiterReactor(shared_ptr<Reactor> previous) : previous(previous) {
    // Handled by initializer
}

void HTMLWaiterReactor::handleEvent(GEvent e) {
    if (e.getEventClass() == HYPERLINK_EVENT &&
        e.getRequestURL() == "next") {
        isDone = true;
    } else {
        previous->handleEvent(e);
    }
}

bool HTMLWaiterReactor::done() const {
    return isDone;
}

/* Script integration. */
void HTMLWaiterReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: Decorate the previous reactor. */
    builder.addReactor("HTMLWaiterReactor", [](StateMachine& machine, const string &) {
        return make_shared<HTMLWaiterReactor>(machine.currentReactor());
    });

    /* Transition: Check if we're done, and, if so, go to the indicated spot. */
    builder.addTransition("HTMLWaiterReactor", "Done", [](const string& target) {
        return [target] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<HTMLWaiterReactor>(reactor);
            return me->done()? trim(target) : "";
        };
    });
}
