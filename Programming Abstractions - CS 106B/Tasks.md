# Tasks for Programming Abstractions

- [ ] check office hours schedule (for minors) on course website
- [x] check the style guide on website
- [x] read cs106b testing guide
- [ ] Assignment 1! [due tue, jun 30]
	- [ ] perfect numbers
		- [x] basic
		- [x] review
		- [ ] extra
	- [ ] soundex search
		- [x] basic - just reached "Developing a census search program"
		- [ ] review
		- [ ] extra

- [ ] check the difference bween pass-by-value and pass-by-reference (in c++ and java)
- [ ] optional practice;
	- [ ] check section assingments(optional to actually do it, answers in lauren's email)
	- [ ] generalized tower of hanoi method from lecture 6 (on ed) (code at the bottom T^T)
 
### Color: Purple


## Questions
- [ ] do function header comments have to follow a certain format, like standard function headers in java?
- [ ] (QT Creator) is there a way to jump from breakpoint to the next breakpoint without having to step-over again and again (like in intellij)?
- [ ] ASSIGN1
	- [ ] sign up for lair!! lmao nwm ig T^T
		- efficiency maybe?/better (more thorough) way to do things..
			- isPrime handline 0 and 1 and negatives with <2
			- smarterSum edgecases
		- if I wanted to try different ways to make the program more efficient, can I submit those changes/extra methods in a seperate file?
	
##  Per Assingment
- [ ] RESUBMIT!!! changes made since last submission;
	- [ ] (no- email lauren about double submission, incl the nams of "normal" and "extra", incl link to nick's post on ed
	- [ ] perfect:
		- [ ] (really small) fixed the name of time trials for findperfectsmarter
		- [ ] sPrimeSmarter, findNthPerfectEuclidSMarter - honestly only isPrimeSmarter showed any change at all, so maybe consider just keeping it in the same file? idk like just change the for loop to only be up to sqrt(n)
	- [ ] soundex:
		- [ ] 



- [ ] Perfect Numbers
	- [ ] (less pressing) smarterSum - I handled the edge case of not adding the swrt of a perfect square twice with that if statement check, and the edge case of 1 with another if statement. But is that a less efficient way of doing it (having to check every single divisor twice when I'm only looking to exclude two numbers) than not looping up to the sqrt, and adding the sqrt at the end if n is a perfect square (instead of checking every single time)?
	- [x] (extra) findnthperfecteuclid error handling
		- [x] check if syllabus goes over error handling before trying on your own (there's a question on ed abt it - you can just output diff values/messages and have tests expecting them if you can't work with simpletest).  (draft at the bottom)
		- [x] handle inputs less than one
		- [x] handle inputs greater than 5
		- [x] include a new student test for edge cases, get rid of old redundant ones
	- [ ] (extra)extra efficiency in the isPrime method. Can I maybe get to n = 6?? (if so update errors on findnthperfecteuclid)
		- [x] (does the for loop have to go all the way to n? swrt(n)? can it increment by 2/somehow skip all evens?)
		- [ ] ~fancy~ algorithm online? (numberphile...? idk look it up)
	- [ ] for extra efficiency changes, be sure to incl time tests to show any changes
	

- [ ] Soundex
	- [ ] do we need to know/can you explain how the inputting works?
	- [ ] (extra) rearrange algorithm steps to combine some steps(like removing duplicates and zeroes), and update Q12 to match. 
	- [ ] (extra) test efficiency of soundex search. can it be improved by first only checking the first letter in the do-while loop?
	- [ ] (extra) implement another search system?
	- [ ] I used the method [toUpperCase](https://web.stanford.edu/dept/cs_edu/cppdoc/strlib.html#Function:toUpperCase) on a char (in the method encode()) but the library says it's supposed to input and output strings. can any char/string specific method be interchanged like this? 

















//experimenting with error handling...I should probably check if the syllabus goes over this first
//for question 10...There aren't really any edge cases to compare the method against, but I did check to make sure my error handling of any input less than 1 worked with two additional test cases...if I can find a way to test my error handling T^T

//long findNthPerfectEuclid(long n)
//{
//    try {
//        if( n < 1){
//            throw n;
//        }
//        long prime =0;
//        long count = 0;
//        long k = 1;
//        while(count < n){
//            long m = pow(2, k) -1;
//            if(isPrime(m)){
//                prime = m* pow(2, k-1);
//                count++;
//            }
//            k++;
//        }
//        return prime;
//    } catch (long n) {
//        cout<<"Input must be an integer greater than 1"<<endl;
//        return 0;
//    } catch(overflow_error){
//        cout<<"Input is too great, must be less than 5"<<endl;
//        return 0;
//    }
//}
even better, smth from trip's YEAH slides;
![[Pasted image 113.png]]



















// #include <iostream>
#include "console.h"
#include "stack.h"
#include "reverse.h"

using namespace std;

void towersOfHanoiThreeDisks(Stack<int>& destination) {
    Stack<int> source = {3, 2, 1};
    Stack<int> auxiliary;
    
    destination.push(source.pop());
    auxiliary.push(source.pop());
    auxiliary.push(destination.pop());
    destination.push(source.pop());
    source.push(auxiliary.pop());
    destination.push(auxiliary.pop());
    destination.push(source.pop());
}

void towersOfHanoiGeneral(Stack<int>& destination, int numDisks) {
    // Populate source stack with numDisks initial disks
    Stack<int> source;
    for (int i = numDisks; i > 0; i--){
        source.push(i);
    }
    Stack<int> auxiliary;
    /* CHALLENGE PROBLEM: FILL ME IN */
}

int main() {

    Stack<int> result; // The final peg

    towersOfHanoiThreeDisks(result);

    // Challenge problem: Write a general towersOfHanoi function
    // result = {};
    // towersOfHanoiGeneral(result, 5);

    cout << result << endl; // Show the final peg

    // Additional ordered ADT examples
    // sentenceReverseStack();
    
    return 0;
}