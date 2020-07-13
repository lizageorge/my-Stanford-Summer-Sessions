# The Art of Translation
### July 6, 2020 - lecture 6


- Recap of the day;	
	- ![[Pasted image 188.png]]

- [ ] intro missed
	- existential is flase until proven, universal is true until proven false


### Review;
- the Aristotelian Forms
	- ![[Pasted image 162.png]]


## Combining Quantifiers
- most complex first order logic statements require some combination of "there exits some..." and "every of some kind..." quantifiers.
- [] "Every person loves some other person"
	- --> "every person p loves some other person q that isn't p"
	- --> ![[Pasted image 166.png]]
		- you should always properly define your variables in such statements to avoid false positives (for example, without the Person(p) bit, I could say that this statement is true when a mountain loves another person, a leaf could love another person, etc. so in a world where there is a person that doesn't love another person it could still be true - this is called the "mount everest test")
	- **break down your high-level statement into smaller levels to take advantage of the aristotelean forms**
- [] "There is a person that everyone else loves"
	- --> "there exists a person p such that every other person q (that isn't p) loves q"
	- --> ![[Pasted image 167.png]]
	- again, because of the mount everest test, something like this wouldn't work;
		- ![[Pasted image 165.png]] this implies that in a world where there weren't any people (say it's a world with just mount everest), the antecedent of the implication is false and so the *whole statement is vacously true*. So be very careful when defining *all* your variables in the implication of existential implications.
- **the order of the quantifiers really matters! **
	- [] there could be worlds where everyone loves someone else but no one is universally loved, or vise versa, or worlds where *both* implications are true and everyone loves someone else and someone is unversally loved
- ![[Pasted image 168.png]] --> "For all choice of x, there's some choice of y where P(x, y) is true." (the choice of y can be different for every choice of x, and can also depend on x. like a nested for loop)
- ![[Pasted image 169.png]] --> "There exists an x such that for some choice of y, P(x, y) is true" (there are a much more limited valid choices of x because the inner statement with all y must hold true)

## Set Translation to FOL
- allows us to rigourously prove that our solutions to CS problems are correct
- remember, set operations doesn't exist in FOL, only the predicates that are provided
- [] "the empty set exists", provided the predicates *Set(s)* and *\elemof*
	- --> "there is a set that contains no elements"
	- --> "there is a set such that !(there exists an element x is s)"
	- --> ![[Pasted image 171.png]]
	- OR  "there is a set such that every element x is not in s"
		- --> ![[Pasted image 172.png]]
	- something like this wouldn't work because it has the wrong quantifier;
		- ![[Pasted image 173.png]] in this case, every choice of s is different for every choice of x examined. this statement only says that every choice of x is not an element of some set S, not that there is some set S where every choice of x is not in S.
- [] "two sets are equal iff they contain the same elements"
	- --> "for any two sets s and t, iff they have the same elements, they are equal " (we're using the biconditional statement)
	- --> ![[Pasted image 174.png]]
		- the universal quantifier + the biconditional operator is often used to describe set equality
	- you could have written with the existential quantifier outside the first two antecedents (there exists sets s and t such that ...). 
	- this passes the mt. everest test (whichever way you define s and t) because it ignores s if s is not a set (and same for t). this time, we *want* this statement to be vacously true even in a world with no sets, because it's just saying that set equality is when two sets have the same elements, not that two sets s and t are equal. 
- Quantifiers on sets summary;
	- ![[Pasted image 175.png]]	



## Expressing Uniqueness
- [] "there is only one way to find out", using the predicate WayToFindOut(x)
	- --> "there is some w way to find out something, and nothing else works"
	- --> ![[Pasted image 178.png]]
	- there's a cleaner way, using the contrapositive; ![[Pasted image 179.png]]
		- (contrapositive of not x implies not a way to find out is waytofindout implies x equals w)
- there is a seperate operator in maths to describe uniqueness, but we will not be using it in this class


## Negating Statements
- The negations of all aristotelian forms;
	- ![[Pasted image 180.png]]
	- notice that there are some pairs in this table (the negation of the last statement and the last statement, etc,), so negations of quantified statements can be expressed with quantified statements;
	- ![[Pasted image 181.png]]
	- the whole process; ![[Pasted image 182.png]]
	- []the negation of "everyone loves someone": ![[Pasted image 183.png]]
- you can use deMorgan's laws with implications;	
	- ![[Pasted image 184.png]]
	- this helps us keep --> with universal quantifiers and ^ with existential quantifiers (which is highly encouraged in this class)
	- [] the negations of "there is a cute puppy": ![[Pasted image 185.png]]
	- [] the negation of "there is an empty set"/"there is a set with no elements"
		- ![[Pasted image 186.png]]
- these statements are not negations of each other...
	- ![[Pasted image 187.png]]
	- remember to stick with the rule that for universal statements, you use --> instead of ^. Right now, this fails the mt. everest test. (also, it's preferable over the "or" operator too, even with deMorgan conversions, because that can get confusing)




































