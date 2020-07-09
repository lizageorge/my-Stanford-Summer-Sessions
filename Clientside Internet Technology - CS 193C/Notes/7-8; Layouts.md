# Layouts
### July 8, 2020, lecture 3

(skimming!)

### Fixed Layout vs. Liquid Layout
- Liquid = the elems will expand out to take whole space available (p rare, only used for banners and stuff like that)
- fixed = widths are specified

## Table-Based Layout (Historic)
- just using regular table strucure to make a layout
	- [] ![[Pasted image 304.png]]
- violates the semantics-styling divide
- nesting tables has a limit to the number of levels of nesting you can have


## Float-Based Layout
- most common today, works on *any* modern web browser
- just using the `float` css property on elems other than images
	- []![[Pasted image 305.png]]
	- [] ![[Pasted image 306.png]] (you have to provide widths for elemes that don't have native widths, like text)
- if you have multiple things floating, they act like layout columns
	- ![[Pasted image 308.png]]
	- ![[Pasted image 309.png]]
- it's easier to use divs for this (but again, define the width)
- use classes to seperate out your elems into things with similar styles
	- ![[Pasted image 311.png]], ![[Pasted image 312.png]]
- float by default will collapse items as the window shrinks, which could mess up your layout
	- fix by setting the width of the body to the sum of your items (minus the margins)
		- []![[Pasted image 313.png]]
	- or use a div to hold all of your content and style that 
		- []![[Pasted image 314.png]]
	- to arrange things into horizontal sections, split your content into divs and stack that
		- if you want to avoid bottom elements floating up to blank space, 
			- either use this is fix;
				- ![[Pasted image 315.png]]
			- or add an 'end-panel' elem at the end of your panel div and set it to not allow floating next to it
				- ![[Pasted image 317.png]]
				- ![[Pasted image 316.png]]
				- ![[Pasted image 318.png]]
- you can make very complex layouts using a *bunch* of nested divs
	- ![[Pasted image 319.png]]


## Flexbox
- prof doesn't like it T^T
	- originally made to be used *alongside* grid. Grid was supposed layout the whole page, and flexbox was meant to layout smaller sections
	- but ppl started using it to layout the entire page
- css-tricks.com
- flex works by setting one div to be the "container". if that div is styled with `display: flex` property, then all of its immediate children will flow based on specified properties
	- ![[Pasted image 320.png]]
- useful for responsive layouts
- useful for ordering
- useful for nice formatting


## Grid Layout
- prof's recommendation
- unfortunately has a kinda low support on browsers, still majority of modern ones do (pick a layout choice based on your inteded audience)

- grid works when you have a parent element with `display: grid`. then you apply your template and assign starts and ends for the children
	- ![[Pasted image 321.png]]
	- ![[Pasted image 322.png]] or ![[Pasted image 323.png]]
- if you use the `fr` property, you can split up the display so widths change responsively
	- ![[Pasted image 324.png]] will have one column fixed and the other two divide up remaining space
- you can use `repeat(iteration, elem)` to avoid repeating the template defining over and over again
	- ![[Pasted image 328.png]]
- the `auto` property sets a row height to change based on how much content is in it
	- ![[Pasted image 325.png]]
	- you can also use `overflow:hidden` to hide any content that exceeds a fixed height
		- ![[Pasted image 326.png]]
- if you want some extra spacing between columns (equivalent to margin), you can use the gap property
	- ![[Pasted image 327.png]] 
- benefits of grid
	- very similar to table-based layout, but the styling is in the css styling, not in semantic html. so it can be dynamic/responsive!	









(1:16, right when the break starts)









