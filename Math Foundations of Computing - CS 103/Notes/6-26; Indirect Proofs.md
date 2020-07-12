# Indirect Proofs
### June 26, 2020 - lecture 3

- summary of the day:
	- ![[Pasted image 61.png]]

- **logical implication** = statements in the form *If P is true, then Q is true* ([] 
if n is even, then n^2 is even)
	- the "if p is true" part is the antecedent, "then q is true" is the consequent
	- both parts need to be strictly defined
	- implications are *directional* - the proof direction doesn't go both ways ("If there's a rainbow, it has rained somewhere" /= "If it has rained, there has to be a rainbow") and doesn't imply cuasality () "rainbows cause rain")
	- `For any x, if P(x) is true, then Q(x) is also true`
	- ![[Pasted image 43.png]] Q(x) can be true elsewhere, P(x) can be untrue
	
- **propositions** = logical statements that is either true of false
	- statements we've proved can be true propositions
	- an example of a false proposition is {} = R
- The **negation** of a proposition X is false whenever X is true, and is true whever X is false
	- [] the negation of "it's snowing outside" is "it's not snowing outside" (not "it's sunny outside", not "it's summer in the bay area" - the negation has to be the *exact opposite*)
	- the negation of a *universal statement* "Every P is Q" is the *existential statement* "There is a P that is not a Q" - you're finding a counterexample
		- [] the negation of "all of my friends are taller than me" is "at least one of my friends is taller than me"
		- this works the other way too - "Some friends are shorter than me" to "All of my friends are taller than me"
		- the negation pair to a universal statement has to be an existential statement, and vise versa
	- the negation of an implication
		- [] the negation of "If x is a puppy, then I love x" is not "If x is a puppy, then I don't love x" - we already assume that Q isn't true when P isn't true. Instead, it would be "There is a puppy I don't love"
			- ![[Pasted image 44.png]]
		- The negation of implication is not another implication!	
			- ![[Pasted image 45.png]]
		- "For any x, is P(x) is true, then Q(x) is true" --> "There is an x where P(x) is true and Q(x) is false"
	- Summary of negations
		- ![[Pasted image 46.png]]
		- [] "there does not exist a cs class that does not have something to learn from cs103" --> "there does exists a cs class that does not have something to learn from cs103"
		- [] "everyone should take cs103" --> "there exists a person that shouldn't take cs103"



- (more on set theory) **set complement** = everything not in set C but is in set P (symbolized by P^C)
	- ![[Pasted image 48.png]]
	- equivalent to set difference, but one set is a  subset of another
	- this is how you would refer to something that "is not in set C" - you always need an "outside set" for context
	- ![[Pasted image 49.png]] right now, *P is a subset of Q, and !Q is a subset of !P*



- **Proof by Constrapositive**
	- the **contrapositive** of an implication X *says the same information*, but reverses the precedent and antecedent
		- ![[Pasted image 51.png]]
		- [] The contrapositive of "If x is a puppy, then I love x" is "If x is not a puppy, I don't love x"
		- [] The contrapositive of "If I store my cat food inside, then racoons won't get to it" is "If racoons got to my food, then I didn't store it inside"
	- to prove *If P is true then Q is true*, I would prove *If Q is false, then P is false* if it is easier
	- [] ![[Pasted image 54.png]]
		- it's a good idea/curtesy to state that you're proving by contrapositive, and include the contrapositive to check yourself
		- after that, you just have a basic direct proof (start with a arbitrary odd, use the definition, etc.)


- **Biconditionals** = sometimes two different implications (each going the other way) that imply each other. We can make a new statement with *if and only if* from them.	
	- []"For any integer n, if n is even, then n^2 is even", "For any integer n, if n^2 is even, then n is even" --> "For any integer n, n is even if and only if n^2 is even"
	- To prove a biconditional in the form *P is true iff Q is true* you need to prove that (first) if P is true, then Q is true, and (second) if Q is true then P is true. You can use any proof technique for those (prove the implication both wars)
	- ![[Pasted image 57.png]]
	- [] Cyclic /\ Reflexive <-> Equivalence Relation Proof


- **Proof by Condradiction** = we can prove that a statement is true by proving that it *cannot be false*
	- Steps:
		- Make the assumption that *P is false*/with a negation of P
		- Use logical reasoning to reach a conclusion that is clearly, by definition, false/impossible or something that contradicts the original negation
		- If nothing else (in step 2) is faulty, then the first assumption must be false, so P must be true
		- [] ![[Pasted image 58.png]]
			- clearly state that this is a proof by contradiction, and state what that negation is 
			- when you reach the impossible statement, state so, and conclude that thus the original negation is impossible
		- [] (a previous proof, done a different way) ![[Pasted image 59.png]]
	- A reference, how to find ther right contradictions/negations:
		- ![[Pasted image 60.png]]



























	