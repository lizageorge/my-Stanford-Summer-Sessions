# Unsolvable Problems
### August 11 2020 - lecture 19

### Developing the Lava Diagram
- when studying Turing Machines we learned that the landscape of languages are split up into a laval diagram;
	- Regular Languages
	- CFLs
	- Decidable Languages (a decidable TM exists for it)
	- (RE) Recognizable Languages (a TM exists for it)
		- ATM (language of the Universal TM)
		- The Halting Problem
		- All 'general algorithms'
	- Unrecognizable Languages (not TM)
- ![[Pasted image 863.png]]
 
 ## Proving Undecidability 
 
 ### The Halting Problem - classic undecidable problem
 - Given a TM M and a string w, can you know if M will halt (not loop) on w?
 - ![[Pasted image 833.png]]
 - HALT is undecidable;
	 - To prove that a language is undecidable (not in R), prove that a decider for it cannot exist/there exits a hypotheticalfunction using that  decider that would be a self-defeating object
	 - ![[Pasted image 834.png]]
	 - ![[Pasted image 835.png]]
	 - now main() contradicts what you wanted to do with with willHalt
	 - ![[Pasted image 836.png]]
- HALT is recognizable;
	- you could try and make a recognizer by saying 'just keep on running on seemilngly infinite loops, you'll get there eventually!' to accept strings in the language
		- ![[Pasted image 837.png]]
### Checking Securing Voting Problem
- Given a TM that claims to be a secure voting machine, can you check if it's a secure voting machine?
	- [] like say you were checking the following; ![[Pasted image 838.png]]
- No. (remember, we're not saying it's impossible to make a SVM, just that's its impossible to check for a SVM)
	- ![[Pasted image 839.png]]
	- ![[Pasted image 840.png]]
	- (to prove that a laguage is undecidable, make a program that makes it self-defeating)
	- ![[Pasted image 841.png]]
- **There is no General Algoritgm** = you cannot design decider programs that can make universal claims about other programs, bc you can disprove it like ^
	- we can design algorithms that check specific cases, but not all programs, bc then it would be self-referentiable and so we could prove it to be self-defeating by adding on a method like ^


## A Different Perspective on RE
- again, there are TMs in RE that could *loop*
- A language is in RE if, for any string w where you are *convinced* that w in L, there is some easy way to prove that to someone else 
	- [] - ![[Pasted image 842.png]] showing the four-clique is very easy, proving that no for-clique exists it much harder
	- [] a sudoku problem - i can just give an answer to a sudoku grid to prove to you that is exists
- **Verification** = in a problem, giving the right answer can convincingly prove that it has a solution. giving a wrong answer doesn't really prove anything either way. 
### Verifiers
- ![[Pasted image 844.png]]
- "c" is the certificate/the *evidence* that something has a solution ([] the existsing four-clique, the working sudoku solution)./ the encoding of the evidence of a solution. We're only checking if a "c" exists, so checking a failing c doesn't mean that the prblem doesn't have a solution. 
	- ![[Pasted image 846.png]]
- Remember, L(V) != L
- [] Hailstone Sequence checker
	- ![[Pasted image 847.png]] in this case, the evidence to provide is the number of steps in a successful sequence
	- ![[Pasted image 848.png]]
	- if 'n' is in L, then there must exist some c where you only need to repeat the hailstone algorithm c times to prove that n is in L. 
- [] Checking for Hamitlonian Path exists
	- ![[Pasted image 849.png]]
	- if G is in L, there there must exist some path (a vector of nodes) that is a hamiltonian path in G that can easily prove that G is in L
- [] a Verifier for ATM
	- (UTM doesn't count bc it doesn't take a certificate)
	- in this case, the certificate c is the number of states required for the M to halt on w
	- ![[Pasted image 850.png]] actually, this method will also only return true if M accepts w
### What languages are verifiable?
- Languages have verifiers iff they are in RE (Languages are in RE iff you can build a recognizer *and/or* a verifier for it. If there doesn't exist a certificate for a verifier, there doesn't exist a way for the certain string to be in the language)
- We can make a recognizer our of a verifier
	- ![[Pasted image 852.png]]
	- we can search through every single possible value of c in the language until we find the certificate that works for w. if w is not in L, then the verifier would just keep on searching forever (and so wouldn't accept!)
	- ![[Pasted image 853.png]]
- We can make a verifier from a recognizer
	- we can always use the number of steps needed for a TM to halt and accept as the certificate
	- [] ![[Pasted image 854.png]]
	- ![[Pasted image 855.png]]
### Two ways to prove in RE
- now we can either make a generalized recognizer, or a verifier for a single explicit working string and certificate in the language!

## Beyond R and RE - Unrecognizable Languages
- we already know there are more problems than there are strings
### The Diagonalizational Language LD
- imagine making a table of all the TMs and the encodings of those TMs, and then observing the diagonal of that table. If we flipped every value in that diagonal...
	- ![[Pasted image 856.png]]
	- ...we knowfor sure there is no TM with this exact behavior (proof that a language with this behavior is not in RE...below)
	- -> there are more problems than there are TMs
- going back to that table, we can make a language out of that diagonal
	- ![[Pasted image 857.png]]
	- ![[Pasted image 858.png]]
	- Ld not in RE!
		- ![[Pasted image 859.png]]
- updated lava diagram...
	- ![[Pasted image 860.png]]
	- actually, if we change our model of 'reasonable computation', we can make computational devices that work with unrecognizable languages
- the philosophical meaning of this...there are strings in languages that we cannot prove are in that language. **There are true statements out there that we cannot prove.** There are limits to what mathematics can do in this world. 
	- ![[Pasted image 861.png]]
- the start of computational theory...
	- ![[Pasted image 862.png]]

















