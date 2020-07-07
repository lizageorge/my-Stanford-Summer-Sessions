# Intro to Web Programming
### June 23, 2020 - July 6, 2020 - lecture 1

## How the Web Works
- when the web client (computer/a browser surface) enters in a url, the browser fetches a file from a web server.
	- this includes the *html file*, which will request for more files as needed
	- other files that will be transfered incl css files, images/sound, etc.
- the protocol for these exchanges is *http (hypertext transport protocol)* (https is encrypted and certified)


## Programming with the web

### server- vs. client-side programming
- two types of processing
	- **servicer-side programming**
		- the program resides on the server. When an http call is made, the program runs on the server and returns another html file
		- Benefits
			- (security) the program can't be deconstructed by the client
			- (power) high-processing-power tasks can be done on powerful server processes
			- some things *require* continued interactions, like editing a central database ([] like adding things to a cart on amazon)
		- Drawbacks
			- continued interaction requires continued connectivity (there are some html5 processes working around this) and will be slower
			- there's a *huge* range of languages used for server-side  
	- **client-side programming**
		- the program is sent to the client during the first sent and runs there. There is no more sending info back to the server
		- Benefits
			- (security) for the client, no risk of sensitive info leaks
			- (costs) no need to pay for processing power for the server
			- *key factor* no continued interaction, is faster response times and smoother UI. ([] imagine panning across a map if every motion needed another web request...)
		- Drawbacks
			- basically just use vanilla js (not really a dealbreaker when making a corporate product) 
			- might require a large initial download
	- pick and choose which method to use based on your particular circumstances
	- these two processes can be combined. [] Using Amazon; inputting-checks for inputting credit card numbers happens on the client-side. But when submitting an order, you have to  interact with the server

### single-page applications
- instead of webpages being replaced with every html call, with SPA a JS program interacts with the server (not the webpage), gets data (not new html files!), and then updates the single webpage 

## Displaying the Web
- **HTTP** = the protocol used to communicate between two computers on the web, to exchange file([] how i signal what type a file is, what kind of error codes we use, etc.)
- **HTML** (hypertext markup language) = the standard used to represent the most important information on a page
	- there are other standards (cascading style sheets, etc.)
	- *hypertext* = how information is organized non-linearly, through a web
		- [] encyclopedias are organized linearly - alphabetically only. information of related concepts could be very far apart in the encyclopedia, but using a *web* can connected all sorts of related informations
	- *markup* = how formating is organized onto a text (so-and-so para will have x size, y font, another title will have z side, etc.)
- browsers use two standardizations to display webpages; *HTML* and *CSS*
	- HTML is used to structure information
	- CSS is used to style information
 




























