# Induction
### July 17, 2020 = lecture 10
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



### What not to do - common mistakes
- forgetting the starting base case. with the base case, your inductive hypothesis can be just about anything and ou could be proving nonsense = **principle of explosion**
	- ![[Pasted image 497.png]]
- not covering all cases of k (if k here was 2, this method of splitting k won't work). you have to take into account all edge cases - k has to be an arbitrary integer, and keep it as a concept like that
	- ![[Pasted image 505.png]]




























