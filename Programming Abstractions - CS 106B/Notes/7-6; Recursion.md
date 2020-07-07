# Recursion
### August 6, 2020 - day 9

### Defining Recursion
- **Recursion** = a problem solving technique where a task is split into repeated smaller tasks that take on the same form
	- a powerful substitution for iteration/loops in certain cases. can yield more elegant/shorter code
	- [] imagine trying to count up all the students in a lecture hall. you could ask one student to count how many people are behind them in a column. they would ask the same to the person behind them, over and over again until the last person who could return "0"
- **base case** = the simplest case that can be answered directly. every other case waits for this case to return a value ([] the student at the end of the column returning 0)
- **recursive case** = the step where the smaller case is called, which cannot be answered directly ([] every other student that asks the person behind them for how many are behind them)
	- take the recursive leap of faith!

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
- here, to reverse a string...
	- base case = ""
	- recursive case = the reverse of a case is the first char appeneded to the end of the reverse of the rest of the string
	- ![[Pasted image 197.png]]