# JS - Events
### July 19, 20 2020, lecture 6

- these lectures (6-7) will go into more detail on how exactly to use different js features than the last one. this one will probably be more useful as a reference


## Event Handlers
- modern method = using .addEventListener on elements in js
	- `.addeventListener("eventName", eventHandlerFunction, (opt)false)`
		- `eventHandlerFunction` can be the function name, the var holding a function literal, or an arrow funtion
		- the `false` is for older browsers that expect it, but it's also used to differentiate what elements are in the bubbling/capture phases (look below)
- old methods 
	- = providing function definition within the html element tag itself
		- ![[Pasted image 510.png]]
	- = using a property of an object designated for an event in js
		- ![[Pasted image 511.png]] 
		
## The Event Triggers
- `"click"` - works on just about any html element that can be clicked
- `mouseOver, mouseOut` - changes based on position of mouse, more functionallity than css :hover. Not supported on mobile, ovsly
	- ![[Pasted image 516.png]]
- `submit` - useful for when you want a user to know they didn't fill in an input correctly without having to check against the server	
	- you can also do smth like this:![[Pasted image 518.png]]
- `change` - when a select tag is changed (most widely supported for this), when a text input is changed, etc. and you want immediate response
	- ![[Pasted image 519.png]]
- `load, unload` - when the body of the DOM finished loading
	- ![[Pasted image 517.png]] (it's tricky to place the script correctly, cause you're not allowed to put things after the body end tag. this might work without the onLoad if you include `defer` in the script link)
	- most browsers block unLoad bc ppl were taking advantage of it for malicious advertising
- `keypress` - when anything is typed out by the user at all, again called on the dom as a whole
	- ![[Pasted image 520.png]]
- `contextMenu` - lets you arrange what happens when the mouse right-clicks/whatver the gesture for bringing up the context menu
	- ![[Pasted image 523.png]]
- preloading = when you want to load up the resources the page will use later (say the images in a slidedeck) right when the page loads, you should assign all of them to a src variable initially (lecture *6* example)
	- ![[Pasted image 550.png]]
	- ![[Pasted image 552.png]] you have to use this imageArray global variable so that the js garbarge collector doesn't delete those images

## The Event Object
- when you use an eventHandler on `addEventListener`, that function is passed in the event *object* that contains a bunch of info about that event
- [] ![[Pasted image 521.png]]
	- "keypress" will include what keys were pressed, and if shift/alt/control were pressed too
- [] ![[Pasted image 522.png]] (the display of the example)
	- "click" will include the coordinates of the click in terms of the webpage and the actual client computer screen
	- only firefox will do this for right clicks, on other browsers you need "mouseDown" event 
- [] ![[Pasted image 524.png]]
- three parts of every event object
	- **target** = what element triggered the event? (like where did the mouse go?)
	- **related target** = (sometimes doesn't exist) smth related to the event occuring (like what the mouse was on before)
	- **current target** = the element containing this event handling (how to differentiate among elements with listereners for the same event, when a nested element's handler is called:	  )
		- *bubbling phase*  = when an event handler from the child element is activated, and the event is handed up to the parent elements (inside->out)
		- *capture phase* = when the parent handler is called first, and the event is passed down (add called) to the child listener methods
		- if you want either chain to end, you can use `stopPropogation`
		- if you want some handlers to go through capture phase and some in bubbling phase, you change the boolean at the end of the .addListenerMethod accordingly
- most of the time, multiple event handlers can be added to one object
	- you can change this by adding stopPropogation onto one of those elements, it stops new handlers being added
		- ![[Pasted image 525.png]]


## Object Selector
- `querySelector()`![[Pasted image 513.png]],  ![[Pasted image 514.png]] or ![[Pasted image 515.png]]





