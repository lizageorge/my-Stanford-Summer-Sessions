# Induction
### July 17, 20 2020 = lecture 10, 11
- [ ] missed the beginning 

## What is Induction??

## Proof by Induction
- Proof by Induction = using principle of mathematical induction 	to show that some idea is true for all natural numbers
- 3 steps
	- ![[Pasted image 493.png]]
	- 1. Prove that P(0) is true (**basis/base case**)
	- 2. Prove that if P(k) is true (the inductive hypothesis), then P(K+1) is true (=inductive step)
		- the reason this doesn't work on R
		- if you wanted to use this over Z, you would also prove for P(k-1)
	- 3. By induction, P(k) must be true for all natural numbers
### Structuring a Proof by Induction
- [] ![[Pasted image 494.png]]
- when proving by induction, state at the very beginning what your predicate P(n) is defined as, and state you're gonna use induction
- prove the base case (in any way you want to), and then the inductive step(this is basically a universal statement, so use *any arbitrary value* k.)
	- start both sections by saying your going to, and definiing exactly what each means in terms of this particular predicate 
	- right before the induction step, again write out exactly what p(k) means, what is the inductive hypothesis that you're assuming
- ** we often say that the 0th sum or 0th step is zero
- ** as we get more ecxperienced, we'll leave some of these details out
- btw, this is why the largest numerical value you can store in 32 bits is 2^32-1
- ![[Pasted image 495.png]]
	- many inductive proofs can sort of be though of as recursive problem - one base case is the actual base case (0 weighings), one base case is the inductive hypothesis(how to sold P(k)), the recusive case is just saying call P(K) on one minus the current input again and again
	- break the problem down into simpler problems, look for a pattern
- just a big ol' example
	- ![[Pasted image 498.png]], ![[Pasted image 500.png]], (corrolary->) ![[Pasted image 501.png]]

- often proofs by induction aren't actually this long, a lot of the scaffolding is left out
	- P(n) isn't always explicitly defined
		- (shortest version of earlier example: ) ![[Pasted image 526.png]]

## Variations on Induction
### Starting at a non-zero point for the base case
- you can use some value "m", prove that P(m) holds, and then prove that P(m+1) holds, to prove the P holds for all int >=m
### Bigger step sizes
- you don't have to use step sizes of one, as long as you can still get to the end point you were aiming for
- []  ![[Pasted image 503.png]]
	- breaking up the problem; ![[Pasted image 502.png]]
	- the induction machine still works, it just works with three sets of inputs;
		- ![[Pasted image 504.png]]
	- when possible, us a single base case. but if you need more, like here do so
	- make sure you're covering the entire range your theorem focused on



## What not to do - common mistakes
- forgetting the starting base case. with the base case, your inductive hypothesis can be just about anything and ou could be proving nonsense = **principle of explosion**
	- ![[Pasted image 497.png]]
- not covering all cases of k (if k here was 2, this method of splitting k won't work). you have to take into account all edge cases - k has to be an arbitrary integer, and keep it as a concept like that
	- ![[Pasted image 505.png]]


## Data Compression
- **bitstrings** are strings of 1s and 0s 
	- (epsilon is the empty string)
	- there are 2^n strings of length n
- **data compression** = making a long bit of data (a bitstring) much shorter to transfer it easier. usually this is done by exploiting redundancies in the data ([] common words in a text, flat colours in an image)
	- **lossless data compression** = compressing a bit string without any loss of information
		- requires a compression function (C) and a decompression function (D), such that D(C(x)) = x (notice that D must be a left inverse and C must be injective)
- *there is no perfect compression function that can always make any string shorter* = a use of induction~
	- ![[Pasted image 527.png]] 


## Complete Induction
- **principle of complete induction** : ![[Pasted image 528.png]]
	- so the difference between this an regular induction is assuming P(0), P(1), P(3)...P(k) is true instead of just P(k)
		- ![[Pasted image 529.png]]
	- note that k could be 0, so it's easier to think of this as "P(k-k)...P(k-2), P(k-1), P(k)".
- [] ![[Pasted image 531.png]], ![[Pasted image 530.png]]
	- using complete induction allowed us to work with much more general assumption than smth as small and specific as P(k). In this case, if we had done the latter, we would need additional proofs
	- ![[Pasted image 532.png]] - prove on *any* simpler set than k
	- ![[Pasted image 533.png]] - you don't need to know exacly what value you're working with for complete induction

## Building up vs. Building down
- **building up** = build up a smaller object to a greater size. use when the predicate is existentially quantified (proving that there exists an object of k+1 from there exists an object of k)
- **building down** = break a larger object down into smaller pieces. use when the predicate is universally quantified(proving that all objects of k+1 have some property)
	- [] for the coin game of size 6, when n is a multiple of 6, the second player can always win if they play correctly 
- ![[Pasted image 534.png]]



















