# Recursive Optimization
### July 14, 2020 - day 13

- there is a set of problems called **NP-hard** problems that simply don't have a simple/efficient solution (they usually involve generating permutations or all possible solutions), and require recursive solutions


### [] the Knapsack Problem
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

### Recursibe Optimization takeaways
- optimization problems are just like other backtracking problems where we generate combinations, but with the added layer of checking for the best-solution-so-far as we go and only returning the best one