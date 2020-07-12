# Binary Relations
### August 8 - 10, 2020 - lecture 7-8

- recap of the day (lecture 7);
	- ![[Pasted image 291.png]]

## Binary Relations
- we often want to formalize and model relationships in CS. Any relations that focus on the connection between *two* objects are binary relations
- []![[Pasted image 266.png]]
- a kind of metaphor for a binary relation is a wise mountain sage. imagine a superwise sage on top of a mountain with a binary relation in her head, who will be presented two objects. if that sage smiles, the two objects satisfies her relations. if she doesn't, then they don't.
	- for any arbitrary relationship R, and two arbitrary objects a and b, 
		- ![[Pasted image 269.png]]
	- [] ![[Pasted image 267.png]] ![[Pasted image 268.png]]
- (official definition) a **binary relation over set A is a predicate R that can be applied to ordered pairs of elements drawn from set A. If the binary relation holds for the pair (a, b), then `aRb`**
	- *order matters!* (there are some relations where order doesn't matter, but by default the order in which you draw the elements matters)
	- the two elements need to have some matching relation for that relation (so you can't use \subsetof on two integers, you can't use < on two sets). So the *relation is defined by the set you're drawing elements from.*
- **  note - relation definitions, by convention, always use "If" instead of "Iff"
	- ![[Pasted image 344.png]]
- *visual representations*
	- we can draw graphs where an arrow pointing from a to b can represent `aRb`
	- [] to represent `a | b` (a cleanly divides b) on the set A = {1, 2, 3, 4}
		- ![[Pasted image 270.png]]


- binary relations can capture certain structures that appear in CS. Two examples of structures are partitions and prerequisites


## Partitions
- you can *partition* (split up) a group/set of data by certain properties so you can deal with each set separately.
	- ![[Pasted image 271.png]]
	- officially, a partition of a set is a non-empty subset. every element is in exactly one subset, and every cluster is disjoint (their intersections are the empty set)
	- aka *clustering*, *cluster*
- you can have a binary relation that checks to see if two elements are in the same *cluster*
	- we can have a few rules for this. is `R` is the relation representing "is in the same cluster as"
		- `aRa` (reflexivity)  ,   `aRb -> bRa`  (symmetry),  `aRb ^ bRc -> aRc` (transitivity)
	- we can translate this intp FOL; ![[Pasted image 274.png]]
- there's one additional property - the partition relation is *cyclic*
	- ![[Pasted image 348.png]]
	- ![[Pasted image 349.png]]

### Equivalence Relations
- type of binary relation that follows all three of the following properties
- - ** some rules/properties for binary relations defined;
	- **Reflexivity** = when a relation *always* holds from any element to itslef 
		- [] `x = x for any x`, `A \subset A for some set A`
		- [] ![[Pasted image 275.png]]
		- `R` is relfexive if `Aa \in A. aRa` ("Every element is related to itself ")
	-	**Symmetry** = when a relation holds true even when the relative order of the objects is switchese
		-	[] `if x = y, then y = x` 
		-	![[Pasted image 277.png]] (because a has no relations, the implication is vacously true)
		-	`R` is symmetric if `Aa \in A. Ab \in A. (aRb -> bRa)` ("If a is related to b, then b is related to a")
	-	**Transitivity** = when a relation can be chained across multiple elements (the chain can be more than two relations)
		-	[]`is x = y and y = z, then x = z`
		-	[]![[Pasted image 278.png]]
		-	`R` is transitive if `Aa \in A. Ab \in A. Ac \in A.(aRb ^ bRc -> aRc)` ("If a relates to b and b relates to c, then a relates to c")
		-	** ![[Pasted image 279.png]] this relation is *not* transitive because `a` and `c` could represent the purple smiley, but there's no self-relation shown
- these equivlence relations are what allow you to define partitions. 
- **Equivalence classes**
	- given an equivalence relation `R` and an object `x` , the *equivalence class of x* is the set of all elements of x's set `A` with which the relation `R` holds with x
	- `[x]_R = { y \in A \ xRy} `
		- [] ![[Pasted image 281.png]]
	- **The Fundamental Theorem of Equivalence Relations** = Let R be an equivalence relation over a set A. Then every element a\inA belongs to exactly one equivalence class of R 
		- ([] you can't have an object that has multiple shapes and is thus in multiple ECs)
		- this captures the rules we need for partitions 
- Equivalence Relations in IRL
	- any sort of hash-table/map data structure has to be able to keep keys distinct. They do this using a rigourous definition of equality that follows rule for equivalence relations;
	- [] ![[Pasted image 284.png]]

## Prerequisites 
- a structure (without circular dependencies) where an element has to come *after another* object. If this is represented by the relation `R`, then `aRb` means that "a must happen before b" 
	- [] ![[Pasted image 285.png]]
- we can have a few rules about this new relation `R`
	- irreflexivity, transitivity, asymterry
	- ![[Pasted image 287.png]]
	- **Irreflexivity** = no element is related to itself
		- [ ] g
		- `Aa \in A. !aRa`
		- ** reflexivity and irreflexivity are not negations of each other! (they are both universally quantified)
	- **Asymmetry** = when the relative order of two objects in a relation can never be reversed
		- [] `if x < y, y !< x`
		- [] ![[Pasted image 289.png]]
		- `Aa \in A. Ab \in B. (aRb -> !bRa`
		- 

### Strict Orders
- type of binary relation that has *irreflexivity, transitivity, asymterry*
- [] `<, >, "x can run faster than y"`
- represent prerequisite structures, and can also model dependencies, rankings, etc.
- Strict Orders IRL;
	- many sdl containers rely on strict orders to create ordered lists
	- functions like sort() and operators like < follow strict order relations (c++ requires that if you overload either)


## Proofs with Binary Relations

### Proofs with Equivalence Relations
- prove that a relation R is an equivalence relation over the set A
- you have to prove each property independently, using the FOL definition
- [] `a~b over the integers if a + b is even~`, `~` is an equivalence relation
	- ![[Pasted image 345.png]]
	- ![[Pasted image 346.png]]
	- ![[Pasted image 347.png]]
	- ** note that none of these proofs include FOL! FOL is used for intuition help and defining, but proofs are supposed to be readable and easily understood. Keep you proofs in English!

- [] `Theorem: A relation R over set A is an equivalence relation iff it is reflexive and cyclic`
	- to prove biconditional statements, we have to prove the implication both ways
	- [ ] backlink?
	- ![[Pasted image 350.png]]
	- ![[Pasted image 351.png]]

- [] `Say the inverse relation (R^-1) over set A means that x(R^-1)y if yRx. Prove or disporve: if R is an equivalence relation over A, then (R^-1) is an equivalence relation over A`
	- when given a prove/disproof problem, just try proving and disproving both
	- when given a new definitino like this, look at some concrete examples of it (`([] > --> <, = --> =)`)
	- ![[Pasted image 352.png]]
	- [ ] go over thiissss
- For more details on how exactly to write proofs of equivalence, check out the [Guide to Proofs on Discreet Structures](http://web.stanford.edu/class/archive/cs/cs103/cs103.1208/handouts/Guide%20to%20Proofs%20on%20Discrete%20Structures.pdf)


