# Dynamic Memory Allocation
### July 16, 2020 - day 15

- everything (every object) requires some storage space. All of our classes used so far (Vectors, Queues, etc.) use *dynamic memory allocation* to get that space under the hood
- you can work directly with computer memory too!
	- at runtime, you can ask c++ for a set amount of storage space
	- you can use that memory (read and write to it)
	- when you're done using that memory, you have to tell c++ so
- Arrays = the organized chunks computer memory is split up into
	- have types
	- have indices
	- contiguous (no gaps)
## Dynamically Allocating arrays
- the process:
	- first, when we declare a variable, include `*` to the end of the type to define it as a pointer
		- a **pointer** is a new data type that helps you work directly with computer storage space.  Even though they take up space themselves, *Pointers stores memory addresses*. 
	- then declare an array with the keyword `new` (of the same type of the pointer) and make sure the pointer is pointing to it. Now the pointer holds as its value the memory location of the first elem in the array
	- now you can access the elemnts of the array using the pointer and bracket operators
	- `T* arr;` (`T` is just a placeholder for the type)
	- `arr = new T[size]`
	- [] example of this process:
		- ![[Pasted image 489.png]] (notice that the arrow crosses the stack! the pointer is on the stack, array is on heap)
		- after the second line, the point `arr` of type string *points* to the location of the array with the size of numValues and type string
		- now you can access that new array using `arr[index]`, like in the for loop
		- ![[Pasted image 490.png]]
- being able to use dynamically allocated arrays is optimized for space and efficiency, not ease of use - so there are some possible errors
	- the array is of fixed size
	- *there is no bounds checking* - if you try and access outside the bounds, there will be no error, no catching, you'll just get "undefined behvaior" - i.e. we have absolutely no clue what will happen if you go past the bounds, it could mess with the rest of your program or create vulnerabilities or crash the program (this is called **bufferoverflow**)
		- [] in the 80's, robert morris jr. hacked a bunch of gov't code that didn't have proper bounds checks, and was the first person convicted for doing that
		
## Memory from the Stack vs. Heap
- ![[Pasted image 491.png]]
- stacks
	- static memory allocation
	- we don't have to worry about memory management
	- limited by scope of each var, things get recylcles
	- this is where the pointer itself is stored
	- you can think of the stack as like a stack of stack frames (goes up with function calls, down with return calls), each frame can take up as much space as it needs, but the stack as a whole has a limited size
- heaps
	- dynamic memory allocation
	- there's no automatic cleanup!
	- this is where your arrays will be stored

## Cleanup
- when working with the heap, you are in charge of memory allocation and *deallocation*, giving back memory when you're done using it
- anything created with the `new` keyword will stay on the heap, even if the pointer goes out of scope = **memory leak**
	- this can take up all your available heap memory, can ruin computer
- do this using the `delete[] {pointer}` operator. this will 'give back' or deallocate the array that was pointing to
	- ![[Pasted image 492.png]]
- the pointer will stick around as a *dangling* pointer, you'll get awful things if you try to read and write with it. but it will go out of scope like a regular variable
- what's actually happening when we use `delete[]` is that the array in the heap still exists, the computer can descide to leave the values unchanged or clear them. We just no longer have access to it
- this is why an array is "initialized" with random/garbage values, not the nice default values like 0 or an empty string 