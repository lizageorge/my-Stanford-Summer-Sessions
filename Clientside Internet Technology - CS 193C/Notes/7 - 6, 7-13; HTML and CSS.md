# HTML and CSS
###  July 6, 13 2020 - lecure 1, 2, 4

## The basics of HTML
- **tags** = are used to select certain blocks of text to apply certain properties to them
	- two types;
		- *in-line tags* = provides information about specific text, small ([] `i, b`)
		- *block-level* = provides information to create blocks of text on your page ([] `h1, h2, p`). 
			- you can nest in-line tags within blocks (not the other way around)
			- you can nest *some* block tags within other blocks = **flow** ([] `td` (table cell), [/] `h1`)
		- html5 added a bunch of extra categories, but we can just use those two (other libraries and JS just deal with two)
			- ![[Pasted image 200.png]]
		- (unoficial) *file level* = structuring the page ([] `head, body`)
- **elements** = the start and end tags combined with their context
	- [] `<i>Go Stanford!</i>`
	- there are some tags without required end tags
		- ![[Pasted image 199.png]] (the top example is the XHTML standard)
- **attributes** = some tags have additional information in them called attributes
	- []`<a href = "http://www.stanford.edu"> To Stanford </a>`
- HTML5 includes some new tags (header, footer, nav, etc.) that basically just act as divs, they just semantically hint to the reader of your code what the purpose of that elem is, and can also help things like readers and the google bot
- there are also some new tags to easily add *audio and video*
	- ![[Pasted image 397.png]]
	- ![[Pasted image 398.png]]
	- you can list muliple sources in case a browser doesn't support one of them

