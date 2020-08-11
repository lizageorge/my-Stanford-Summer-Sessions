# High-Performance Website
### August 10, Lecture 11

- the most relevant rules to follow to keep client-side websites efficient! front-end programming changes can make a big differences and are cheap

### Rule #1 - Make fewer HTTP Requests
- the delay to download and display files is no good
- so using CSS Sprites/directly encoding images into html file > downloading mutliple image files
- don't have too many css and js files (combine them after build process)

### Rule #5 - Leave stylesheets on the top
- browsers won't load the page until the stylesheet's loaded

### Rule #6 - Leave JS at the bottom
- browser doesn't have to wait for JS to download to load. you could also use `defer` instead

### Rule #3 - Add an expires header
- tell the web browser that a file only has to be updated after a certain amount of time so that, on a site that's visited frequently, the file can be kept in cache and not re-downloaded

### Rule #8 - Make JS and CSS External
- This seems to disagree with Rule #1, but while it does technically take longer on initial load of a page, for common visits a longer html file would take longer to load than keeping JS and CSS in cache with an expirationg date.

### Rule 4 - G-zip components
- we don't really have much control over this


### Rule 10 - minify JS
- you can reduce the size of the JS file for build by getting rid of whitespace and comments and shorten function/var names (done with minifiers)
- (obfuscators will make duplicating public code harder to reverse engineer - normally paired up with minifiers) 


### Rule #2 - Use a CDN (Content-Delivery Network)
- [] Akamai, CloudFar
- the physical distance between servers can make file loading slower. CDNs keeps servers around the world to make the retrieval much faster
- put things like JS, CSS files, images, etc. (not whole databases for ^ tools)

### Rule #14 - Make Ajax Cachable
- you can put expiration dates on Ajax content too

### Rule #11 - avoid Redirects
- there are a variety of reasons ppl might add redirects, but they make things slower
- "www.stanford.edu/class/193C" is slower than "www.stanford.edu/class/193C/" 