# All Feedback

## Assignments
### Functionality
- function decomposition
	- *functions shouldn't have an extended functionality. Make sure that anything too long is plit up among different functions* (||)
	- but don't get too specific either, and check for pre-existing functionality/helper methods before writing one (`s[0] = toUpperCase(originalSurname[0])` vs. writing out a switchFirstChar function that uses substrings)
- don't worry about keeping edge-case checks out of loops for efficiency. it's not that much of a difference, and it could be clearer within the loop
- code repeating
	- use for loops, etc. to avoid repeating code!
- simplify ADTs used (can a variable just simplify the use of a whole stack? etc.)
- notes on while loops
	- remember that this could be repeated *a lot*. don't use expensive operations within your loop ([]keep an index variable and update that > make a substr with every loop (assign2, search.cpp))
	- be careful about your check - it should handle edge cases too! ([] don't just check if current char is a punc, check if the string is empty first)
	- the benefit of do-while loops is you don't need to repeat the "half-loop", so make sure you're not if you're trying to take advantage of that (assign 2, search.cpp)
- watch out for simpler ways of writing things
	- `str[0]` instead of `str.substr(0, 1)`
	- `return{}` instead of initializing a whole vector/queue/just about anything of size 0 and returning that
- don't have arms-length recursion calls! (= when you have a recursive call within an if-statement that isn't the base case when it should be. instead of this, you want to make that check part of the base case, and if the base case doesn't pass only then will the recursive call be called. it's like if you only called the fibonacci recursive function if n-1!=0 instead of making n== 0 the base case). 


- :) caught edge cases well (||)
- :) tested well (|||)


### Style
- *in-line comments should be short. if anything is too long, keep them in a seperate file, maybe even multi-line* 
- even the multi line comments don't have to be so long
- space everything out (`m* pow(2, p-1)` vs `m * pow(2, p - 1)`)
- (from lecture) include function prototypes for all of your functions, even if they're in a convenient order, for readability
- function header comments don't need to be too long or detailed - just an overview 
- :) good use of whitespace to seperate everything
### Submition
- file header comments should include a little bit on what the functions within do
	- :) file headers are now good (assign2)
- writing exactly that a submission is an extension, which submission is normal, etc. is appreciated
- extensions aren't graded

### Full Grades:
- Assign1 (Functionality: +, Style: ✓+)
- Assign2 (Functionality: ✓+, Style: ✓+)
- Assign3 (Functionality: ✓+, Style: ✓+)


## Assessments
### Practice Exams
- Mid Quarter Practice Diagnostic = 33(+-3)/45
	- timing on the code review + algorithmic analysis + tracing problems was rough...should be more confident/swift next time, come back to the problem with extra time
	- don't forget function order! everytime you add a helper, just be sure to add a prototype at the top
	- be sure to always trace your program very thoroughly/like you don't know what the expected result should be after writing!
	- make sure you thoroughly understand what the question is asking for. What *exactly* are you supposed to return/output (it'll help to store this in a var with an appropriate name(instead of result)), and how does the rest of your code relate to that (count the number of paths, not the number of movements in all the paths)
	- difficult EC backtracking problem - there was honestly a much simpler and easier way of doing it, but this is what i reached even after following every problem solving/decomposition strategy. so ig it's just a matter of practicing that intuition
