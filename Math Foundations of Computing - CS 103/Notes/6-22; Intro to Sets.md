
# Intro to Sets
### June 22, 2020 - first class

The day's summary of the day; 
![[Pasted image 14.png]]

- ==set== = an unordered collection of distinct objects, which may be anything, including other sets
	- notation = curly brces, elements seperatd by commas
	- two sets are equal when they have the same elements (not caring about order)
	- repeated elements in a set are ignored (not a multiset)
	- the symbol of a circle with a line through it denotes an empty set 
		- The Empty Set is a set, is an important edge case
- Set Membership
	- The e-looking symbol denotes that the element before is "an element of" the set after
- ==infinite sets== = some sets can contain an Infinite number of elements
	- [] the set `N` (the natural numbers) is unbounded (and includes 0)
	- [] the set `Z` (the intergers)
	- [] the set `R` (the real numbers ) (includes N and R, and e and pi etc.)
- Describing Complex Sets
	- use ==set-builder notation== 
	- `{ x | some property that x satisfies}`
	- ![[Pasted image.png]]
	- This is also an option
		- ![[Pasted image 1.png]]
	- That property should be precise enough to not be ambigous


- Combining Sets
	- Union = the *combination* of all elements in two sets (symbolized by the u-shaped symbol)
		- ![[Pasted image 2.png]]
	- Intersection = the *overlap* of all elements in two sets (symbolized by the upside-down u symbol)
	- Difference = one set subtracted from another (symbolized by subtraction symbol, or by \) (order matters)
		- ![[Pasted image 3.png]]
	- Symmetric difference = all the elements that one or the other set has, but not both (like a union minus the intersection) (symbolized by deta symbol)
		- ![[Pasted image 4.png]]
	- Venn Diagrams can represent set combinations. They can go up to representing ~7 sets reasonably
		- ![[Pasted image 5.png]]


- Subsets = a set S is called a subset of set T is all elements of S are also elements of T (symbolized by the c on top of line symbol)
	- {c, b} *is a subset of* {a, b, c, d}
	- {c, b} *is a subset of* {c, b}
	- N (natural numbers) ** Z(integers), Z ** R(real numbers)
	- *the empty set* *is a subset of* every set T
		- "all objects of type are also of type Q"  - this statement is an example of smth that is ==vacously true== if there are no objects of type P, so there is no way to disprove it, so it is by definition true
		- []All unicorns are pink, all unicorns are blue - you can't find a non-pink unicorn to disprove the first statement
- Being an element of and Being a subset of are two different things!
	- subsets of multiple elements can't be elements of another set ({1, 2} *not an element of* {2, 3, 4, 5, }), but a subset of a single element can be ( {2} *an element of* {2, 3, 4, 5})
	- a single element cannot be a subset of another set bc it's not a set ({2} *is not an element of* {2, 3, 4, 5})
	- the empty set *is a subset of* any set, but *is not an element of* just any set
	- We say that S *is an element of* T iff among th elements of T, one of them is exactly the object S
	- We say that S *is a subset of* T iff S is a set and every element of S is also an element of T (imagine drawing circles inside T)


- The Power set = the set of all of all subsets of S (symbolixed with the script p symbol)
	- ![[Pasted image 8.png]]
	- The power set of the empty set is just a set containing the empty set (*not* just the empty set, and *not* everything that the empty set is a subset of)


- ==cardinality== = the number of elements inside a set. Denoted by using | on either side of a set
	- ![[Pasted image 9.png]]
	- comparing cardinalities - if you *can* pair up every element of one set with another without leaving an element of the second unpaired, they have the same cardinality
	- the cardinality of the natural numbers is defined as aleph-naught (looks like an n with a 0). N can be "paired up" with any other infinite set, so ==ever infinite set has the cardinality of aleph-naught==
		- ![[Pasted image 10.png]]
	- The cardinality of a power set is always greater than the cardinality of the original set, if the original is finite
	- for the power sets of infinite sets, we have to see if every single subset can be matched with an element
		- The Diagonalization Proof - you can prove that there's a set that won't be matched matched with an element by taking the "diagonal" of every element-set pair and flipping it.
			- ![[Pasted image 11.png]]
			- ![[Pasted image 12.png]]  
			- ![[Pasted image 13.png]]
	- ==Cantour's theorem== = the cardinality of *any set* is smaller than the cardinality of the power set of that set

- ** We can translate an existential statement into set notation. [] "There is at least one element in set A" --> `A /noteq /emptyset` or `|A| /noteq 0`


- thus we can prove that there's more problems than there are problems

## Why Discrete Maths?
- (from 7/1)
- set theory can let us pin down abstract concepts
- a broad approach to apply to problem solving - if you can *quantify* the problem, we can find a more efficient solution
