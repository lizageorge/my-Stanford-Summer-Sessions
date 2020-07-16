# Recursive Backtracking
### July 8-14, 2020 - day 10-13

- **Recursive Backtracking** - make a choice on solving a solution, explore that choice, and then going back and making another choice (*choose-explore-choose*)
	- [] making coin flip combinations - *generatring permutations*
		- you can find a self-similar pattern in each possible branching of combinations of coins like adding on to old braches (HH -> HHT and HHH, etc.)
		- you can think of this using *decision trees*
			- ![[Pasted image 299.png]] 
			- the base case is when you reach the *leaves of your decision tree*, recursive cases are the *decision points/branch joints* (so there's a recursive call in the function for each decision to be made. if this was a combination of dice rolls, there would be six calls)
			- not that we can have *variable decisions at each joint*
		- base case = when flipsLeft = 0, recursive case = when you add "H" or "T" to the end of a sequence
		- ![[Pasted image 300.png]] 
	- in recursive backtracking, we actually give an empty solution as a parameter, and have the final output being made at the leaves (as opposed to regular recursive function where a value is returned back up the tree from the base case and output is only found at main call)
		- ![[Pasted image 301.png]]
		
- **When to use Recursive Backtracking**
	- to generate all possible solutions - *generatring permutations*
		- --> find best possible solution
		- --> determine if a certain solution exists
	- you can also generate all possible subsets of a given set

### Generating Permutations
- [] Unscrambling words - *generatring permutations*
	- generate a sequence of letters (like generating coin flips), but the number of choices avaiable is constrained by previous letters
		- there are always n! permutations of a combination of n elements
	- we can think of this as taking one letter, and adding it to all permutations of the remaining letters. So the base case is no letters left to choose from, recursive case is adding on combinations to previous combinations
		- so each level of the tree will have a different number of options, and as we go we have to keep track of remaining elements = **shrinkable decision tree**
		- [] ![[Pasted image 341.png]]
	- ![[Pasted image 342.png]]
	- with backtracking, we could explore a variable number of options at each step
- [] finding shrinkable words
	- we need to look at every subset of a word to see if it's a valid english word
	- base case = shrinkable single-letter word + a string that is not a word, recursive case = a multi-letter word to test for shrinkable
	- ![[Pasted image 343.png]]
	- [ ] note that we had to *keep track of the decisions already made and those still need to be made*

### Working with large ADTs, generating subsets
- [] generating subsets of a given list of people
	- the two options at each *recursive case* is whether or not to inlude another elem in the subset we're buliding
	- ![[Pasted image 377.png]]
	- note that we had to *keep track of the people already included in each path and who is available to choose* - *the base case*/leaves of the tree is when there is no one remaining to choose from 
	- ![[Pasted image 378.png]]
	- note that when working with large ADTs and passing by reference, we have to be careful in the "recurse/unchoose" step to *undo* any changes made in the rest of the function
		- ![[Pasted image 379.png]]
		- "choose-explore-undo"
		- it's rarely an option to not pass-by-reference on any recursive method that uses ADTs as params (incl. non-backtracking ones) bc otherwise huge copies would be made again and again with every recursive call
- [] Jury selection - how to find sets of candidates with sum bias of zero
	- note that we're working with Vectors cause there could be duplicate candidates in the pool
	- recursive case = at each level, choosing to add and not add each remaining elem
	- base case = when there are no more candidates left to choose from, also check if bias is equal to 0
	- ![[Pasted image 380.png]]
	- note the helper function also helps keep track of sum of bias so far
	- honestly there's a better way of doing this - instead of removing and re-inserting the first elem randomly, since we're anyways using vectors, we can try keeping track of the elements we've already looked at with a passed index variable
		- ![[Pasted image 381.png]]

### Maze Example - Depth First Search
- [ ]  go through lecture explanation of this again...
- base case = reached exit...yeah no revisit lecture
- [ ] compare BFS and DFS ![[Pasted image 383.png]]


### Recursively generating combinations
- combinations have fixed sizes and picks from larger sets of options. So they're like all subsets of size 
- each decision in the decision tree would still be to include or exclude a specific justice
- ![[Pasted image 402.png]]
- [] Making combinations of 5 justices out of nine chief justices
	- make a helper function to generate combinations
	- the base cases are maxing out the number spots available AND running out of elems to pick from while you still have open slots (that last case is because the recursvie call for "exclude" doesn't change k)
	- ![[Pasted image 403.png]]
	- ![[Pasted image 405.png]]
	- ![[Pasted image 404.png]]

### Recursion with Optimization problems
- there is a set of problems called **NP-hard** problems that simply don't have a simple/efficient solution (they usually involve generating permutations or all possible solutions), and require recursive solutions
-  [] the Knapsack Problem
	- imagine having to put together a survival knapsack, where every element has a survival value and a weight. you need to generate a combination of elems that maximizes value while staying under a weight limit
	- you can't just use a greedy approach that picks the item with the highest value that will fit, because there might be combinations of smaller-value items that sum up to a greater total value and still fit
	- the recursive approach is to generate all possible combinations of items that fit and pick the one with best total value
		- we'll just keep track of the biggest value possible (not the actual subset/combination that yielded that combo)
		- very similar to the generating subsets example with S.C. judges, but here the restricting factor is the total weight (not the number of items added) 
		- recursive case; choosing whether to include or exclude an item, calculate values, and *return the larger one*
		- base case; stop when you run out of capacity or if you run out items to choose from
		- we don't need an unchoose step bc there's not ADT we're modifying
	- ![[Pasted image 406.png]]
	- ![[Pasted image 408.png]]
	- [ ] i asked this during lecture but honestly didn't get it...why does using a forloop to iterate through the index instead of passing it through the method allow for identical possibilities to be searched?
	
## Key Takeaways from all of these Backtracking examples
- Backtracking works outwards, from empty values towards the final values, think of an upside down tree where the leaves are the base cases and are also where the final answers are
- the backtracking decision tree works on a "choose-explore-unchoose pattern" (down and then back up, move over down and then back up...)
	- for generating permutations, the equivalent is copy-add-recurse
- backtracking trees can have variable decisions available at each level (the number of decisions can change or change in number)
	- as we go, we need some way to keep track of what decisions have already been made and what haven't / what options have been used up and what are still available
- use of helper recursive functions that reduce the number of params in the main-function call is common
- when generating subsets, each decision will be whether to include or exclude a certain element in the set being built up. The difference with combinations is that the size of the "subset" is restricted
- when working with large ADTs and passing by reference (it's not really an option to not pass by reference), be sure to *undo* any changes made to the ADT within the method ("choose-explore-undo")
	- when generating subsets, maximize efficiency by keeping track of the index of the element currently under consider for include/excluding instead of just removing and re-inserting that element every time
- optimization problems are just like other backtracking problems where we generate combinations, but with the added layer of checking for the best-solution-so-far as we go and only returning the best one
- USES FOR RECURSIVE BACKTRACKING
	- generating permutations (order matters)
	- generating subsets (order doesn't matter)
		- generating combinations (retricted size)
		- optimization problems (only return best-answers-so-far)
- **Backtracking strategies:**
	- ![[Pasted image 454.png]]