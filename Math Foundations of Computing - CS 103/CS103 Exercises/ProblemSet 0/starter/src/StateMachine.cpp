#include "StateMachine.h"
#include "strlib.h"
#include <string>
#include <sstream>
using namespace std;

namespace {
    /* Header start and end. */
    const string kHeaderStart = "<!-- StateMachine";
    const string kHeaderEnd   = "-->";

    /* Command headers. */
    const string kSetHTML       = "HTML:";
    const string kSetReactor    = "Reactor:";
    const string kAddTransition = "Transition:";

    /* Strips comments and leading/trailing whitespace from a line. */
    string cleanLine(string line) {
        /* Strip comments. */
        auto commentStart = line.find('#');
        if (commentStart != string::npos) {
            line = line.substr(0, commentStart);
        }

        return trim(line);
    }

    /* Returns the next token in a stream, reporting an error if this isn't possible. */
    string nextToken(istream& source) {
        string result;
        if (source >> result, !source) error("Unexpected end-of-line.");
        return result;
    }

    /* Expects there to be nothing left in a stream, reporting an error if there is. */
    void expectDone(istream& source) {
        char ch;
        if (source >> ch) error("Unexpected character: " + string(1, ch));
    }
}

/* * * * * StateMachine implementation * * * * */

/* React to an event by forwarding the event down to the underlying reactor and seeing if we
 * need to change state.
 */
void StateMachine::handleEvent(GEvent e) {
    reactor->handleEvent(e);

    for (auto& transition: transitions) {
        auto dest = transition(reactor);
        if (dest != "") {
            setState(dest);
            break;
        }
    }
}

/* Changing state necessitates sourcing the contents for the new state and interpreting what
 * we find. Acceptable commands are
 *
 *   HTML    [state-name]:     Changes the HTML to display to the HTML associated
 *                             with the given state.
 *   Reactor [reactor] [args]: Changes the reactor to the specified reactor. This command
 *                             removes all old transitions in anticipation of a new set.
 *   Transition [type] [args]: Adds the specified transition to the list of transitions. This must
 *                             be done AFTER specifying the reactor, as transitions are reactor-
 *                             specific.
 */
void StateMachine::setState(const string& state) {
    /* Report that we've changed state. */
    for (auto& entry: plugins) {
        entry.second->onStateChanged(state);
    }

    auto source = reader(state);


    /* Confirm that the first line matches what we expect. */
    string firstLine;
    if (!getline(*source, firstLine)) error("Couldn't read initial line of state " + state);
    if (firstLine != kHeaderStart)    error("First line of state " + state + " is not config info.");

    /* Type of reactor selected. */
    string reactorName = "";
    for (string line; getline(*source, line); ) {
        /* Remove comments, etc. from this line and skip if if there's nothing left. */
        line = cleanLine(line);
        if (line.empty()) continue;

        /* If we hit the end, we're done. */
        if (line == kHeaderEnd) break;

        /* See what kind of command this is. */
        istringstream extractor(line);
        string command = nextToken(extractor);

        if (command == kSetHTML) {
            setHTML(extractor);
        } else if (command == kSetReactor) {
            setReactor(extractor, reactorName);
        } else if (command == kAddTransition) {
            addTransition(extractor, reactorName);
        } else {
            error("Unknown command: " + command);
        }
    }
}

void StateMachine::setHTML(istream& command) {
    auto htmlSource = reader(nextToken(command));
    expectDone(command);

    /* Skip until we find the end of the reactor description. */
    for (string line; getline(*htmlSource, line) && line != kHeaderEnd; ) {
        // Do nothing
    }

    graphics->pane->readTextFromFile(*htmlSource);
}

void StateMachine::setReactor(istream& command, string& reactorName) {
    /* Something's wrong if the reactor has already been set. */
    if (!reactorName.empty()) error("Attempting to set the reactor twice?");

    reactorName = nextToken(command);
    if (!reactorConstructors.count(reactorName)) error("Unknown reactor type: " + reactorName);

    /* Pass the remaining arguments into the constructor. */
    string args;
    getline(command, args);

    reactor = reactorConstructors[reactorName](*this, args);

    /* Clear out any transitions; they're now stale. */
    transitions.clear();
}

void StateMachine::addTransition(istream& command, const string& reactorName) {
    /* Something is wrong if no reactor has been set. */
    if (reactorName.empty()) error("Attempting to read a transition without a reactor?");
    if (!transitionConstructors.count(reactorName)) {
        error("No transitions defined for reactor type " + reactorName);
    }

    string transitionType = nextToken(command);
    if (!transitionConstructors.at(reactorName).count(transitionType)) {
        error("No transition named " + transitionType + " associated with reactor " + reactorName);
    }

    string args;
    getline(command, args);

    transitions.push_back(transitionConstructors.at(reactorName).at(transitionType)(args));
}

shared_ptr<GraphicsSystem> StateMachine::graphicsSystem() const {
    return graphics;
}

shared_ptr<Reactor> StateMachine::currentReactor() const {
    return reactor;
}

shared_ptr<Plugin> StateMachine::pluginNamed(const string& name) const {
    if (!plugins.count(name)) error("No pluging named " + name + " exists.");
    return plugins.at(name);
}

/* * * * * StateMachineBuilder implementation * * * * */
StateMachineBuilder::StateMachineBuilder(shared_ptr<GraphicsSystem> graphics,
                                         const string& initialState,
                                         StateReader reader) {
    result.graphics = graphics;
    result.reader = reader;
    this->initialState = initialState;
}

void StateMachineBuilder::addReactor(const string& name, ReactorConstructor constructor) {
    if (result.reactorConstructors.count(name)) {
        error("Duplicate reactor type: " + name);
    }

    result.reactorConstructors[name] = constructor;
}

void StateMachineBuilder::addTransition(const string& reactorName,
                                        const string& name,
                                        TransitionConstructor constructor) {
    if (!result.reactorConstructors.count(reactorName)) {
        error("Unknown reactor type: " + reactorName);
    }

    if (result.transitionConstructors[reactorName].count(name)) {
        error("Duplicate transition: " + reactorName + "::" + name);
    }

    result.transitionConstructors[reactorName][name] = constructor;
}

void StateMachineBuilder::addPlugin(const string& name, std::shared_ptr<Plugin> plugin) {
    if (result.plugins.count(name)) error("Duplicate plugin: " + name);
    result.plugins[name] = plugin;
}

shared_ptr<StateMachine> StateMachineBuilder::build() const {
    auto machine = make_shared<StateMachine>(result);
    machine->setState(initialState);
    return machine;
}
