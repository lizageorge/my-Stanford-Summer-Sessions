# JS - Selecting Elements
### July 20, 2020, lecture 7

- these lectures (6-7) will go into more detail on how exactly to use different js features than the last one. this one will probably be more useful as a reference

### getElementById is always great, but...
- `getElementsByTagName("htmlTagName")` = returns an "array-like object" with all the html elements of the specified tag
	- ![[Pasted image 558.png]]
- `getElementsByClassName("className")` = again, returns an "array-like object"
	- ![[Pasted image 559.png]]

### Accessing things like on CSS stylesheet
- `querySelector`, `querySelectorAll`
	- ![[Pasted image 560.png]]
	- querySelector will return first matching elem, querySelectorAll will return that "array-like object"
- these are about x2 slow as getElementById

### Accessing the actual Document
- you can use the `documentElement` object
	- ![[Pasted image 562.png]]
- but be careful, bc some browsers add implicit elements (like the table body, or things for accessibility), messing up your indeces

### Working with HTML Attributes
- there are some words and attributes from HTML that you can't use in JS bc they're conserved words. These are replaced with "psuedo words"
	- [] class -> className ![[Pasted image 563.png]] 
- alternatively, you could use `setAttribute` to pass that in as a string
	- ![[Pasted image 564.png]]
- there's also smth called `className` that you can use to edit the classes on an element
	- ![[Pasted image 565.png]]

### Accessing Style Values
- to change the style of an element, use the `.style` property followed by the style property name
	- ![[Pasted image 566.png]]
	- note that you have to convert the property name from the css style to camelCase
- you can also use the `.setProperty()` method to avoid that
	- ![[Pasted image 567.png]]
	
- to access the current values of style attributes, you can use the in-line style attribute and again use the `.style` keyword
	- ![[Pasted image 568.png]]
	- but again, this only works for in-line styles
	- this is another, messier option:
		- ![[Pasted image 569.png]]

### Finding Location of Elems
- you can use `.top`, `.left` from `.style` for the relative positions (compared to the top-left of the webpage)
- `getBountyRect` gives you the absolute position (compared to the top-left of the window)
	- ![[Pasted image 570.png]]

### Modifying the DOM tree
- ** this method was created for IE and adopted by other browsers, but not technically standard
	- ![[Pasted image 571.png]] now the text displayed won't be this string, it will be treated as actual parsed HTML
- to actually add a whole elem to the tree (the old version of edge's solution):...
	- ![[Pasted image 572.png]]
	- just check the assign4 / lec7 files
















