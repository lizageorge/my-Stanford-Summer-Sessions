# First-Order Logic
### June 29, 2020 - lecture 4, August 1, 2020 - lecture 5

- **First-Order Logic** deals with objects, not propositions
- ![[Pasted image 89.png]]
- [] ![[Pasted image 91.png]]	
	- the *red* are the predicates. Applying a predicate produces a proposition that's either true or false 
	- the *blue* are the objects (includes numbers)
- when working with Firth Order Logic, you'll be given a list of predicates to work with 
- [] ![[Pasted image 92.png]]
- binary predicates can be written in infix notation like ( "<")


- **equality** applied to objects can be a predicate, represented by a regular equal sign, not equals is the regular notequals symbol
	- [] `Tom Marvallo Riddle = Lord Voldermort`, `Lord Voldermort != Harry`
	- for comparing predicates (propositions), you would still use the propositional equality symbol


- Functions; which can take in an input object(s) and outputs another object (*not* boolean values)
	- []![[Pasted image 93.png]]
	- includes arithmetic operators ([] +, -, *, etc.*)


- Be careful to keep propositions(true/false values) and objects(tangible things) seperate
	- [] you cannot apply connectives to objects, you cannot use functions on propositions
	- The type-checking table...
		- ![[Pasted image 94.png]]


## Working with Existential and Universal Statements
- Translating Existential Statements ("there exists x such that...")
	- use **the existential quantifier**
		- []![[Pasted image 95.png]]
		- ![[Pasted image 96.png]]
	- The statements in the form `E. some-formula` is a proposition that is true when for some choice of x, the statement `some-formula` is true when that x is plugged in *your particular "world"*
		- [] ![[Pasted image 99.png]] vs. ![[Pasted image 100.png]]
	- The quantifier can be applied to implications (also propositions!), where the implication and antecent are the left and right sides of -->
		- ![[Pasted image 98.png]]
		- [] ![[Pasted image 101.png]] the implication is false bc it's a P:Q T:F structure
		- []![[Pasted image 102.png]] - with no objects, it's a default false bc you can't find an example x value (existential statements in an empty world are automatically false, bc you can't find an example of "x" to start it off - universal statements with the empty set can be vacously true)
	