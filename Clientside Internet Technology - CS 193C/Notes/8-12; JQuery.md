# JQuery
### August 12, 2020 - lecture 12

- one of the libraries built on top of JS. 
- mainly for client-side development
- had a high/peak a few years ago that lasted like 8 years
- we'll be covering *just* a *teeny weeny* bit of this

### Advantages
- biggest advantage of JQuery was that it bridged differences between different web browsers. this was especially useful when IE was...the odd one out
- it also allowed you get HTML elements by css styling, but now that's part of vanilla JS
### Disadvantages
- some other libraries won't be compatable with it, like Node and React
- in terms of speed, vanilla JS is faster so use it when possible


## Using JQuery
- first you need to load in JQuery file
	- ![[Pasted image 883.png]]
	- there is a way to load this from Google, but usually it would be in the user's cache anyways
- every JQuery line is associated with `$`
	- [] ![[Pasted image 884.png]]
- a JQuery Object is an array-like object that you can access from and write to
	- ![[Pasted image 886.png]]
- chaining together JQuery calls is quite common
	- ![[Pasted image 885.png]] 
- JQuery defaults everything to pizels, so you can set position like `top:100` withou including `px`
- use `.bind()` to add event handlers to an object
	- ![[Pasted image 887.png]]


## Libaries built on top of JQuery UI

### JQuery UI
- you can pick out certain styles and behaviours for different UI elements online, download a custom JS file that creates all that for you, and then implement them into your own code *very* easily
- remember how hard dragging was? yeah this is all you need when using JQuery UI;
	- ![[Pasted image 888.png]]
- all built on top of vanila JS

### Bootstrap
- yeah um...I spent several months on this, back at the beginning of the year
- basically the same thing but with css, and you implement them into HTML elements by modifying class names
- very nice for grid layouts and for responsive design
	- ![[Pasted image 889.png]]
- be careful that if you are making somehting for customers you actually customize the styles at least a little to avoid "the twitter bootstrap look"