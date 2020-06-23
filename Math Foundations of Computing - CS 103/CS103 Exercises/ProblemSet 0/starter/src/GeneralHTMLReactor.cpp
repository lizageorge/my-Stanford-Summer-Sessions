#include "GeneralHTMLReactor.h"
#include "strlib.h"
using namespace std;

void GeneralHTMLReactor::handleEvent(GEvent e) {
    if (e.getEventClass() == HYPERLINK_EVENT) {
        lastLink = e.getRequestURL();
    }
}

string GeneralHTMLReactor::lastLinkClicked() const {
    return lastLink;
}

/* Script integration. */
void GeneralHTMLReactor::installHandlers(StateMachineBuilder& builder) {
    /* Constructor: Decorate the previous reactor. */
    builder.addReactor("GeneralHTMLReactor", [](StateMachine &,
                                                const std::string &) {
        return make_shared<GeneralHTMLReactor>();
    });

    /* Transition: Report links clicked on the given page. */
    builder.addTransition("GeneralHTMLReactor", "Link", [](const string& args) {
        /* Extract the name of the link being clicked on. */
        string link;
        string destination;

        istringstream extractor(args);
        extractor >> link;
        getline(extractor, destination);

        if (!extractor) error("Could not parse star transition.");

        return [link, destination] (shared_ptr<Reactor> reactor) {
            auto me = static_pointer_cast<GeneralHTMLReactor>(reactor);
            return me->lastLinkClicked() == link? trim(destination) : "";
        };
    });
}
