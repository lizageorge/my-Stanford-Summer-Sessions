# Intro to Complexity Theory
### August 12, 2020 - lecture 20

- presburger arithmetic  = any statement that uses this system of arithmetic can be proven using these rules and is decidable. 
	- ![[Pasted image 868.png]]
- but! any TM that does use it needs to move its tape head (2^(2^(c^n))) places...so processes would take longer than the heat death of the universe
- so just because a problem can be solved, doesnt mean it can feasibly solved by a computer
	- ![[Pasted image 869.png]]
	- **R** = problems that can (eventually) be solved by a computer
	- **RE**
	- ![[Pasted image 870.png]]
- new lava diagram
	- (oops)


### Measuring Complexity
- there's a bunch of ways to reason about changes in complexity...
	- ![[Pasted image 871.png]]
- but we'll be going with time
- efficient algorithms...
	- [] searching a finite space for the longest increasing subsequence
		- this is a decidable problem bc we can just search through an entire space and you'll *eventually* find what you're looking for but that's not necessarily feasable
		- ![[Pasted image 872.png]] 
		- vs patience sorting ![[Pasted image 873.png]]
	- ![[Pasted image 874.png]]
- **polynomial time** = runtime is some polynomial to the power of n (O(n^k)) > **exponential time**
- **Cobham-Edmonds Thesis** - A Language L can be decided *efficiently* if there is a TM that solves it in polynomial time
	- we're going to assume this, but it's not actually proven
	- ![[Pasted image 876.png]]
	- but *in general* polynomial runtimes are nice. They also have nice mathematical properties that make them easier to work with
	- -> the **complexity class of P**
		- ![[Pasted image 877.png]]
		- P is analogous to R
	### The complexity class of P
	- all regular languages and CFLs are in P, and more!
	- updated lava diagram
		- ![[Pasted image 879.png]]
	- what *can't* be done in polynomial time?
		- ![[Pasted image 880.png]] there are 2^n subsets, so we can't traverse through all of them, so not polynomial...

- had to leave for outreach right at the start of talking about non-polynomial time..



