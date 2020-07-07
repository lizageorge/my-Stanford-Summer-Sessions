# Intro to C++
### June 21, 2020 - my own notes

Resources:
- https://www.youtube.com/watch?v=K8VzVDldDbo
- https://www.learncpp.com/cpp-tutorial/


## Transitioning from Java to C++
- It seems like there are a few syntactical/minor differences to keep in mind
	- packages = namespaces
		- one of the most common C++ Standard Librararies is iostream. To use this, incl ` #include <iostream` at the top of the file (the *preprocessor directive*), and `stf:: [name` to access a function
	- all main methods are part of a 'global space', not any one class, must return an int (sucessful = 0), and take a slightly different list of args
	- methods don't have an access keyword (public/private) in the header. If you call a method that is declared lower down in the file, you have to use forward declaration(more later) - so most of the time, reorder your function declarations to that calls are after definitions
	- calling methods has a different syntax...
		- `System.out.println("Hello!");` translates into `std::cout << "Hello!" << std::endl;`
		- the `<<` is called the *insertion operator*, and "send" the input of Hello World into the function. It can be used multiple times in a chain (`std::cout << "the value of x is " << x;`)
		- If you want the console print to be a new line (the equivalient fo println()), then use `<< std::endl`

- Compiling
	- c++ files are compiled into *object files* through the c++ compiler, and can be combined into one executable file using a *linker*

- Forward Declaration
	- for when you define a function later in the file than where you called it, it can be easier to declare the existence of all of your functions at the top of the file using *function prototypes*
	```
	int add(int x, int y);

	int main()
	{
		add(1, 2);
	}

	int add(int x, int y)
	{
		return x + y;
	}
	```

- The Standard Library
	- iostream
		- cout, endl for outputting (see above)
		- cin for inputting/reading for keyboard inputs
			```
			int x;
    		std::cin >> x;
    		std::cout << "you entered " << x;
			```
			- use the *extractor operator* this time, `>>`, to take the output of the previous function and assign the following var to it (the extractor and insertion operators go in the flow of the direction)
- Void methods
	- methods with return type void can still use `return` to end the flow of the function as long as it doesn't include a value
	- []![[Pasted image 223.png]]