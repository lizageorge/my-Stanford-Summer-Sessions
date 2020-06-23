#ifndef Reactor_Included
#define Reactor_Included

#include "gevents.h"
#include <string>

class Reactor {
public:
    /* Interfaces need virtual destructors. */
    virtual ~Reactor() = default;

    /* Responds to an event. */
    virtual void handleEvent(GEvent e) = 0;
};

#endif