### the version we use
- *XML* = extensible markup language, a standard of how different markup languages can be written (languages like svg, chemical markup language) so different tools can be used on new languages
	- we will be using *XHTML*, which has more specific rules than regular HTML ([] case-sensitive, put every attribute value in quotes, you can't leave out end tags)
- the current standard version of HTML is HTML5 (as per W3 Consortium), but the web browsers consortium (WHATWG) just call it without the version name...they say it's a "living standard"
	- so now, when specifying doctype, just include "html"
	- sometimes the two standards disagree...so just always check the specs

### starting your build;
- ![[Pasted image 201.png]] the details you should include
	- again, doctype is needed bc of browsers like edge still require the element, but you don't have to include a version number
	- charset is needed incase you're dealing with more than just english characters. most of the time UTF-8 is enough
	- title is the name of the tab displayed at top of browser
- **validator** = a tool we can use to check if html files pass the rules of newest standard
	- you should do this in addition to testing on a variety of web browsers
	- check any new features against caniuse.com

### Forms
- *the form element* - any way you accept input from the user. you can have more than one form per page, each should have seperated functionality.
	- when you want to actually do stuff with the form inputs and send it to the web server, include the attributes
		- `action` where you include the location to the program that can accept and do stuff with the input
		- `method` where you specify if the info is sent through the get or post methods
			- any http request can send information through the **get** or **post** methods. 
				- get will submit info through the url (supposed to be *idem potent*, which means that it's not supposed to change anything on the state/server) (use when you want people to be able to bookmark/send the url and save inputted info)
				- method will submit info through the request body (used when you want to actually change the state of the server or change if the state of the server changes )
			- you'll also probably include the `id` attribute
	- `<form action="", method="", id = ""></form>`
- each form can have *form elements* (aka controls/widjets) of different types (text fields, radial buttons, mutli-select buttons, drop down menus)
	- most use the `<input/>` tag and a `type` attribute
		- common types with input
			- `text` (you can now also have a `placeholder` attribute that displays some text in the field that disappears when the user starts typing, instead of just using `value` to have that placeholding value)
			- `checkbox` 
				- ![[Pasted image 385.png]]
			- `radio`-  make sure the mutually exclussive choices that correspond to each other have the same name 
				- ![[Pasted image 386.png]]
			- `submit`/`reset`
				- ![[Pasted image 387.png]]
				- reset will change elems to their preset/default value. you can set that defualt value within each input elem ![[Pasted image 388.png]]
				- submit will submit info to the server
			- `button` (not the button tag - they both kinda do the same thing, but the button tag can have more formatting)
			- there are more added in html5
	- there are other tags too;
		- `select` (for drop-down menus)
			- ![[Pasted image 389.png]]
		- `textare` (for multi-line inputs, you have to preset the size)
			- ![[Pasted image 390.png]]
	- all element tags include the `name` tag to identify the input elem when servers interact with their values
	- for a long time, form elements had to be inside the form tag to work, now you can leave it outside (as long as it's just for client-side/local pages, doesn't actually access a server)
- you can also include a `<label>` tag alongside every form element to include text, and if you click on that text on the page is highlights the corresponding input (the input elem is required to include an id for this)
	- ![[Pasted image 384.png]]
- look at the ski-form example for this lecture for a bunch of examples

### Character Entities
- basically when you insert something into a string that can show a symbol that is not supported by your character set, almost like an escape sequence ([] `&pound;, &euro;, &amp;, &nbsp;` (non-breaking space, use inbetween words that you want to be treated as one word and won't be broken up when the window is resized (`Stanford&nbsp;University` won't ever be on seperate lines)))
- most of those first examples are set in UTF-8, but some things aren't
### Image maps
- when you take an image, and make it so that if a user clicks on certain parts of it, it is linked to a different page
	- []![[Pasted image 391.png]] clicking on each room would take you to a different page
- use the `map` elem to create a map of coordinates
	- ![[Pasted image 392.png]]
- and then just link that map to the image in your page
### iFrames
- including outside webpages into your page with the `<iFrame>` tag
- ![[Pasted image 399.png]]
- specify height and width in css
### Meta Tags
- when you work with other pages on yours
- [] ![[Pasted image 400.png]] - will change the page after 7 seconds
- []![[Pasted image 401.png]] - will refresh the page after 30 minutes


## CSS
- CSS (cascading style sheets) is used to present information
- some people believe that HTML should be used purely for *semantic* info and CSS should be used for *presentational* info. So they use `<strong>` instead of bolding, and `<em>` instead of italicisizing. This makes it easier to update styling.


- using CSS within an HTML file
	- you can use the `style` HTML tag to insert CSS into an html file
	- ![[Pasted image 202.png]]
- using a seperate stylesheet
	- use an `href` in an html file to link an external stylesheet, be sure to include the `rel="stlyesheet"`
	- ![[Pasted image 210.png]]
	- (the link tag used to be used for other purposes too, but those have been discarded by most web browsers. still, you have to specify the type now)
- there are some rules to follow on when to use seperate stylesheets and when to use internal styling


### Selectors
- the part of a CSS rule that *selects* what part of the html file a property applies to 
- (i'm not including every type of selectors here, this is all review)
- you can include an *html tag* (`h1 {color:red;}`)
- you can *specify what tags* you're refering to by 
	- listing them (seperate with commas)
	- or using *descendent selectors* (seperate with spaces)
	- ![[Pasted image 203.png]] the `li` elems only wihtin `ul` will be affect
	- or using *child selectors* (seperated with >) to refer to the immediate children (only!)
		- ![[Pasted image 204.png]]
- you can *single out specific elements* with
	- `< [elem] class = "[className] .../> "`
		- ![[Pasted image 205.png]]
		- ![[Pasted image 206.png]]
	- `< [elem] id = "[idName] .../> "`
		- ![[Pasted image 209.png]]
	- an id can only be applied to one elem in the webpage - it shows code readers that a property is unique to one elem
- *psuedoelements*
	- can single out certain parts of the html elements, act as if they're a seperate element. uses `::`
	- [] ![[Pasted image 248.png]] will affect the first letter of every para
	- [] first-line, even/odd listed elements, etc.
- *psuedoclass*
	- can affect elements with certain properties, as if those html elements have a seperate class. uses`:
	- []![[Pasted image 249.png]]
	- [] visited, hover, etc.
- there are two HTML tags that are used specifially to help format more specifically within elements
	- `span` (for in-line)
		- ![[Pasted image 207.png]]
	- `div` (for block-level)
- when selectors class clash, *the most specific rule wins out* and *the last rule wins out*

### properties
- font (pts, inchs, em's, x's, small, medium, large, x-large, bigger, smaller, etc.), size, weight	
- text propertires (line spacing, word spacing, letter spacing, allignments)
	- text decorations (underline, strikethrough)
- classification properties (numbering symbols (numbers, roman numberals, custom bullet images))
- color and background
- positioning (float)
- box properties (padding, border (color, width, style) , margin (for all - bottom/top/right/left))
	- []![[Pasted image 254.png]]

### more CSS features
- importing
	- you can import a stylesheet into another style sheet/a style element using `@import`
		- ![[Pasted image 211.png]]
- vars
	- you can set basic variables to hold things like color codes like so;
		- ![[Pasted image 212.png]]
- CSS Reset
	- when you want to get rid of the standard formating from a browser, often used for more complex/professional webpages
	- there are two provided for the class
- Measuring scales
	- you can use pixels, cms, inches, em's, and x's
- tranformations
	- you can take elements and skew or rotate them
	- ![[Pasted image 394.png]]
- animations
	- you can have animations (that start without triggers) using just css
	- ![[Pasted image 395.png]]

### versioning
- the last official version of CSS was 2.1, version 3 has a whole bunch of extra properties that are in process of being approved
- caniuse.com


## Linking
- on your html page, you can use the `a` tag
	- two types
		- **absolute reference** - specify exactly how to get to a website (protocol, full site)
			- ![[Pasted image 246.png]]
			- used (needed) for linking to external website
			- there are some other refs (mail to? aim, geo) in addition to http and https, but they're not very common
		- **relative reference** - specify just a file name, assume it's located same space as current (or use ./ to move around folder structure)
			- [] ![[Pasted image 247.png]]
			- used for linking to own website (less text, smaller file), easier to move all your files around together
	-  using psuedoclasses and psuedoelements to control link colour by whether or not already visited
- you can link within a page using id's
	- [] ![[Pasted image 250.png]]


## Images
- seperate files from the html and css
- link to the file from your html page using the `img` tag (the alt attribute is always require)
	- ![[Pasted image 252.png]]
- you can edit the image through css
	- []![[Pasted image 253.png]]
	- it's not recommended cause the deformation can ruin image
	- but recommended to provide a height and width for the image so that loading of the webpage (while the image takes longer to load) will look smoother
	- there's a new tag called `picture`, more for responsive design, but `img` works too

- file formats
	- JPEG: good for photographs, esp smaller ones
	- PNG: good for diagrams, logos (reduces the size of file by looking for repeated patters)
	- GIF: can be animated, low resolution

- sprites
	- using the `background-position` property to change what part of an image is displayed. this allows you to reduce the number of files requested for the images on a page
	- ![[Pasted image 256.png]], ![[Pasted image 255.png]]
- you can also convert your image to *base-64* (there are converters online) and use that on `src` so you don't have to load an external image file at all (better for smaller files, first visits)
	- ![[Pasted image 257.png]]

- SVG = scalable vector graphics
	- and XML language that allows you to create and display vector graphics
	- stick it into a page with the `svg` tag
		- ![[Pasted image 396.png]]
	- take up less space than pixelated images, and resizes nicely

## Colours
- **24-bit colour**, supportd by most modern computers, can be represented in red-green-blue numbers (0-255). Can make ~16.7 million different colours
	- hdr can go from -1053 or smth
- **alpha** = transparency/opacity setting of a colour of an element (0-255) 
	- colour + transparency = **32-bit colour/RGBA**
- defining colours
	- there are ~214 predefined colours with string-value colours
	- you can specify rbg values (`rgb(r, g, b)`) or rgba (`rgba(r, g, b, a`)
	- or specify rgb values through hex values (`#rrggbb`- each pair of digits corresponds to 8 bits (left-most in the pair is the most significant digit), or one byte for one colour). This is most common on the web