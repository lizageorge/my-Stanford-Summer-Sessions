# Node
### August 12, 2020 - lecture 12

- one of the libraries built on top of JS
- a standalone runtime environment that runs JS, can be used for to run serverside js on an application


## Using node
- always use the *longterm support version*, not the newest version
- you can just run it on the console to use as an JS interpretter
	- ![[Pasted image 890.png]]
- or you can start running an external js file from the console too
	- ![[Pasted image 891.png]]

### Node Modules
- for the longest time JS didn't have seperated namespaces (so the whole webpage would share variables), which made group work very difficult
- one solution was **node modules**
- you can install standard node-modules like this;
	- ![[Pasted image 892.png]]
#### NPM (originially node package manager)
- how you can use other ppl's modules that have been loaded onto this shared library of ppl's node modules
	- [] install the package first, (`npm install lodash`) through console, and then ![[Pasted image 898.png]]
	- careful abt what you install and use! stick to popular modules 

### Synchronous and Assynchronouse node
- node can let you work with multiple threads, which JS didn't have for the longest time. you can pick between sync and assync node code 
- assync work is very common. remember otherwise, if any one function takes a long time everything else - including event handling - is on pause
- [] synch; ![[Pasted image 896.png]] (prints "example is a file first") vs assynch ![[Pasted image 897.png]] (prints "we're done" first)

### Node as a web server
- this way is p uncommon
	- [] ![[Pasted image 899.png]] ->![[Pasted image 900.png]]
	- [] ![[Pasted image 901.png]] -> ![[Pasted image 902.png]]
- `express` makes it easier for static pages, bc it checks to see if the user's computer already includes the intended file and display that if it can
	- ![[Pasted image 903.png]]