# Guide To Negations 
### July 7, from the "Guide to Negations" handout

- the basic negation of any statement is just putting the `~` symbol in front of it

- summary templates;
- ![[Pasted image 263.png]]
- 
## Negating Propositional Logic
- you should simplify most negations (aka "push" the negations in deeper until they apply directly to the propositions)
	- use deMorgans Laws for propositional statements (switch and flick!)
		- ![[Pasted image 228.png]]
		- (new notation - this reads as "replace what's above the line with what's below the line")
	- []![[Pasted image 229.png]] to ![[Pasted image 230.png]]
- you can confirm that a negation is done correctly either 
	- intuitively
	- through truth tables (every row has to have opposite values)
	- or using a biconditional (basically, if B is a negation of A, then every time A is true B should be false and vise versa. This is the opposite of a biconditional, so if you punch in the biconditional `A <-> B` it should output all false)
		- ![[Pasted image 231.png]]

### Negating an Implication
- you have to prove that the direct `p -> q` relationship is false, aka that (`p -> !q` doesn't cover the opposites fo vacous truths for when p is false so) `p ^ !q`
	- ![[Pasted image 232.png]]
	- ![[Pasted image 235.png]], ![[Pasted image 233.png]], ![[Pasted image 234.png]]
- don't forget to apply *operator precedence* 
	- the implication operator is at a higher level than things like ands/or/nots
		- ![[Pasted image 236.png]]
	- the implication operator is right-associative
		- ![[Pasted image 237.png]]
		- `p -> q -> r` = `p -> (q -> r)` !=`(p -> q) -> r`
- the relation between implication and and for negations works the other way too
	- ![[Pasted image 240.png]] (this rule is more useful than demorgan's when working with FOL)

-  Negating Biconditionals
	- two rules; ![[Pasted image 242.png]]. Choose the side that's easier to negate
	- [] negating ![[Pasted image 243.png]] to ![[Pasted image 245.png]]

## Negating FOL
- ![[Pasted image 258.png]]
	- if you have multiple quantifiers next to each other, imagine that the second starts a new stack/parenthesized group. pushing in the negation will switch both
- after you push the negation through the quantifier (![[Pasted image 259.png]], ![[Pasted image 260.png]]), apply to any following implications like normal (and then any more quantifiers after that, over and over again)
- it's preferable tot use the second rule when negating ANDs, the one that turns it into an implication
- []![[Pasted image 261.png]]
- to check the negations of FOL, we can't use truth tables, we just have to make some manual checks
	- A. is usually paired with ->, and E. is usually paired with /\
	- just check that the english translations make sense intuitively
- anytime you're working with sets, just treat the "{operator} {setName}" bit like a proposition (so `x \in A` is equivalent to `A(x), returns if x is an element of A`). But when it's attached to the quantifier...
	- ![[Pasted image 262.png]]

## The Steps to Negations
- start with negating your whole statement by parenthesizing and using `~`
- then try and "push in" that negation as much as possible by applying templates
- ** sometimes, the exact same formula can result in multiple valid negations. You just have to pick the one that's most readable
	- [] `~(p ^ q ^ r` can equal any of these, but the blue are most readable; ![[Pasted image 241.png]]