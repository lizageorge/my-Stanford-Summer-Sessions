# Big-O Notation and Algorithmic Analyses
### August 2, 2020 - day 8

## Big-O Notation
- It's very usefult to have effiicient algrothims to achieve more with fewer computing resources, but we need to formalize the way we measure the efficiency to analyze it
- **Big-O Notation is a way to quantify the rae at which something grows** - "on the order of..."
	- []![[Pasted image 151.png]]
	- [] Metcalfe's Law - the value of a communication network with n users grows O(n^2). So if you want to increase the value by a factor of 100, you only need to grow n by 10. 
	- [ ] check second example (cell size)
	- [] If you were a manufacturer and wanted to predict the cost of a factory producing n number of toys, the *rate* at which the cost grows is just n! (disregard starting constant values, disregard coefficient below bc that doesn't change the rate over change in n)
		- ![[Pasted image 152.png]] 

## Applying Algorithmic Analyses
- you can't just use the changes in runtime to figure out the big-O notation, because the runtime for the exact same code can vary from trial-to-trail on one computer, or even more between different computers ("runtime is messy"). Bc there are outside factors, runtime cannot make accurate predictions
- instead, think of every *statement* in the code as taking one *unit* of time. Tally up the units to find what the big-o notation would look like
	- [] ![[Pasted image 153.png]] = ![[Pasted image 154.png]] = `O(n)`
	- we only care about the tallies of time units that are a multiple of n, not the constants!
- we always assume the worst-case for variable loops, because the real-world application for this is dedicating certain amounts of processing power  to certain tasks, so you alays want to round upwards! (the same way we build and test algorithms to be able to handle the worst possible edge cases)
- nested loops have exponential big-O notations!
	- [] ![[Pasted image 155.png]] = ![[Pasted image 156.png]] = ![[Pasted image 157.png]] - `O(n^2)`
- **constant run** - sometimes the runtime isn't dependent on n at all
	- []![[Pasted image 158.png]] - `O(1)`
	- (the "1" is just a generalization of a constant rate. So the notation would still be O(1) even if you had ten cout statements)
- If you have multiple variables to work  with, you would just include multiple variables in the big-O notation
	- [] the nested for loop to iterate through a matrix of r rows and c collumns has O(r* c)
- We optimize algorithms to be efficient and fast, we're aiming for these smaller bi-O notations
	- `O(1)` > `O(n)`> `O(n^2)`
	- ![[Pasted image 297.png]]

### The Analysis Process
- count up the number of operations that vary based on the input n
	- strip away any constant functions
	- look at the biggest process
	- for helper functions like those of provided ADTs, be sure to check their Big-Oh in the documentation! If, for example, inserting an element `n` into a set actually takes `O(log n)`
		- ![[Pasted image 545.png]]
	- if you have multiple growth factors/rates (suppose one for loop that loops `n` times and adding an element to a set) the Big-Oh will include both (`O(n logn)`). However, you still don't count multiple repeats (suppose there were two for loops in the previous example, it would still be (`O(n logn)`)
- **Analysis of Recursive Programs**
	- think about the number of calls each frame needs
	- then think about how many times the function is called/how many stack frams are needed
		- most functions would produce a tree! ![[Pasted image 461.png]] (it helps to draw out the tree)
		- this would produce an exponential pattern per row, and all the rows need to be added up
	- so the total runtime would be `(total number of recursive calls)(runtime of a single call)`. If most of the additives in that sum are constants and there's one dominating addiditive, that's the only one you care about ([] (2 + 4 + 8 + 16....+ s^n ) --> n^n)
		- ![[Pasted image 462.png]] 
	- ** log(n) is one of the fastest possible
		- ![[Pasted image 463.png]] log of n is when you have repeated *division* in the recursive call instead of repeated *subtraction*
	- ** don't mix up n^2 (quadtratic) with 2^n(exponential, like when you have a binary tree)!
- **Observing provided runtimes**
	- if you're given a table on input sizes and runtimes and you're asked to identify its Big-Oh, don't just look at the differences between the rows. Look at the *rate of change of the differences*
		- are the changes increasing with input size? (exponential)
		- are the changes decreasing with input size? (logarithmic)
		- are they staying about the same/not following either pattern? (linear)
- sometimes, analyisis of "auxillary storagge space" is asked for - again, just see how the number of variables declared changes based on input size