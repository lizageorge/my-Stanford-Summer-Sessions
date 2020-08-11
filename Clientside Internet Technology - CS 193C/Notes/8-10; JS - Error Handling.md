# Error Handlind in JS
### August 10, Lecture 11

- two ways
## 1. Through the DOM
- similar to regular event object
- [] ![[Pasted image 814.png]]
- actually assynchronous

## 2. JS Language's Error Handling
- tryr/catch blocks
- [] ![[Pasted image 815.png]]
- sometimes the error throws back an error object
	- ![[Pasted image 816.png]]
	- helpful on Firefox
- you can create your own error objects too, be careful to be specific for others to catch it
	- [] ![[Pasted image 817.png]]

### Promises
- **promises** = if there's every any delay between data retireval and trying to display that data, this will make sure that delay doesn't freak out a user. this will allow funcitons to pass even after the handlers were 'resolved' (like clicking on a button twice before the first call finished)
- old way;
	- [] ![[Pasted image 818.png]]
- when (smth) happens, execute (this method), if smth happens (handle error)
- you can add multiple promise and error handlers to a single object
- you can create your own promises too
	- [] ![[Pasted image 819.png]]
- using promises;
	- ![[Pasted image 821.png]]
	- .`then` will take as an input that will run once the promise returns a value, and if you want to include a second function for what happens when the promise fails
		- [] ![[Pasted image 822.png]]
	- `.catch()` only cares when the promise rejects
		- [] ![[Pasted image 823.png]]
	- you can *technically* ignore the functionality for handling rejected processes (except in node.js), most browsers just prints an error in the console
	- you can chain on promise methods. a .catch at the end would watch if *any* of the .thens didn't resolve 
		- [] ![[Pasted image 825.png]]
		- you can also use previous .then returns in later ones
			- [] ![[Pasted image 826.png]]
- you can think of promises being in different states; *pending -> settled ->fullfiled/rejected*
- you can use returned objects from promises
	- [] the second promise uses the first one's result ![[Pasted image 824.png]]