# Context-Free Grammars
### July 31, 2020 - lecture 16

### What are Context-Free Grammars
- we need a way to express non-regular languages effectively
- we can imagine setting up a sort of *template* where different types of expressions can fill in blanks (kind of like a mad-libs template that expects certain kinds of rules at each blank)
	- ![[Pasted image 709.png]] (the application of this would let a calculator accept an algebraic expression - this on a higher level is how programming languages are defined!)
- just like regexs can describe how you build up a language, context-free grammars is a new way to *set rules to define the strings in a non-regular language*
- a **context-free language** can be written in a CFG
- ** CFGs were actually created by Noam Chompsky for linguistics, but cs can use it for natural language processing

### Writing Context-Free Grammars
- `E` and `Op` are the **non-terminals** (variables) (usually red and capitalized), the symbols in blue are **terminal symbols**
- sometimes there are also gray greek symbols just acting as general variables 
- (there conventions might differ in different places)
- the given list of non-terminals and terminals is the **production rules**
- the **start symbol** is by convention the left-hand symbol of the first production/the first symbol you see (and must be a single non-terminal)
	- ![[Pasted image 710.png]] ![[Pasted image 711.png]]	
- there are shorthands
	- [] the or symbol ![[Pasted image 712.png]]

### Derivations
- a **Derivation** is a sequence of steps that can get you from a produciton to a list of terminals by replacing non-terminals on the right hand side of that production
- is a string $\alpha$ derives the string $\omega$, we write that as $\alpha \rightarrow * \omega$
	- [] ![[Pasted image 713.png]] (from the earlier example)
	- basically the derivation will only contain non-terminals
- a language can be defined over a certain CFG as the set of derivations from its start production
	- ![[Pasted image 714.png]]
	- [] ![[Pasted image 715.png]] L will include 'dca' but non 'bcb' or 'dTaa' 


### Converting from regexs to CFGs
- CFGs don't have operations, but we can still convert the intuition of the regex operations
- kleene stars
	- [] `S -> a*b` -> `S -> Ab, A->Aa|e` (So a derivation could look like A=>ab, => aab, => aaab, etc.)
- unions
	- [] `S -> a(b U c*)` -> `S -> X, X -> (b U c*)` -> `S -> X, X -> b| C, C-> Cc|epsilon)`
	- ![[Pasted image 717.png]]
- Every Regular Expression Language is context free and can be expressed in both a regex and a CFG
- but CFGs can describe more languages than regexs! Remember, strings can be expressed in a way that needs infinite memory
- ![[Pasted image 718.png]] (CFLs also contains non-regular languages that are context free)
	- this thing is called a *~lava diagram~*

### Designing CFGS
- three main concepts!
	- think recursively (duh)
	- have a construction plan - know in what order/structure you want to build up the string
	- store information in non-terminals. they don't change!
- [] checking for palindromes
	- thinking inductively (building up)
		- ![[Pasted image 719.png]]
	- thinking recursively (building down/tearing apart)
		- think of a string S with two identical chars taken of each end still being a palindrom (aSa and bSb and on the right of S->)
- [] checking for balanced braces
	- thinking recurisvely;
		- ![[Pasted image 721.png]]
		- ![[Pasted image 722.png]]
- **The CFG has to not generate any extra strings in the Language, and has to generae *every* string in the Language**
	- [] checking for if every string has same number of as and bs
		- ![[Pasted image 723.png]]
		- none of these CFGs work!! 

- be careful to have base cases that terminate the recursive CFGs!
	- [] ![[Pasted image 724.png]]
	- every nonterminal needs a way to turn into a terminal

- remember that terminals expanding out are entirely independent - they don't have to expand out identically
	- [] ![[Pasted image 725.png]]
	- if you want two sides of an expression to be the same, they *have*  to be terminals
- decide on the order in which you design a string according to the program (building up/building down)
	- [] ![[Pasted image 726.png]] <- uses building up instead of building down like last example


- terminals should repesent different pieces of information (almost like states in a dfa)
	- [] ![[Pasted image 727.png]]
	- ![[Pasted image 728.png]]

- [] design funciton prototypes
	- ![[Pasted image 729.png]]
	- ![[Pasted image 730.png]] (that recursive way of defining a list is very common)
	- this on a higher level is how programming languages are defined!

- (summary)
	- ![[Pasted image 731.png]]









