#ifndef SummaryReactor_Included
#define SummaryReactor_Included

#include "Reactor.h"
#include "StateMachine.h"
#include <memory>

/* Reactor that reports a summary of everything that's happened so far.
 * This is used to output the completion code.
 */
class SummaryReactor: public Reactor {
public:
    SummaryReactor(StateMachine& machine);
    void handleEvent(GEvent e) override;

    static void installHandlers(StateMachineBuilder& builder);
};

#endif
