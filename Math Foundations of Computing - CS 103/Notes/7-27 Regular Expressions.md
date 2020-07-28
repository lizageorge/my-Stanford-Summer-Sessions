# Regular Expressions
### July 27, 2020 - lecture 14


### Summary
- shorthand summary; ![[Pasted image 635.png]]
- constructing a regex from an NFA ![[Pasted image 646.png]]
	- how to eliminate a state; ![[Pasted image 649.png]]
### Review
- regular languages = can be solved using DHAs and NHAs
- properties of regular languages;
	- concatenation
	- language exponentiation
	- closures (Kleene closures, )

## What is a RegEx? An alternate way of thinking of languages...
- construct regular languages from the bottom up (lego method)
- **regular expressions** = expressing a regular language through a string representation (expressing a language through smaller strings/languages)
	- so essentially the regex is a string representation of the construction of a language. the same notation used to represent the languages accepted by an automata can be used for regexs ($\L(R)$ = L if 'R' represents a regex and L is the set of all strings accepted by it)
	- used in software for string processing
- **the atomic regular expressions** = the building blocks
	- the empty set symbol represents the empty language
	- for any a \in sigma, the symbol a represents the language containting {a}
	- the tymbol epsilon represents the set containing the language {epsilon}
- now we compound these together into **compound regular languages**
	- concatenations ($R_1R_2$ is the concatination of R1 and R2)
		- [] "HELLO" = {H}{E}{L}{L}{O} = {HELLO}
	- unions ($R_1 \cup R_2$)
		- [] "HELLO" \cup "GOODBYE" = {HELLO, GOODBYE}
	- Kleene closures ($R*$)
		- [] "H"* = {epsilon, A, AA, AAA...} = {A}*
	- operator precedence: (parentheses can be used to clarify what symbols bind to what strings)
		- ![[Pasted image 627.png]]
		- ![[Pasted image 626.png]]
	- *the formal rules for regular expressions:*
		- ![[Pasted image 628.png]]
	- ** no intersections, complements

## Designing Regular expressions to represent regular languages
- [] creating a regular expressions where every elem has substring "aa"
	- ![[Pasted image 629.png]] (equivalent to $\Sigma$* aa $\Sigma$* )
- the *length* of a string *w* is represented by **|*w*|**
- [] creating a regular expression where every elem has length four
	- ![[Pasted image 630.png]] (equivalent to $\Sigma\Sigma\Sigma\Sigma$)
- the notation **w?** is equivalent to anything from the language w unioned with epsilon (so anything in w or nothing) 
- [] create a regex that contains *at most* one 'a'
	- ![[Pasted image 632.png]] equivalent to b*(a U epsilon)b*
	- or b* a b* U b*
- the notation **w+** is equivalent to  **ww\***  is equivalent to saying 'at least one w' 
- [] create a regex expression representing all email addresses
	- ![[Pasted image 633.png]]
	- once we create a regex like this, we can translate it into code
	- remember, these can still technically be represented by automata...
		- ![[Pasted image 634.png]]


### The power of RegExs
- **Thompson's Algorithm** can convert from regexs into NFAs, and from there to DFAs
- ***any* regular language can be represented with regular expressions** - you can convert any arbitrary NFA  into a reg ex
	- we can label the transitions as regular expressions (create overpasses!)
		- ![[Pasted image 636.png]] -> ![[Pasted image 637.png]]
	- convert the NFA into a *generalized* NFA with just two states
		- ![[Pasted image 640.png]] -> ![[Pasted image 641.png]] -> ![[Pasted image 644.png]] -> ![[Pasted image 645.png]]
	- and from there figure out the expression it represents
		- ![[Pasted image 638.png]]
- the transformations we can do, summarized
	- ![[Pasted image 647.png]]

- now we have multiple ways to represent regular languages;
	- ![[Pasted image 648.png]]

- so! **designing automata**; for each problem, determine *what it is you need to remember* at each state.
	- [] determine if a string is divisible by five
		- ![[Pasted image 651.png]]
		- ![[Pasted image 650.png]] - one state for just read a 0,5 and one stte for just read smth that's not 0, 5
	- [] create an oreo cookie sandwhich (first and last char are same)
		- start with the information you need to keep track of in each state to directly solve the prblem, and then fill in transitions to achieve that 
		- ![[Pasted image 652.png]] (note that blue represents the information known at each state - so the epsilon here just means that last character was "")
- **designing regexes;**; look for patterns in a bunch of examples
	- ![[Pasted image 653.png]]
	- [] create a regex for oreo cookie with alternating O and R 
		- ![[Pasted image 654.png]]

## Applications of Regular Languages
## Intuiting Regular Languages
## The Myhill-Nerode Theorem




