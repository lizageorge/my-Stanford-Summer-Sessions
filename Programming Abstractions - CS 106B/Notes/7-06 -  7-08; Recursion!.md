# Recursion
### July 6-8, 2020 - day 9-11

### Defining Recursion
- **Recursion** = a problem solving technique where a task is split into repeated smaller tasks that take on the same form
	- a powerful substitution for iteration/loops in certain cases. can yield more elegant/shorter code
	- [] imagine trying to count up all the students in a lecture hall. you could ask one student to count how many people are behind them in a column. they would ask the same to the person behind them, over and over again until the last person who could return "0"
- **base case** = the simplest case that can be answered directly. every other case waits for this case to return a value ([] the student at the end of the column returning 0)
- **recursive case** = the step where the smaller case is called, which cannot be answered directly ([] every other student that asks the person behind them for how many are behind them)
	- take the recursive leap of faith!
- once a base case returns a value, that value travels back up the call stack until the main function call

### Example - calculating factorials
- ![[Pasted image 190.png]] - the base case is when n is equal to 1, the recursive case is when n isn't one, and n! is equal to n(n-1) 
- ** every time a function is called, a **stack frame** is created. A frame is an area in memory needd for a specific function call. this means that every new call has no context of the last call, all it has is the parameter n. 
	- ![[Pasted image 193.png]]
- once a function reaches a return call, the stack frame is cleared! then the return values will be propogated back up to the original call from main.
- comparing to an iterative solution;
	- ![[Pasted image 194.png]] vs. ![[Pasted image 196.png]]


### Example - reverse string example
- when approaching a possible recursive problem...
	- look for *self-similarity*/repetition
	- work through a simple example first, and think about what information you really need for each step/set of steps. could that be a seperate stack frame?
	- identify the base and recursive cases, and then take the leap of faith!
- here, to reverse a string the functionality is...
	- base case = ""
	- recursive case = the reverse of a case is the first char appeneded to the end of the reverse of the rest of the string
	- ![[Pasted image 197.png]]


### Example - palindrome string example
- write a function that determines if a given string is a palindrome
- functionality;
	- the repeating step is checking to see if the first and last char is the same, and then the first and last of the new string, and then ...
	- base case; one or zero characters -> return true
	- recursive case; (...else) if the first and last char is the same.
- ![[Pasted image 213.png]]


### Strategy for solving recursive problems
- 1. look for a self-similar pattern
- 2. determing a base case (the simplest/ending case) and the recursive case (brings you one step closer to the base case)

## Visually representing recursion
- **Self-similarity** = an object is self-similar when it contains the pattern of itself
	- []![[Pasted image 214.png]]
- Graphical representations
	- allows us to see what it looks like when we have multiple recursive calls in the recursive function, and there are many *branches*
	- [] the "vee" program drew a tree; ![[Pasted image 215.png]]
	- **fractals** = any repeated graphical pattern, repeated instances of the same self-similar pattern
		- []![[Pasted image 216.png]]
		- the only things the differentiates the "smaller tree" from the whole and other smaller trees are
			- position -  ![[Pasted image 217.png]]
			- size
			- orientation
			- order
				- order refers to the number of recursive steps/the layers of complexity a tree has. Order 0 is blank, Order 1 has one branch... *Order-n tree has two branches with order(n-1) branches going from it*
				- ![[Pasted image 219.png]]
	- recursivedrawing.com

### Making art with fractals
- Stanfords graphic library
	- uses a `GWindow`, every object in it has a coordinate pair `(x, y)` where the top-left corner is `(0,0)`
	- GPoint is just a struct for a coordinate, get `getX()` and `getY()` methods
	- ![[Pasted image 220.png]]
	- all the graphics implementation is abstracted away for us in this class
- **Cantor Set**
	-  = a set of lines, with a main line at the top, and two lines filled in the length of the first and third thirds of that line. this filling in of thirds is repeated over and over again downwards
	-  ![[Pasted image 221.png]]
	-  order-0 is a blank page, order-1 has one line, order-2 has one long line and two shorter lines, etc.
	-  using the graphics library and self-similarity to draw a cantor set of order *n*
		-  ![[Pasted image 222.png]]
		-  the base case is order-0
	- [] ![[Pasted image 224.png]]

- **Sierpinski Carpet**
	- = taking a square and subdividing into 9 squares, and repeat again and again with the surrounding . almost a 2d version of cantor set
	- ![[Pasted image 225.png]]
	- order-0 is a single filled-in square, order-1 is that square with the surrounding 8 squares removed, order 2 is that pattern copied into each square
		- ![[Pasted image 226.png]], ![[Pasted image 227.png]]
	- base case = order-0, recursive case = (order-n) draw 8 sierpinski carpets
		- it makes sense to use iteration to call those 8 carpets - *you can combine recursion and iteration as needed*


## Why we use Recursion
### elegance
- [] Towers of Hanoi
	- suppose we have four disks. we already have an algorithm to move three disks onto the auxilary peg. after that we can move the fourth pin to destination. and then we have an algorithm that can move three pins from auxillary to destination!
	- iterative solution;
		- ![[Pasted image 292.png]]
	- recursive solution
		- ![[Pasted image 293.png]]
	- O(2^n) to find solution for n disks

### efficient
- [] Binary Search
	- the process of looking at the middle index and halving the list we're searching repeats, and can be repeated recursively
	- base case = found the element, recursive case = binary search the right/left half of the data
	- ![[Pasted image 294.png]] (the first check will only return if the element is not in the list, so it counts as a base case)
- we can use recursive *helper functions* to further abstract your function. In this example, the recursive calls need the start and end index parameters, but we don't want the user to handle that. so we use another function to abstract that away
	- ![[Pasted image 295.png]]
- the complexity of binary search is O(log(N))
	- ![[Pasted image 296.png]]
	- we drop the base 2 bc the rate of change of log(N) and log_2(N) are comparable
- ![[Pasted image 297.png]] an exhaustive search would use O(n)
- there are a few standard methods for sorting and searching that use similar recursive algorithms and have logarithmic complexity
	- ![[Pasted image 298.png]] 

- merge sort is another algorithm that uses recursion, a "divide-and-conquer" strategy, and has a runtime of O(log(n))
	- ![[Pasted image 354.png]]
	- first the list is split recursively (the red portion), sort every pair of elements that was last split (gray to first green) and then repeatedly merge the last two split lists that are now sorted (comparing the first two elems of each list, and then the next, on and one) (the rest of the green portion) (

### dynamic
- there are some problems that are almost to solve iteratively, when there are many possible solutions and paths for solving. This is when you have to use recursion.
- **Recursive Backtracking** - make a choice on solving a solution, explore that choice, and then going back and making another choice (*choose-explore-choose*)
	- [] making coin flip combinations
		- you can find a self-similar pattern in each possible branching of combinations of coins like adding on to old braches (HH -> HHT and HHH, etc.)
		- you can think of this using *decision trees*
			- ![[Pasted image 299.png]] 
			- the base case is when you reach the *leaves of your decision tree*, recursive cases are the *decision points/branch joints* (so there's a recursive call in the function for each decision to be made. if this was a combination of dice rolls, there would be six calls)
		- base case = when flipsLeft = 0, recursive case = when you add "H" or "T" to the end of a sequence
		- ![[Pasted image 300.png]] 
	- in recursive backtracking, we actually give an empty solution as a parameter, and have the final output being made at the leaves (as opposed to regular recursive function where a value is returned back up the tree from the base case and output is only found at main call)
		- ![[Pasted image 301.png]]























