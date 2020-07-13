# Functions
### July 13 - lecture 10


## Defining Functions
- functions in high school are given as some manipulation of one input to produce one output. but in CS, functions can have different outputs for the same inputs, they can have multiple or no intpus, they can have side effects
- so here's our rougher *definition of function; a function f takes in one input and outputs exactly one output object*
	- you can represent with a picture - [] "evolves to" would take a caterpillar and output a butterfly, a pikachu and outputs a raichu 
	- you can represent with a written rule [] f(x) = x^2  
- we're defining functions to be **deterministic** (the same input returns the same outputs), unlike some CS functions that use randomness or other variable factors
- we need to restrict the inputs of the function to avoid invalid calls (like f(pickachu))
	- **domain**; all the possible inputs *x* where f(x) is valid
	- **codomain**; includes all the outputs of f(x) from all the input elements in the domain (doesn't mean that it doesn't include elems that can't be produced from f(x) - that would be the range/image)
		- ![[Pasted image 355.png]]
	- We can represent domains and codomains with this notation:
		- ![[Pasted image 356.png]]

### Formal Definition of a Function
![[Pasted image 357.png]]
- [] `f(n) = n+1, where f: Z -> Z`
- [] `f(n) = ceil(n), where f: R -> Z`

## Combining Functions
- if the codomain of one function is the domain of another (`f:A -> B, g:B->C`)
- ![[Pasted image 360.png]]
- this is denoted at (g* f)(x) -- supposed to be a little circle
	- ![[Pasted image 361.png]]
- []![[Pasted image 358.png]]
- the domain of the codomain of f and g is the domain of f, and the codomain is the codomain of f


## Special Types of Functions

- **injective functions** (one-to-one) = For every possible output in the codomain, there's no more than one input in the domain that produces it
	- ` Aa1 \in A. Aa2. \in A (a1 != a2 -> f(a1) != f(a2) )` = if the inputs are different, the outputs are different
	- ` Aa1 \in A. Aa2. \in A (f(a1) = f(a2) -> a1 = a2 )` = if the outputs are the same the inputs are the same (just contrapositive of above definition)
	- [] ![[Pasted image 362.png]]
	- proofs with injective functions use either of those two FOL definitions
		- [] ![[Pasted image 363.png]]
		- for disproofs, just use the existential negations of the above definitions (`Ea1 \in A. Ea2 \in A. (a1 != a2 /\ f(a1) = f(a2)` or `Ea1 \in A. Ea2 \in A. (f(a1) = f(a2) /\ a1 != a2`)
			- [] ![[Pasted image 365.png]]
		- compositions of injective functions and injectives:
			- [] `Theorem: if a funtion f:A-> B is an injection and g:B->C is an injection, then the function g*f:A-> c is an injection`
			- ![[Pasted image 367.png]]
			- it's best to also quantify A,B,C, they didn't bc of space
- **surjective functions** = For every possible output in the codomain, there's at least one possible input in the domain that produces it
	- `Ab. \in B. Ea. \in A (f(a) = b)`
	- []![[Pasted image 368.png]]
	- proofs with surgective functions, use the FOL definition (arbitrary element in the codomain with a particular matching elem in the domain)
		- [] ![[Pasted image 369.png]]
		- compositions of surjective functions are surjective:
			- `Theorem: if a funtion f:A-> B is surjective and g:B->C is surjective, then the function g*f:A-> c is also surjective`
			- ![[Pasted image 370.png]]

- **bijective functions** = For every possible output in the codomain, there's at exactly one possible input in the domain that produces it
	- are *both injective and surgective*, sometimes called one-to-one correspondence (not to be confused with "one-to-one functions", which was injections)
	- proofs with bijections use the FOL definitions of injections and surjections
		- compositions with bijective functions are bijections  (since both f and g are injective, we know that f* g is injective, same thing for surjectivity. since f* g is injective and surjective, its bijective)
	- bijective functions' domains and codomains have equal cardinality (when defining equal cardinality, we thought of "pairing of" each element in each set...that's a bijective function!)
	- ![[Pasted image 371.png]] the pink arrows represent another bijective function! ...

- **invertible functions** = functions that have valid inverse functions
	- inverse functions: a function `f^-1(x) B->A` is ann inverse function if `Aa \in A. (f^-1(f(a)) = a)` and `Ab \in B. (f^-1(f(b)) = b)`
	- examples on non-invertible functions are the examples of injective and surjective functions above
	- ![[Pasted image 372.png]]
	- [ ] check out proof for this theorem in the course reader
		- ![[Pasted image 373.png]]
- **involutions** = a function f(n) is an involution if `f(f(a)) = a`	
	- [] f(x) = -x; f(x) = x; f(x) = 1 - x


### Some practice~
- `Say f(n) = 2n, f:Z -> E, and g(n) = n/2, g:E -> Z ("E" is all the even integers, E = { n | Ek . n = 2k} )`
	- let's examine `f`
		- f is a function because every elem in Z has exactly one output in E
		- f is injective because every elem in E only has no more than one elem in Z that can produce it (for any arbitrary z1 in Z and z2 in Z, if z1 != z2, then f(z1)  != f(z2). This is because two unequal elem will still be unequal when multiplied by 2.)
		- f is surjective because every elem in E 
		- so, f is a bijection
	- let's examine `g`
		- g is a function because every elem in Z has exactly one output in E
		- g is injective
		- g is surjective
		- so, g is a bijection
	- let's examine `f*g`
		- bc combinations of bijections are bijections, this combination is a bijection
	- let's examine `g*f` (g (f(n)))
		- bc combinations of bijections are bijections, this combination is a bijection

- `Theorem: If f is an involution, f is a bijection`
	- Take any arbitrary elem a in A and b in A where a != b. Assume for the sake of contradiction that f(a) = f(b). If f(a) = f(b), then f(f(a)) = f(f(b)) bc determinisitic function. But bc of involution. that should be the same as a = b. we've reached a contradiction, so f is injective
		- ![[Pasted image 375.png]]
	- (prove subjective...)
	- [ ] extra practice - finish this proof









