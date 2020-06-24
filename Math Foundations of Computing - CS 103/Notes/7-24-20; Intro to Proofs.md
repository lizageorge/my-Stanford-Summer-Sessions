# Intro to Proofs
### June 22, 2020 - first class

![[Pasted image 37.png]]

- mathematical proofs = an argument that proves why a mathermatical statement (the *theorem*) is true, following mathematical rules 
- modern proofs = should be *easy* to understand and follow the explanation 
	- So you don't have to unecessarily reduce the amount of english used. Use full sentences with punctuation.
- proofs should be specific enough to take into account edge cases

- we're going to be throwing out everything we know in maths (except for monday's lectures and basic integer arithmetic), and try and prove everything else!
- **An integer is even** *if there is an integer k such that n=2k*
	- so 0 is even
- **An integer is odd** *if there is an integer k such that n=2k+1*
	- so 0 is odd

### Direct Proofs
- **Theorem: If n is even, then n^2 is even**
	`Let n be an even integer.` - if we'r eusing a *if P, then Q* structured-theorem, we should start by assuming P and work down to prove Q
	`Since n is even, there must be k such that n = 2k.` - it's common to call back to mathematical definitions to be rigourous and specific
	`So n^2 = (2k)^2 = 4k^2 = 2(2k^2).` - it's common to use variables (like k here) to simplify the work
	`So there is an integer m (namely 2k^2 where n^ = 2m.` - again, you must rigourously follow mathematical definitions
	`Therefore n^2 is even.[ ]` (there's normally a square symbol to represent the end of a proof)
- **Theorem: For any integers m and n, if m and n are odd, then m + n is even**
	- you can start your intuition with a visual interpretation, but that doesn't prove everything (for example, this doens't unambigiously prove the theorem for negative integers)
		- ![[Pasted image 20.png]]
	- when proving anything that is *always true*, you have to show that no matter the value of that starting value(x) the proof works. Start by choosing x *arbitrarily* ("Consider any x (of some set)", "Pick an odd integer x") and then denostrate the property holds true for that choice of x
	`Consider any arbitrary integers m and n, where m and n are even.`
	`Since m is odd, we know that there is an integer k such that m=2k+1. (1)` - notice that numbering equations can make the proof easier to understand
	`Similarily, there must be some integer r such that n = 2r +1. (2)` - don't re-use vars, bc that would assume that the ka value is equal in both
	`By adding equations (1) and (2) we learn that ` 
			`m + n = 2k + 1 + 2r + 1
						 = 2k + 2r + 2
						 = 2 (k + r + 1`
	`Equation (3) tells us that there is an integer s (namely k + r + 1) such that m + n = 2s. Therefore m+n is even. [ ]`
	
	
### Proofs By Exhaution/Proofs by Cases
- **Theorem: the product of any two consecutive integers is even.**
	`Pick any two consecutive integers n and n+1. We can prove that (n)(n+1) is even.` - once again, to prove an "any" theorem, we stat by picking arbitrary values
	`Let's consider two cases:` - proofs by cases shows that the theorem is true regardless of the value picked. You need some sort of justification that you've covered all possible cases (here, we know that all integers are either even or odd), and in more complex problems, include that justification.
		`Case 1: n is even. This means that there must be a k such that n = 2k. Threfore, we learn that
			n(n+1) = 2k(n+1)
						 = 2(k(n+1)).
			Therefore, there is an integer m (nameley, k(n+1)) such that n(n+1) = 2m, therefore n(n+1) is even. `
		`Case 2: n is odd. So there is an integer k where n=2k+1. This tells us n+1 = 2k + 2. We then see that 
			n(n+1) = n(2k+2)
						 = 2(n(k+1))
			Therefore, there is an integer m (nameley, n(k+1) such that n(n+1) = 2m, therefore n(n+1) is even.` - you usually have to re-derive proofs in separate cases, but you can use phrases like "By the same logic..." as long as you're careful.
		`Either way, we find that n(n+1) is even, which is what we needed to show. []`
		
	- * * be sure to format your proof to be easy to read too! Use line breaks, indenting, break up the proofs as needed, etc.
		- ![[Pasted image 21.png]] vs. ![[Pasted image 22.png]]
	
	- some extra exercises to prove!
	- ![[Pasted image 23.png]] we'll be using these statements for further proofs without having to reprove them. 

### Universal and Existential Statements
- **universal statements** are in the form `For all x, [some property] holds for x`
- **existential statements** are in the form `There is an x where [some property] holds for x.`
- ![[Pasted image 24.png]]

- **Theorem: for any odd integer n, there exists integers r and 2 where r^2 - s^2 = n**
	- Visual interpretation:![[Pasted image 25.png]]
	- ![[Pasted image 26.png]]


### Working with sets
![[Pasted image 36.png]]
- Any time you're working with *subsets*...
	-   ![[Pasted image 29.png]]
	- **Theorem: For any sets A, B, and C, is A [is a subset of] B, and B [is a subset of] C, then A [is a subset of] C.**
		- use visual interpretations: ![[Pasted image 27.png]]
		`Let A, B, and C be arbitrary sets where A [is a subset of] B and B [is a subset of] C. We need to prove that A [is a subset of] C. To do so, consider any x [is an element of] A. We will prove that x [is an element of] C` - again, for universal statements, start with arbitrarily-selevted values. Call back to mathematical definitions. Clearly state what exactly you need to prove. We're also breaking down those definitions into smaller elements to proe, and chain that result to keep on proving ( this is called a **lemma**). 
		` `	![[Pasted image 28.png]]
- *Working with Set equality*
	- prove that A is a subset of B and B is a subset of A to prove that A = B
	- **Theorem: If A and B are sets and A the union of A and B is a subset of the intersect of A and B, then A is equal to B**![[Pasted image 30.png]]	 
		- again, because this is a universal statement, we start with arbitrary sets
		- here we can use the *lemma* that A is a subset of T
			- ![[Pasted image 31.png]]
		- [ ] the final proof screenshot. 
	- ![[Pasted image 32.png]]
- *Working with Power Sets*
	- **Theorem: For any sets A and B, is A instersect B = A, then A is an element of the powerset of B**
		- ![[Pasted image 33.png]]
	- ![[Pasted image 34.png]]
	- To prove ![[Pasted image 35.png]]

	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		