# Console Programs, Data Structures (Vectors, Pass-by-Reference)	
### June 25, 2020 - day 4

## Console Programs - interacting with users
- **console programs** = uses the interactive terminal to communicate with a user
	- the console itself acts as an *abstraction boundary* - the user can use the program without having to know the logic behind it
- there's a stanford libr method we can use, `getLine()` will take a string as a param, display it as a prompt, wait for an input, and returns whatever the user inputs before hitting enter
	- this is part of the Stanford simple input.output library ([here's the full documentation](https://web.stanford.edu/dept/cs_edu/cppdoc/simpio.html))
- console programs are usually written in the main() function


## Data structures - how do we structure code?
- **Abstract Data Types** = programming abstractions that allow programmers to store in a structured, organized ways
- using ADTs, we can manage data without worrying about the underlying details
- this course is going to cover ADTs from the Stanford C++, which are more user-friendly, but the principles are the same in all languages
	- CS106L focuses more on standard c++ libraries 


- **Vectors** = an ordered collection of elements of the same data type that can grow and shrink in size
	- ordered = every element has an index
	- equivalent to ArrayLists in Java
	- in the header file/imports; `#include "vector.h";` 
	- `Vector< [type] > [name]` - initialized to empty
	- `vec.add(8)` - adding values
	- `Vector<int> vec = {1, 2, 3, 4}` - declare and initialiize in one line
	- `vec[3]` - access the same way as strings
	- `vec.remove(1)` - remove the element at specified index, move everything else up one index
	- you can traverse with for loops or for-each loops, just like in c++ strings, and java
	- [The full Stanford vectors documentation](https://web.stanford.edu/dept/cs_edu/cppdoc/Vector-class.html)
	
	
- **Pass-by-reference**
	- if you want a function to permanentaly edit a data structure, you would pass in a *reference to the data structure* instead of the value itself. So a copy of the data structure isn't made
	- in c++, this is done by adding an ampersand to the data type defining in the parameter of the function
		- ![[Pasted image 42.png]]
		- when you call this function later, you must enter a variable, not a literal (if you had a pass-by-reference function `double()`, you cannot pass in `double(1.5)` )
		- you can choose to have some parameters pass-by-value and some pass-by-reference in the same function
	- this is most useful in helper methods for complex data structures because normally copying large data structures is inneficient. for smaller data types, it's better to pass-by-value and use returns 
	- this is a sort of workaround to functions only being able to return one value. if you pass-by-reference multiple values, the function can edit all of them (it still isn't returning more than one value, but it can *change multiple*)



























