# HTML and CSS
###  July 6, 2020 - lecure 1, 2

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

### the version we use
- *XML* = extensible markup language, a standard of how different markup languages can be written (languages like svg, chemical markup language) so different tools can be used on new languages
	- we will be using *XHTML*, which has more specific rules than regular HTML ([] case-sensitive, put every attribute value in quotes, you can't leave out end tags)
- the current standard version of HTML is HTML5 (as per W3 Consortium), but the web browsers consortium (WHATWG) just call it without the version name...they say it's a "living standard"
	- so now, when specifying doctype, just include "html"
	- sometimes the two standards disagree...so just always check the specs

- starting your build;
	- ![[Pasted image 201.png]] the details you should include
		- again, doctype is needed bc of browsers like edge still require the element, but you don't have to include a version number
		- charset is needed incase you're dealing with more than just english characters. most of the time UTF-8 is enough
		- title is the name of the tab displayed at top of browser
- **validator** = a tool we can use to check if html files pass the rules of newest standard
	- you should do this in addition to testing on a variety of web browsers
	- check any new features against caniuse.com


## CCC
- CCC (cascading style sheets) is used to present information
- some people believe that HTML should be used purely for semantic info and CSS should be used for presnetational info. So they use `<strong>` instead of bolding, and `<em>` instead of italicisizing. This makes it easier to update styling.


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

