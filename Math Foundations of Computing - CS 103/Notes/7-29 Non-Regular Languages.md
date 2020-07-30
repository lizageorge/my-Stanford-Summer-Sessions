# Non-Regular Languages
### July 29, 2020 - lecture 15
- just like regular languages correspond to problems that can be solved with finite memory, non-regular languages correspond to problems that can only be solved with 'infinite' memory (cannot be solved by real-world computers)

## Proving a language is non-regular
- to prove that a non-regular language is non-regular, you have to prove that *no possible* DFA works
	- (if you can't make a DFA for smth, you can't make a regex or NFA for it)
	- [] think of the language `{a^n b^n | n \in N}` 
	- the dfa would have to look like this...
		- ![[Pasted image 682.png]]
		- even though df states should be deterministic
	- oe tha dfa would somehow have to do this...
		- ![[Pasted image 683.png]]
	- so there's no way to have a DFA where two strings have the same state!
		- ![[Pasted image 684.png]] 
- **distinguishability** = in a language L over $\Sigma$, two strings *x* and *y* in $\Sigma*$ are distinguishable if there exists a third string *w* in $\Sigma*$ such that is *w* is appended to each of them, exactly *one* of *xw* and *yw* are in the language L.
	- ![[Pasted image 686.png]]
	- [] in the previous example, a^2 is distinguishable relative to L to a^4, if you think abt appending b^4 to them. 
- back to the previous example;
	- ![[Pasted image 687.png]]
	- ![[Pasted image 688.png]]
	- *formal proof*;
		- ![[Pasted image 689.png]]
		- (don't use this as a template, there are simpler techniques v)
- another example; []![[Pasted image 690.png]]
	- ![[Pasted image 691.png]]
	- ![[Pasted image 692.png]] (still not the best template!)
- there's a pattern in these two proofs so far..
	- ![[Pasted image 693.png]]
	- we can generalize this idea of k being very large, but if there are always distinguishable strings, we can invalidate the hypothetical DFA with a set of k+1 strings!
	
### The Myhill-Nerode Theorem
- ![[Pasted image 695.png]]
- ==so all you have to do to prove a language L is non-regular is find a set of strings that satisfies those requirements (infinite and has all distinguishable-to-L pairs)!==
	- the intuition for the set you pick...
		- ![[Pasted image 699.png]]
- (proof of this theorem: ![[Pasted image 696.png]] ...template to use! ->)

- [] prove language `E` is not regular using myhill-nerode..
	- we're going to pick the set `S = {a^n | n \in N}`
		- the set we pick doesn't necessarily have to be a subset of the original language, just of the language*
	- ![[Pasted image 697.png]]
- [] prove the language `EQ` is not regular using myhill-nerode...
	- ![[Pasted image 698.png]]
























