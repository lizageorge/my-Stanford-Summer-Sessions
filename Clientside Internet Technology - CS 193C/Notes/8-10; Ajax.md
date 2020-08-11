# Ajax
### August 10, Lecture 11

- Ajax is a tool that allows you to make **Single Page Applications**
	- the JS will make a request ot the web server, and instead of replacing the current webpage it *modifies  the current webpage* using that server info by using computer memory
	- single page applications like Gmal, doesn't reload on every click
- Ajax used to use XML, but now relies more on JSON 

## JSON
- JS Object Notation
- a text format to easily and in standardized way transfer data
- the syntax is very similar to JS objects, but both the property names and values are written in `""` 
	- [] ![[Pasted image 807.png]]
	- the whole thing needs to be a single object (`[]` or `{}`). you can nest objects and arrays within each other
		- [] ![[Pasted image 808.png]]
- basically replacing xml
	- ![[Pasted image 809.png]] vs ![[Pasted image 810.png]]
- you cannot have loops! so no object can refer to itself
	- this will throw an error
	- ![[Pasted image 813.png]]

- parsing JSON
	- old way had security issues, now we use `JSON.parse`...
		- ![[Pasted image 811.png]]
- converting from an object to JSON
	- `JSON.stringify`
	- [] ![[Pasted image 812.png]]


## Using Ajax
### Fetch and Promises
- ** the new way~~
- Promises in Error Handling doc
- set `getNews()` to be an event listener for a button. within it you will use `fetch()` with a promise for whn the data is retireved, and then call JSON on that data to process it with another promise
	- [] ![[Pasted image 827.png]]
	- [] ![[Pasted image 828.png]]- processing method
- shorthand for ^ ; ![[Pasted image 829.png]]

### Old way - using XML instead of JSON
- [] ![[Pasted image 830.png]], ![[Pasted image 831.png]]
- notice how you need to create a global variable to hold the XML object
- obvsly the processing code is different
- you can nest the functions so that the XML object doesn't need to be a global variable
	- ![[Pasted image 832.png]]