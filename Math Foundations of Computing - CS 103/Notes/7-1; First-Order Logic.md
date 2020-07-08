# First-Order Logic
### June 29, 2020 - lecture 4, August 1, 2020 - lecture 5

- **First-Order Logic** deals with objects, not just true/false statements as in propositional logic.
	- augments propositional logic with
		- predicates = given some object, output whether or not some-property applies (true/false)
		- functions = given some object, output another object to work with
		- quantifiers = operators to reason in a world with multiple objects
- [] ![[Pasted image 91.png]]	
	- the *red* are the predicates. Applying a predicate produces a proposition that's either true or false 
	- the *blue* are the objects (includes numbers)
- **Predicates**; when working with Firth Order Logic, you'll be given a list of predicates to work with 
	- [] ![[Pasted image 92.png]]
	- binary predicates can be written in infix notation like ( "<")
	- - **equality** applied to objects, can be a predicate, represented by a regular equal sign, not equals is the regular notequals symbol
		- [] `Tom Marvallo Riddle = Lord Voldermort`, `Lord Voldermort != Harry`
		- for comparing predicates (propositions), you would still use the propositional equality symbol

- **Functions**; which can take in an input object(s) and outputs another object (*not* boolean values)
	- []![[Pasted image 93.png]]
	- includes arithmetic operators ([] +, -, *, etc.*)

- Be careful to keep propositions(true/false values) and objects(tangible things) seperate
	- [] you cannot apply connectives to objects, you cannot use functions on propositions
	- The type-checking table...
		- ![[Pasted image 94.png]]


## Working with Existential and Universal Statements
- *quantified statements* are a kind of proposition.
- Each *quantifier* has two parts
	- the variable being introduced 
	- the statement being quantified
	- ** the variable is scoped to just the statement being quantified
		- []![[Pasted image 122.png]] this works, but just for clarity we'll stick to using different variable names for each statement
- Operator precedence with quantifiers - the operator binds tightly (so watchout for variables being out of scope!). Use parentheses.
	- []![[Pasted image 124.png]]


- **Translating Existential Statements ("there exists x such that...")**
	- use **the existential quantifier** - backwards E
		- []![[Pasted image 95.png]]
		- ![[Pasted image 96.png]]
	- The statements in the form `Ex. some-formula` is a proposition that is true when for some choice of x, the statement `some-formula` is true when that x is plugged in *your particular "world"*
		- [] ![[Pasted image 99.png]] vs. ![[Pasted image 100.png]]
	- The quantifier can be applied to implications (also propositions!), where the implication and antecent are the left and right sides of -->
		- ![[Pasted image 98.png]]
		- [] ![[Pasted image 101.png]] the implication is false bc it's a P:Q T:F structure
		- In an empty world, you can't find an example of x that exhibits the property, so existential statements are automatically false
			- []![[Pasted image 102.png]] 
	
	- **Translating Universal Statements ("for any choice of x, ...")**
		- use the **universal quantifier** - upside down A
			- [] ![[Pasted image 125.png]]
		- A statement of the form `Ax.some-formula` is true iff, for every choice of x, the statement `some-formula` is true when x is plugged into it, as per the conditions in *your particular world*
			- ![[Pasted image 127.png]]
			- ![[Pasted image 128.png]] - all you need to disprove a universal statement in one counterexample
			- ![[Pasted image 129.png]] - this statement (If every x is smiling, every x is wearing a hat) is *true* because it follows the P:Q F:T structure (look at the truth table for p --> q)
			- in an empty world, you cannot find a *counterexample* to a unversale statment, so any statement is vacously true.
				- ![[Pasted image 130.png]]
- if you have multiple quantifiers chained together, unless otherwise specified, the two variables can represent the same value. so if you're writing a statement, keep in mind that that's an edge case 
	- [] `Aa \in A. Ab \in A. (aRb -> bRa)`has to hold true even if a and b represent the same object

## Translating English into First Order Logic
- very useful for manipulating defintions and propositions for proofs
	- for proofs by contradictions, translate into FOL, negate it, and translate back
	- for proofs by contrapositive, translate into FOL, take the contrapositive, and translate back

- **The Aristorlean Forms**
	- "All P's are Q" == `Ax.( P(x) --> Q(x) )`
		- so doesn't turn false for objects you don't care about (things that aren't P)
	- "Some P is Q" == `Ex.( P(x) --> Q(x) )`
		- so doesn't turn true because of objects you don't care about (things that aren't P and Q)
		- ![[Pasted image 134.png]]

- A Bunch of examples! Remember when translating that the value/result(t/f) of the english statement must stay the same.
	- Using the predicates Puppy(x) (returns if x is a puppy) and Cute(x) (returns if x is cute). "all puppies are cute" = `Ap.(Puppy(p) --> Cute(p))` (not `Ap.(Puppy(p) && Cute(p)`, because that would return false if the world includes x where is cute but not a puppy. but a counterexample should only work when the antecedent is true and the consequent is false. )
	- Using the predicates Blobfish(x) (returns if x is a blobfish) and Cute(x) (returns if x is cute). "some blobfish is cute" = `Ex.(Blobfish(x) && Cute(x))` (not `Ex.(Blobfish(x) --> Cute(x))`, because that would return true if even if there are no blobfish in the world at all, since the inside implication would be vacously true?? ) 
	- [ ]![[Pasted image 132.png]]

### Some Proof Practice
- `Theorem: If A and B are sets, then p(A) n p(B) = p(A n B)`
- Step 1: understand what you're assuming and what yo uneed to show
	- ![[Pasted image 135.png]]
- Step 2: list out all the relavant definitions and requirements, and apply them to the variables you have, to get a sense of what you need to prove and what tools you have to work with. 
	- ![[Pasted image 139.png]]
	- ![[Pasted image 137.png]]
	- as you work through (^), you will find more *lemmas* (things you need to prove), and add to your assumptions list
		- ![[Pasted image 140.png]]
- Step 3: make a rough outline. start with just where you're starting and where you need to reach
	- (for the lemma `p(A) n p(B) \subset p(A n B)`) ![[Pasted image 141.png]] and slowly build downwards from the start (or upwards from the end) based off your definitions
- Step 4: translate that rough outline into a proof
	- ![[Pasted image 142.png]]
	- 
	```
	Consider the set S /elem p(A) n p(B). 
	As an elem of the union of the two sets, S must also be an elem of p(A) and of p(B). If S is an element of the powerset of A, which is the set of all subsets of A, S /subset A. 
	Consequently, every elem x /in S must also be an elem of A. The same logic can be applied to the relationship between S and B, so S/subset of B and x must also be an elem of B. 
	Because x /in A and x/in B, x /in A n B (since the intersect is the set of all shared elems between A and B). Because every elem in S is an elem in A n B, s /subset AnB. 
	Finally, because the powerset of AnB contains every subset of AnB, if S / subset AnB, S /in p(AnB). 
	```
	- here's the provided proof:
		- ![[Pasted image 143.png]]
		- I should have clearly stated what I'm proving at the beginning, restate the lemma.
		- Should use "Consider an arbitrary S..." instead of "Consider the set S..."
		- Should have properly introduced and defined all variables (A, B, "any" x)
		- could have used symbols for all descriptions, without english "elem of..."
		- DO NOT INCLUDE "because powerset is a set of all subsets.." etc. Just "If S is an element of the powerset of A, S /subset A. "















