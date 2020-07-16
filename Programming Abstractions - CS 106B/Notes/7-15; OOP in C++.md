# Object-Oriented Programming
### July 15, day 14

- The creation of classes is literally *the* abstraction boundary

## Definition of a class
- a **class** define a new data type for other programs to use
- Examples we've seen so far are Vectors, Maps, Graphs, Queue, GPoints (not GridLocations)
- Every class has two parts
	- the **interface** = the abstraction boundary, the operations that is available to the user (the documentation)
	- the **implementation** = the actual background code that users don't need to see
- **Encapsultation** = the process of grouping relevant information together and defining where that information is available (**public/private**)


- we can use the class as a *blueprint* to create **instances** of it, called **objects**
	- `Vector<int> vec;` creates an instance of the Vector class

## Writing a class
- three parts;
	- Member variables = variables stored within the class, usually not available outside the class
	- Member functions = functions you can call on an object (when you call it later, the object will be the implicit parameter)
	- Constructor = the function called to create an object
- two files;
	- header and implementation files will have the same root/name for convention
	- write the `[classname].h` header file = defining the interface
		- every member var and function must be defined in the header file
		- include the `#pragma once`	preprocessing directive, makes sure that it won't re-included your code multiple times in a project if you have multiple `#include` calls for this class that you're writing throughout the project (without this, the seperate include calls will try and create two classes with your name and won't compile, like making two vars of the same name) 
		- - inclue the `public:` and `private:` portions of the implementation. public will include all the member functions that you can call on functions, private will include the (privated) member variables (it's good practice to keep all vars private, private helper methods can also be kept here)
		- ![[Pasted image 455.png]]
		- if you have methods that act as accessor methods and don't change the state, you add `const` to the end of the function header (both in the header and implementation files)
			- ![[Pasted image 458.png]]
	- write the actual `[classname].cpp` implementation file
		- include the header file at the top
		- define all your methods, using the *scope resolution operator* to make sure the method is linked to this specific class's header file
			- ![[Pasted image 456.png]]
		- ![[Pasted image 459.png]]
		- write the constructor
			- if you don't define a constructor, there will be an *implicit default constructor* that initializes all the member variables to each var's type's default value
		
















