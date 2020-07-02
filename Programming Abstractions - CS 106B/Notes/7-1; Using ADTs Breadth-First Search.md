# Using ADTs: Breadth-First Search
### August 1, 2020 - day 7

## Sorting algorithms
- **Counting Sort**
	- = iterate through an ordered ADT (of any kind), and keep a tally of how many times each unique elem appears. Then return a new ordered ADT with every unique elem inserted the right number of times, in order.
	- [] to alphabetically sort a word, count the number of times each letter appears, and then generate a new string where for every letter in the alphabet, you insert the letter the right number of times (the tally corresponding to the letter from the word)
		- ![[Pasted image 144.png]]
		- ![[Pasted image 145.png]]


- **Breadth-first Search**
	- = we organize a search from the simplest "length" upwards 
	- all the data we need to keep track of...
		- keep track of each (partial) path --- ideal ADT = *stacks*
			- need to easily access the "lates" elem
		- keep track of all paths, which haven't been followed yet --- ideal ADT = *queue*
			- need to sort the paths by length (you will only see the longest (and thus newly added) paths at the end. As part of the algorithm, you will add newly generated paths to the *end* of the queue)
		- keep track of nodes previously visited --- ideal ADT = *sets*
			- need to search very quickly, don't need to store repeats
	- word ladder problem;
		- [] working with word ladders, the simplest ladder would be when the starting and ending words are adjacent - one rung away. For anything that's two rungs away, we start by thinking of every path from zero->one rungs, see if anything matches, if not look at all paths from one->two rungs, etc.
		- [] ![[Pasted image 146.png]]
		- be sure to never keep track of any changes that revisit a previously visited word (so keep track of all visible words) ([] no path from 'mop' to 'map' or 'man')
		- keep track of the path used to far for final answer
		- full psuedocode;
			- ![[Pasted image 147.png]]


##  Nesting Data Structures
- putting any ADTs inside other ADTs
- can help with organizing very complex data
- [] keeping a queue of stacks to keep track of the paths in BFS
- accessing elements within nested ADTs (watch out for working with references vs. with copies)
	- you can access the reference of the nested ADT with *square-bracket notation*, and edit that
		- ![[Pasted image 148.png]]
	- if you use the *equals operator* you always recieve a reference to the nested ADT. So if you're working with a variable assigned using equals signs, be sure to reassign that back into the ADTS
		- ![[Pasted image 149.png]]
	