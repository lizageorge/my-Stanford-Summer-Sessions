# Tasks for Programming Abstractions

- [ ] check office hours schedule (for minors) on course website
- [x] check the style guide on website
- [x] read cs106b testing guide
- [ ] Assignment 1! [due tue, jun 30]
	- [ ] perfect numbers
		- [x] basic
		- [ ] extra
	- [ ] soundex search
		- [ ] basic
		- [ ] extra
- [ ] check section assingments(optional to actually do it, answers in lauren's email)
 
### Color: Purple


## Questions
- [ ] do function header comments have to follow a certain format, like standard function headers in java?
- [ ] what do I put for "section" in the header of files
- [ ] (QT Creator) is there a way to jump from breakpoint to the next breakpoint without having to step-over again and again (like in intellij)?
- [ ] ASSIGN1
	- [ ] Perfect Numbers
		- [ ] Q1 - does 'numbers that it searches through' include all of the checks in divisorSum()?
		- [ ] (less pressing) smarterSum - I handled the edge case of not adding the swrt of a perfect square twice with that if statement check, and the edge case of 1 with another if statement. But is that a less efficient way of doing it (having to check every single divisor twice when I'm only looking to exclude two numbers) than not looping up to the sqrt, and adding the sqrt at the end if n is a perfect square (instead of checking every single time)?
		- [ ] findnthperfecteuclid extra
			- [ ] check if syllabus goes over error handling before trying on your own (there's a question on ed abt it - you can just output diff values/messages and have tests expecting them if you can't work with simpletest). 
				- [ ] handle inputs less than one
				- [ ] handle inputs greater than 5
				- [ ] include a new student test for edge cases, get rid of old redundant ones
			- [ ] extra efficiency in the isPrime method. Can I maybe get to n = 6??
		- [ ] "As a finishing touch on this portion of the assignment, add to the comments in perfect.cpp to share with your section leader a little something about yourself and to offer an interesting tidbit you learned in doing this exercise (be it something about C++, algorithms, number theory, how spunky your computer is, or something else exciting!)." 
	- [ ] Soundex
		- [ ] do we need to know/can you explain how the inputting works?
		- [ ] (extra) rearrange algorithm steps to combine some (like removing duplicates and zeroes), and update Q11 to match. 
		- [ ] I used the method [toUpperCase](https://web.stanford.edu/dept/cs_edu/cppdoc/strlib.html#Function:toUpperCase) on a char (in the method encode()) but the library says it's supposed to input and output strings. can any char/string specific method be interchanged like this? 
		- [ ] the stupid 0 < -1 error - uncomment the test for removeDuplicates when fixed (try Nick's office hours )