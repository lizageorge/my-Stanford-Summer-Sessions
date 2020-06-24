# Strings and Testing
### June 24, 2020 - day 3

## Strings in C++

- strings = a data type, made up of characters. denoted by double quotation marks. 
	
### The differences between strings and chars in C++ and java
- Strings are mutable in c++. You can work with individual characters like the whole string is an array (you can also use this array notation to access indeces of a string)
	`string word - "hello";
	 word[1] = 'a';
	 //word now equals "hallo" `
- Strings can be concatonated with strings *and* characters using `+`
- Strings can be directly compared with logical operators, just like any other types ([] `abc < bcd`)
	- these comparisons are case sensitive ([] `Abc < abc`)
	- the comparisons are made of askii values. So it's alphabetical, upper-case first
- You can use for-each loops with strings and chars as the looping var
	- ![[Pasted image 38.png]]
- You can use math operators between chars and ints. For example, adding one to a char will 'change' it to the next char in askii order
	- ![[Pasted image 39.png]]
- standard c++ methods for chars accepts the char input as a paramter ([] `islower('a')`), but strings as implicit parameters ([] `var.length()`) (but stanford libraries use excplicit parameters for both)


### C Strings
- as opposed to c++ strings (which is what we've used until now), c strings are string literals (defined on the spot with just double quotations)
- they cannot be concatinated like regular strings ( [/]`string word = "hi" + "there"`), nor can they be appended to chars
- they cannot be used directly as implicit parameters ([/]`"hello".length`)
- convert from c to c++ strings using the method `string("c string")`


## Testing in CS106B
- testing is very very very important, especially when the code goes to critical roles or can risk the loss of a lot of money
- write tests that cover a wide variety of use cases, including edge cases
- Stanford has a helpful testing tool called **SimpleTest**
	- ![[Pasted image 40.png]]