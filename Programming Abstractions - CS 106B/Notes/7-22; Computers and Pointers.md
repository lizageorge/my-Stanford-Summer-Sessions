# Computers and Pointers
### July 20, 21 2020 - day 18

## How is a Computer Memory System Organized?
- another abstraction boundary: ![[Pasted image 598.png]]
- the progams we write work with the computer's **RAM** (Random Access Memory) 
	- this is what we're refering to when we say "computer memory"
	- c++ gives us several ways to ineract with this
- Memory can be through of a huge pool of suitcases in which we can store information. Each suitcase will include a **memory address**, which is what we use to access that piece of information
	- ![[Pasted image 599.png]]
	- the computer OS is in charge of managing and generating these values for addresses. They're written in hexadecimal (preceded by '0x')


## More Memory Management with cpp

### Pointers
- a pointer is a data type that *stores a memory address*
- ![[Pasted image 600.png]]
	- addressOf() isn't actually a thing. you can access the address of a particular variable like so; (note this is a different use of & than pass-by-ref)
		- ![[Pasted image 601.png]]
		- you won't actually use this in this class ("please don't ever write code like this, tmrw we'll show you how you should do this")
- the `new` keyword is what lets you allocate space for something in the heap. We used it with arrays before, but you can use it even with just one single value
	- ![[Pasted image 602.png]]
	- useful for linked ADTs
	- if you have a single value like this, you *have* to use `delete` instead of `delete[]`
- you can *deference a pointer* (use the pointer to get to the value of the addressed variable/ 'follow the arrow')
	- ![[Pasted image 603.png]]
	- you can use this to read or write to the addressed variable
	- [] ![[Pasted image 606.png]]
- some tips
	- be very vigilant that the pointers you're derefencing are valid (they're actually pointing to something). So if you have to define a pointer without an initial value, use `nullptr` as a placeholder initial value
		- ![[Pasted image 604.png]]
		- you can also check for `nullptr` when given a pointer before dereferencing
			- ![[Pasted image 605.png]] 
		- if you try to derefence a pointer of nullptr value, the program will crash (= **segmentation fault**), but if you derefence a pointer of garbage values, you get unpredictable behaviour which is arguably worse	
	- use the box and arrow diagrams to understand what exactly is happenning


rip binky 1999-1999

















