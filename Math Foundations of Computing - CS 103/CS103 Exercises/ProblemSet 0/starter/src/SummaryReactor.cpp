#include "SummaryReactor.h"
#include "goptionpane.h"
#include "strlib.h"
#include "base64.h"
#include <vector>
#include <random>
using namespace std;

namespace {
    /* Plugin that tracks the history of all states visited. */
    class HistoryPlugin: public Plugin {
    public:
        void onStateChanged(const string& state) override {
            /* Don't record revisits of the same state. */
            if (theHistory.empty() || theHistory.back() != state) {
                theHistory.push_back(state);
            }
        }

        vector<string> history() const {
            return theHistory;
        }

    private:
        vector<string> theHistory;
    };

    /* String to target for replacement with the completion code. */
    const string kCompletionTarget = "(Once you've entered your email address, the completion code will show here.)";

    const string kEmailPrompt  = "Please enter your @stanford.edu email address into the box below.";
    const string kMessageTitle = "Email Address";
    const string kDefaultValue = "@stanford.edu";

    const string kConfirmTitle = "Confirm Email";

    string promptForEmail() {
        while (true) {
            string email = GOptionPane::showInputDialog(kEmailPrompt, kMessageTitle, kDefaultValue);
            if (endsWith(email, "@stanford.edu") && email[0] != '@') {
                if (GOptionPane::showConfirmDialog("You entered " + email + ".\n\nIs this correct?", kConfirmTitle) == GOptionPane::CONFIRM_YES) {
                    return email;
                }
            }
        }
    }

    /* Sorry, we won't say what this does. :-) */
    const size_t kPizkwat = 16;
    string getQuokka() {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<char> distribution;

        string result;
        for (size_t i = 0; i < kPizkwat; i++) {
            result += distribution(generator);
        }

        return result;
    }

    string dikdik(const string& pudu, const string& gerenuk) {
        string result;
        for (size_t i = 0; i < gerenuk.size(); i++) {
            result += static_cast<char>(gerenuk[i] ^ pudu[i % pudu.size()]);
        }
        return result;
    }

    /* Generates the completion code that's presented to the student. */
    string completionCodeFor(StateMachine& machine, const string& springbok) {
        /* Sorry - we're not going to explain what this code does. :-) */
        auto history = static_pointer_cast<HistoryPlugin>(machine.pluginNamed("SummaryReactorHistory"));
        auto cutie   = getQuokka();

        string initial;
        for (auto entry: history->history()) {
            initial += entry + "/";
        }
        initial += springbok + "/";

        /* We're also not going to explain this one. :-) */
        initial += to_string(hashCode(initial));

        return Base64::encode(cutie + dikdik(cutie, initial));
    }

    /* Constructs a HTML-ified version of the completion code. */
    string presentableVersionOf(const string& code) {
        return "<div style=\"background-color: #FFD700; font-weight:bold; font-family: monospace\">" + code + "</div>";
    }
}

SummaryReactor::SummaryReactor(StateMachine& machine) {
    string email = promptForEmail();
    string html  = machine.graphicsSystem()->pane->getText();

    /* Locate the text to replace. */
    size_t target = html.find(kCompletionTarget);
    if (target == string::npos) error("Could not find completion target.");

    /* Rebuild the string. */
    istringstream source(html.substr(0, target) +
                         presentableVersionOf(completionCodeFor(machine, email)) +
                         html.substr(target + kCompletionTarget.length()));
    machine.graphicsSystem()->pane->readTextFromFile(source);
}

void SummaryReactor::handleEvent(GEvent) {
    // Do nothing.
}

/* Script integration. */
void SummaryReactor::installHandlers(StateMachineBuilder& builder) {
    builder.addReactor("SummaryReactor", [](StateMachine& machine, const string &) {
        return make_shared<SummaryReactor>(machine);
    });

    /* Install a history plugin to listen to all events. */
    builder.addPlugin("SummaryReactorHistory", make_shared<HistoryPlugin>());
}
