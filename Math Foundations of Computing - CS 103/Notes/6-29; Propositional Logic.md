# Propositional Logic
### June 29, 2020 - lecture 4

## Propositions
- **propositions** = statements that can be given a definitive true/false value
	- [] "puppies are cuter than kittens"
	- [] "mt. everest is the tallest peak on earth"
	- *not* commands ([] fly, you fools. fly!)
	- *not* questions ([] can I fly?)
- **propositional logic** = mathematical system for reasoning about propositions, working with *propositional variables* and *propositional connectives*
	- **propositional variables** = a proposition with a value of true/false, represented by any lower-case letter. Think of them as boolean statements
	- **propositional connectives** = operations 
		- *logical negation* = basically !, represented by like a short horizontal bar with a hook on it `-`
		- *logical conjunction* = basically &&, represented by a big carrot (`^`)
			- this is an *inclusive* or - so true if at least one variable is true
			- an *eclusive* conjunction would require that only one variable is true. you can create a formula for this, like so; ![[Pasted image 64.png]]
		- *logical disjunction* = basically ||, represented by a v-like symbol (`v`)


- **truth tables** = represent all the possible combinations of two variables and the outputs when they're entered into a specific formula of propositional connectives
	- [] ![[Pasted image 63.png]]
	
## Mathematical Implications
- There's another propositional connective called material implication, that means that the first variable implies the second variable (`p --> q`). The output represents whether or not the whole *statement* or proposition is true
	- those outputs have been defined as such;
		- ![[Pasted image 66.png]]
		- there are other definitions of implications, but in this class, it's *only* true when p is true and q is false
		- those first two rows kinda represent vacuous truths (from 7/23)
		
- These implications can also represent contrapositives;
	- ![[Pasted image 67.png]]
	- The truth table values for `p --> q` and its contrapositive `(not)q --> (not)q` are the same
- These implications can also represent biconditionals
	- the `<-->` symbol represents an iff relationship
	- ![[Pasted image 70.png]]vs. ![[Pasted image 68.png]]

- one last "connective"-ish pair; is a univeral true value (represented by a `T`), and a universally false value (represented by an upside down T)

- **operator precedence**
	- ![[Pasted image 72.png]] is the order, bottom-to-top ou would parenthesise a string with
	- all operators are right-associative (so they work on just the term directly to the right - this is most clear with the not-operator)
	- just use parenthesis


- all 7 connectives!
	- ![[Pasted image 73.png]]

- **NOTE** - this system is just the classical definitions se ta long time ago that we follow now. There are studies done with different definitions, we just happen to use this most common one


## Proofs
- **Proofs by Contradiction**
	- when we disprove a negation to prove that "p" is true (the other row shows a vacous truth)
	- ![[Pasted image 71.png]]

## Translating English into Logical Statements
- [] from these propositional statements, we can create the statmenet
	- ![[Pasted image 74.png]]
	- "Aang wont' defeat the firelord if he's not in the path of totality" = 
		- `-a --> -b` 
		- ` b --> a`
		- remember, (if P, then Q) means Q--> P, not P--> Q
	- "If Aang will be in the path of totatlity, but plan doesn't go smoothly, aang won't defeat the firelord"
		- ![[Pasted image 76.png]]
		- ![[Pasted image 75.png]]
		- remember, "P, but Q" translates to "P and Q"
	- you have to ignore outside knowledge, and only think  about the info presented!
- English can be very vague, and we have to be careful, methodical, unambigous


## Propositional Equivalence
- ** deMorgan's Laws = factoring out negativity through ands' and or's 
	- ![[Pasted image 78.png]]
	- `!(p && q)` is equivalent to `!p || !q`
	- `!(p || q)` is equivalent to `!p && !q`
	- split and switch (switch and flick!)


- **propositional equivalence** when two formulas have the exact same truth tables, represented by an equal sign with an extra horizontal bar
	- *not* a propositional connective, not the biconditional symbol. equivalence means that two formulas are equal, *regardless of the values of the variables*
- [ ] review these; (connects to proofs by contradictions!)
- ![[Pasted image 79.png]]
- ![[Pasted image 80.png]]
- ![[Pasted image 81.png]]
- ![[Pasted image 82.png]]
- ![[Pasted image 83.png]]
- `p --> q == !(p && !q) == !p || !!q==  !p || q` The equivalence is true because, in both cases, only if q is false is the statement false. 


## Why all this matters
- an example proof by contrapositive;
	- ![[Pasted image 84.png]]
	- ![[Pasted image 85.png]]
	- ![[Pasted image 86.png]]
	- ![[Pasted image 87.png]] - now you have an easier statement to prove!
	- ![[Pasted image 88.png]]
- Propositional logic makes the reasoning of complex propositions and implications easier to understand, especially if you want to prove them
- But it's not quite enough!...first-order logic





	