# Turing Machines
### August 3, 9, 10 2020 - lecture 17-18

### Summary 
- terminology of TMs
	- ![[Pasted image 752.png]]
	- (so if something doesn't accept, it didn't necessarily reject it could have looped)
	- (if a string is in the language L, a TM over L should always accept it. If it isn't, then it could loop or reject)
- what the language of a TM means;
	- ![[Pasted image 751.png]]

### what languages are we looking at now? (more at the end)
- finite automata can accet exactly the regular languages
- how do we solve context-free languages? do we need a finite number of states as long as we can use unbounded memory?
### A bit of history
- 1900, Hilbert wanted to solve his 23 unsolved problems with automated mathematics. But then Alan Turing came along and came up with the turing machine and proved some problems unsolvable


## The Turing Machine
- there's an equivalent to 'scratch space' to keep track of information for the computation as we go. think of this infinite amount of scratch space/memory as a reel of film tape
	- ![[Pasted image 732.png]]
	- MISSED A BUNCH
- The input string can be inserted onto this tape. The *tape head* will look at one char at a time
	- ![[Pasted image 733.png]]
	- if it starts on the empty string, the entire tape must be empty and the position on the tape must be arbitrary 
- each transition is of the form `read -> write, directions(L/R`
	- ![[Pasted image 734.png]]
- the machine doesn't necessarily stop reading once it reaches the end of the string, but only when we reach a **rejecting state**. still, we can be confident that if we read a blank, we've gone off the end of the input
- the machine stops immediately once it reaches an accepting or rejecting string
- the key definitions!
	- ![[Pasted image 735.png]]
	- ![[Pasted image 736.png]]
- **determinism**
	- for every combination of a non-accepting/rejecting state and a tape symbol there must be exactly one transition defined
		- any missing transitions implicitly go straight to a rejecting state 
		- ![[Pasted image 737.png]] = ![[Pasted image 738.png]]
- the language of a turing machine is the set of strings that the TM accepts (the original inputs, not the mangled results on the tape)

### Designing Turing Machines
- MISSED A BUNCH
- [] a language with (0)^n(1)^n for n \in N (non-regular)
	- ![[Pasted image 741.png]] (the missing transitions implicitly go to a reject state)
- [] a language with the same number of 0s and 1s (non-regular, also context-free) (straightforward)
	- a common problem - if you encounter a blank in the middle of string that you inserted earlier, how do you know it isn't one of the infinately many blanks outside the string?
		- one solution is to replace the blanks you insert with some other arbitrary character (say 'x') from the *tape alphabet, not the input alphabet!* (it is technically possible to have an infinite input alphabet, but there are ways to still model the tape alphabet characters differently)
	- ![[Pasted image 743.png]]
	- sometimes a TM might need to remember extra infor that can't be put on the tap, in which case you can add a (finite number of ) extra state  

- - [] a language with the same number of 0s and 1s (non-regular, also context-free) (crazy big brain)
	- sort the string first! and then use the old algorithm for checking (0)^n(1)^n 
		- remember, a string is sorted if it matches 0\*1\* 
		- repeatedly find copies of 10 and replace them with 01
		- ![[Pasted image 744.png]]
	- that last dotted line circle is acting as a placeholder for another TM ( = **subroutine**)
		- TM subroutines allows the equivalent of function decomposition!

### Deciders 
- a kind of turing Machine that always gives an accept/reject answer instead of possibly looping on certain inputs. So accepting <-> !rejecting now. 
	- some lanugages are *decidable* if there is a decider TM that accepts it. (If a string w $\notin$ a decider M, M rejected w)
- the class **R** is the set of all decidable languages
### Recognizers
- basically the TMs we've been working with so far
- ![[Pasted image 851.png]]
### Verifiers
- (more in next lecture)
- ![[Pasted image 843.png]]
- ![[Pasted image 845.png]]


## R and RE Languages
- RE = set of all recognizable languages, R = all decidable languages
- Every decider is a TM, so R $\subseteq$ RE
- (later on...ATM in R but not in RE, so R is a strict subset of RE!)
- To prove that a language is undecidable (not in R), prove that a decider for it cannot exist/a hypothetical decider would be a self-defeating object. Can you writ e a self-referencial program in the decider that contradicts what it was supposed to do?


## Idealized Computing Machines
- we can imagine an idealized computer simulating a TM
	- ![[Pasted image 745.png]]
- you can really do a lot of stuff that we do on the computer in a TM (split up the tape into multiple locations, represent arrays and linked structures, etc.)
- except for randomness and user input, *TMs can do anything a computer can do* (even if they're insanely slow and inneficient)
### Effective Computation
- an **Effective Method of computation** solves a problem with a set of steps, in a finite number of states
- the *Church-Turing Thesis* is a *claim* that every effective method of computation is either equivalent to or weaker than a Turing Machine!
	- ![[Pasted image 747.png]]
	- so TMs can be approximated as computers


### What kind of problems can a computer solve 
#### 'solve'?
- you can actually claim that a solution doesn't necessarily work for all possible inputs, it just works for the ones we know (Collatz conjecture on Hailstone Sequence TM)
- tms can technically go endlessly
	- ![[Pasted image 749.png]]
#### 'computer?'
- we're using a TM as 'compuer' bc og Church-Turing Thesis
- we can try and model TMs with code using some hypothetical methods;
	- ![[Pasted image 791.png]]
	- [] ![[Pasted image 792.png]]
	- if the TM is a decider, the function would return something corresponding to that (for example, for the a^nb^n language example the code would return a bool)

#### 'problem'?
- a **decision problem** should always have a yes/no answer ('is it actually possible to do this?' instead of 'what's the best way to solve this?')
	- ![[Pasted image 785.png]]
	- how do we represent inputs?
		- **Object Encoding** = we can represent any finite object *Obj* into a string of bits *\<Obj\>* . Encoding should be an injective function, where different objects yield different codes
		- we can abstract away object encodings and reason with a TM by assuming that any object or group of objects has an encoding
- impossible problems (more next lecture)
	- [] (there is no decider for ATM) - there is no algorithm that can determine if a progam will accept a particular input, you just have to run it
	- for problems on *undecidable* languages, you can't simulate them and it's impossible to compute with them or create a decider for it because of the difference between false and not-true/looping 

### Emergent Properties of TMs 
- an **emergent propery** = of a system is some property that arises after putting together a bunch of small, property-less elements 
	- [] universality, self-referentiality
	- with a TM with both of these properties, you can prove whether or not it's in R by calling it with itself
#### Universality - Universal TMs
- universality = some computational device that can solve all problems, by taking in other TMs along with an input
	- can we build a reprogramable turing machine? A simulator TM that would take as input an encoding of another TM with an input string to return whether or not the other TM accepts it? (something like our own actual computers)
		- ![[Pasted image 786.png]]
		- ![[Pasted image 788.png]]
		- [] assuming there's a way to encode a TM, 
			- ![[Pasted image 789.png]] the UTM will traverse the input string, but at each character it goes to the inputted TM to find out what to do with that char
		- this concept can theorize our modern computers, which take code as input and can even run virtual machines as input
	- The Language of the Universal TM is called the acceptance language
		- ![[Pasted image 790.png]]
#### Self-referentiality
- think of a Quine, or a program that prints out its own source code as a string. we can claim that any program can write itself as a string; Kleene's Second Recursive Theorem = it is possible to write TMs that compute on themselves + church-turing therem
	- = any computing machine has a way to self-reference! (Any program can be augmented with a call to its own source code)
- **self-defeating object** = an object whose own essential property is that it doesn't exist
	- [] the largest integer
	- you can prove if an object is self-defeating; 
		- ![[Pasted image 793.png]]
		- becareful not to prove smth is not self-defeating by assuming first that it exists and not searching thoroughly for contradictions
	- [] **Theorem: the decider for the ATM is self-defeating**
		- if we had a decider for the ATM, we could know definitively whether any other TM will accept or reject a string instead of just if it's looping
		- ![[Pasted image 794.png]]
		- imagine having to plug this program into a self-reference machine
			- ![[Pasted image 795.png]]
		- ![[Pasted image 796.png]]
		- --> update on lava diagram!
			- ![[Pasted image 797.png]]
 























