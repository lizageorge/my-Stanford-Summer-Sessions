# Intro to Javascript
### July 14, 2020, lecture 5

## The Javascript Programming Language

### Javascript Uses
- JS is *the* client-side programming language, most common use of JS (there are dozens of languages for server-side, but basically just one for client-side)
	- client-side alternative languages
		- java is supported on most modern browsers, but its a huge security risk
		- most other languages are translated into JS through a **transcompiler**
			- Typescript (JS isn't a typed language, TS requires type on JS)
			- Dart (a language from google, allows classes)
			- Coffeescript 
- There are libraries and frameworks that are build on top of JS 
	- JQuery - designed to handle the differences between browsers (this issue was much worse a few years ago when IE was super different, nowadays not as popular)
	- React, Angular, Vue - ways to simplify your workflow (make sure to only use a framework that follows the way your project views the world, or its not worth it!) React it a way to define your own HTML tags to work with
	- Web Assembly - an assembly language (smth that's basically a readable version of machine code) that you can convert your files into, newly coming 
	- asm.js - a subset of js, can help with efficiency too (not supported by apple for whatever reason)
- you can use JS outside of the browser 
	- like using Node.js or 
	- Electron allows you to use HTML/CSS/JS to create stand-alone apps
	- there are some people thinking to make mobile programs using web languages
	- you can also use js interpreters (like v8) to build in scripting capabilities to outside applications

### History of JS
ok im skipping this for now, i'll come to it later
30:30 - 45:00


### JS as a Language
- Things about JS that suck
	- there aren't any amazing debuggers, just browsers that weren't designed for development. Errors only show up in the console, 
	- Error are not always very clear, and could come from just about anywhere (HTML/CSS/JS)
	- especially bc JS is very flexible	
		- not typed language
		- doesn't catch when function calls with incorrect/missing/extra parameters
	- JS was designed for small, short programs, not huge projects
- Differences between JS and c-based languages
	- no typing. you define vars with `var`, not a specific types (same for return types)
	- variable declaration isn't even required unless you set it to be stricter (most industries require linters to auto-restrict some things like this)
		- this is how you set a page to strict; ![[Pasted image 476.png]]
	- `Nan` = not a number (`3/'stanford' = NaN)`, `undefined` = var never defined
	- just a general number type (no longs/floating point seperate vars)
		- so there will be some weird rounding errors bc of weird binary-floating conversions 
	- function just has a global scope and function scope
		- ![[Pasted image 464.png]] x can be accessed outside the for loop
		- [ ] check if this applies to the iterating var
		- ecma script 6, `let` creates block scoped vars like you're used to
	- interpretted, not complied language (so you can just plop code anywhere, outside of functions) (but most modern versions use smth called adjusted time compiler to help with efficiency)
	- some people use `===` instead of `==` bc it doesn't allow for type conversion (so `0===0.0` will return false) (same for `!=` vs `!==`). the rules for types conversion gets messy fast, so this is useful
	- strings
		- you can define strings with `""` or `''`, there's no difference.
		- there's no separte char type
		- strings are immutable, which can hurt efficiency
		- bc of the typse issue, string concattination can get tricky (so always use `parseInt\parseFloat`)
		- string templates allow inside-y code (check old js notes)
	- convention for naming is lowercase camelcase for vars, uppercase for object-based things
	- you can have *standalone* functions, and they don't have return types, and params don't have set types
		- ![[Pasted image 465.png]]
	- you can also define and store functions into vars
		- ![[Pasted image 471.png]]
	- you can declare *objects* very easily, like c++ structs. They're basically just key-value pairs
		- ![[Pasted image 466.png]]
		- aren't strictly defined, which can lead to accidents and errors; ![[Pasted image 467.png]]


## Javascript in the Web Browser

- you can just insert js into your HTML page 
	- one way is with the `script` tag
		- ![[Pasted image 468.png]]
	- old  way of adding event listeners
		- ![[Pasted image 469.png]]
		- but this is how event listeners are made now; ![[Pasted image 470.png]] (notice that the script tag has to be written below the buton)
- you can link an external js file into your HTML file using the `script` tag too
	- ![[Pasted image 473.png]]
	- `defer` tells the browser to only start executing the js once the entire page has loaded
	- make sure your script tag is still at the end of the body tag!

### The Document Object Model
- = the interactions between the browser and js 
- technically every single html element has a corresponding object that you can access from js. 
	- this an example of the *tree* of the html elements; ![[Pasted image 472.png]]
	- so if you want to access an element, you could do it by traversing this tree (but it's more common to use ids)
- you access the DOM/tree using the `document.` object that's created everytime a webpage is loaded and contains an element for every HTML element
	- `document.title` lets you access and change the document's title property
	- `document.getElementById()` lets you access and change an element by its id
	- ![[Pasted image 474.png]]
	- accessing form elements;
		- convert.js example
		- ![[Pasted image 475.png]]
		- the event handler mthod ctof access the `input` elements from the HTML page by unique ids and the `.value` keyword (that's the `value` attribute on text-type inputs!). you can use .value to both access and edit the value attribute
			- checkboxes use `checked` instead; ![[Pasted image 478.png]]
			- for radio buttons, you use the form name, find the set of radio buttons (by each input element's name) and the `.value` of that set
				- ![[Pasted image 480.png]]
				- same thing for the `select` elements (drop-down menues), but you can also use `selectedIndex` instead if you want to 
		- convert from strings by convention
		- honestly should have included `var` declarations ![[Pasted image 477.png]]
		- if you used a `form`, each input is actually a property of that form. So you can just use the `.name` property of each input instead of having to use an id (`formName.name`)
			- ![[Pasted image 479.png]]
	- accessing an image
		- you can just use `document.getElementById()` to access the image, and change things like `src`
		- ![[Pasted image 481.png]]
 












