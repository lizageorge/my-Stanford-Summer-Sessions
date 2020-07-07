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
- you can specify what tags you're refering to by 
	- listing them (seperate with commas)
	- or using *descendent selectors* (seperate with spaces)
	- ![[Pasted image 203.png]] the `li` elems only wihtin `ul` will be affect
	- or using *child selectors* (seperated with >) to refer to the immediate children (only!)
		- ![[Pasted image 204.png]]
- you can single out certain elements with
	- `< [elem] class = "[className] .../> "`
		- ![[Pasted image 205.png]]
		- ![[Pasted image 206.png]]
	- `< [elem] id = "[idName] .../> "`
		- ![[Pasted image 209.png]]
	- an id can only be applied to one elem in the webpage - it shows code readers that a property is unique to one elem
- there are two HTML tags that are used specifially to help format more specifically within elements
	- `span` (for in-line)
		- ![[Pasted image 207.png]]
	- `div` (for block-level)
- when selectors class clash, *the most specific rule wins out* and *the last rule wins out*

### importing
- you can import a stylesheet into another style sheet/a style element using `@import`
	- ![[Pasted image 211.png]]
### vars
- you can set basic variables to hold things like color codes like so;
	- ![[Pasted image 212.png]]
### CSS Reset
- when you want to get rid of the standard formating from a browser, often used for more complex/professional webpages
- there are two provided for the class


### Measuring scales
- you can use pixels, cms, inches, em's, and x's















