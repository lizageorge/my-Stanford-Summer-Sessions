# Finite Automata
### July 22, 2020 - lecture 12

- computers are really messy and diverse and complex, but fundamentally are very similar and *can* and *should* be generalized and abstracted in **computational models**
	- models allow us to
		- more simply manipulate the models for mathematical logic
		- bc they're abstracted, the models allow us to make sweeping claims about larger groups of computers that share a property
- One such model of an idealized computing machine(notice how much clearer this is than a non-abstracted computer diagram): **Finite Automata**	
	- ![[Pasted image 580.png]] 
	- finite automata have finite resource constraints, just like physicial computers have an upper bound for computational power (as opposed to turing machines)
	- you can think of this like a compiler
	- each automata has a set of **States** (the circles) with **Transitions**(the arrows) connecting them, each transition is specific to a specific input
		- the special **start state** is denoted with the arrow labeled "start"
		- the automota can only be in one state at a time, and starts at the start state
		- the special **accepting state**(s) are denoted with the double circle. If the process *ends* here, then it basically returns true, else (its on a *rejecting state* and ) returns false
		- commas let you set a transition to allow multiple inputs:
			- ![[Pasted image 591.png]]

### What is a Problem?
- [ ] 
### Formal Language Theory 
- **strings** = a finite sequence of *characters* from a specified alphabet
	- an alphabet is represented by symbol $\Sigma$ (can never be empty)
	- [] ![[Pasted image 581.png]]
	- empty string is represented by symbol $\epsilon$
- a **language** is a set of strings over an alphabet $\Sigma$
	- [] ![[Pasted image 582.png]]
	- the empty set {} is a language over *any* alphabet
	- languages can be infinite (like that palindrome example)
	- the set of all possible strings you could create from an alphabet is denoted as $\Sigma *$
		- L is a language over $\Sigma *$ if $L \subseteq \Sigma *$
- Types checking: (if the arrow means 'made up of...')
	- ![[Pasted image 583.png]]
- [ ] Fundamental Question = ![[Pasted image 584.png]]

- when an automata reads a string:
	- ![[Pasted image 585.png]]
	- each char is read one at a time, starting in the start state, and a transition corresponds to that char

- you can read an automata backwards to try and determine what strings will be accepted by it
	- ![[Pasted image 586.png]] if you have a string with at least two ones or two zeroes at the end, it'll be accepted [aka] This automaton accepts a string {0, 1}* iff it ends in 00 or 11
	- the **language of an automaton** is the set of all strings that the automaton will accept
		- ![[Pasted image 587.png]]
		- every automata has a language

### DFAs 
- **Formalizing an Automaton**
	- you want to avoid cases where a string doesn't have any transitions to go out of a state at some char, or if there are more than one valid transition out of a state
		- ![[Pasted image 588.png]]
	- **DFA**s = **Deterministic Finite Automaton**
		- for each state, there must be *exactly one* transition out for each character in the alphabet	 
		- there must be a unique start state
		- there must be zero or more accepting states (basically you just need at least one state, we'll get back to this)
		- [] 
			- ![[Pasted image 590.png]]
		- [] non example: this is *not* a DFA over {0,1}
			- ![[Pasted image 589.png]]
		- when building DFAs, remember that each state should correspond to some information you need to remember, it should act as a 'memento' to use for wherever you go next

- recognizing Languages with DFAs
	- [ ] check middle of lecture
	- [ ] ![[Pasted image 592.png]]
	- [] accept if the input includes any substring of "aa"
		- ![[Pasted image 593.png]]
		- again, we don't care about a b input at the beginning, but at every other state we want to make sure that seeing a b "resets" the search for aa
		- you only want this to accept if two a's were seen in a row. The self-loop transition just makes sure that if the string has chars after the "aa", they won't mess up the return. 
			- the epsilon represents 'all chars'
	- [] accept if the input is a valid c-style multi-line comment! (a represents any char other than * and \)
		- ![[Pasted image 594.png]]
		- q5 represents a sort of *trash state* where you can put any transitions that would automatically ruin an input

### The Regular Languages
- a **regular language** is one that we can solve problems with using DFAs
	- ![[Pasted image 595.png]]
- so it is a classification of problems
- (more on friday)

### NFAs - Nondeterministic Finite Automaton
- a model of computation is deterministic if at every point in the computation, there is only one choice to be made. 
- **existential nondeterminitistic models** have multiple choices from a single point, and will accept an input is there *exists at least one possible path* that will end in an accept state

- [] ![[Pasted image 596.png]]

- if the automaton reaches a point with no transition to go through, that path "dies"
	- [] ![[Pasted image 597.png]]








