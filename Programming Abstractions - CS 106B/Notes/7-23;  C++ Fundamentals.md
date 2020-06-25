# C++ Fundamentals
### June 23, 2020 - day 2

- benefits of C++ (review from yesterday)
	- compiled language (not interpretted)
	- lower level language, gives access to lower-level computer access, understand abstractions better!

## history and overview
- based off of C. Bjarne Stroustrup chose to build off C bc it was powerful and widely-used
- an oop language from the start
- it has grown quite complex over time
- Benefits
	- very fast
	- very popular
	- powerful - gives access to more computer complexity
- Drawbacks
	- complex (this course is going to use the Stanford c++ library instead of the standard libraries)
	- dangerous - bc it gives lower-level computer access, can have more damaging mistakes

## whirlwind tour
(I will only incl any differences bween c++ and java, bc that is the lang i know that i'm most used to and what c++ is most similar to)
- include statements
	- you must include a header file with any "imports"
	- two ways
		- use angle brackets for standard liraries `#include <iostream>;`
		- use quotations for  custom libraries `#include "console.h";`
- variables and types
	- convention is to use lowercase camelcase for variables 
	- the types in c++ are **int, long, double, string, char, boolean**, and types are *explicitly defined and cannot change* (you can use casting functions though)
	- initialize chars with single-quotes and strings with double-quotes
- functions and parameters
		- function prototype = you can declare a function without initializing it with an implementation (just like you can declare and initialize vars seperately). the decleration should include the whole method header; the return type, the name, and the parameters.
			- ` [returnType] [functionName] ( [paramters, with varType and name] );`
		- you *must* define a function before (first in the code file) you use it, *unlike in java*
		- the scope of a variable inside a function is that function
		- you can have multiple functions of the same name *only if the parameters differ* (c++ doesn't look at the return type for public interface)
		- c++ uses **pass-by-value**; when you pass in a var, it creates a *new variable* that copies the *value* of that var. so you can't change an outside variable in another function
			- this will print "myValue is now 5, the new value is 10". The value of myValue cannot be changed by an outside function
		
	
```
int doubleX(int x)
{
x=*2
return x
}
int main()
{
int myValue = 5;
int newValue = doubleX(myValue);
cout << "myValue is now " << myValue << endl;
cout << "the new value is " << newValue << endl;
return 0;
}
```
			
- control flow
	- boolean expression and operators work the same as in java
	- conditional if and ifelsestatements look the same as in java, so do while and for loops
