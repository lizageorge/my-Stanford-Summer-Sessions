# Encoding, Compression and Hashing
### August 5,6 2020 - day 26-27

## Lossless compression
- we would compress a string/askii character using a prefix coding scheme, that coding scheme can be represented in a tree!
	- ![[Pasted image 767.png]]
- To creat that prefix coding scheme...

### Huffman algorithm
- Hoffman algorithm is a way to minimally compress the string
	- steps
		- 1. create a frequency table
		- 2. initialize a priority queue and fill it with a leaf node for each character in the original character with a weight corresponding to how often it appeared
			- ![[Pasted image 768.png]]
		- 3. dequeue the first and second elements in the queue, then create a new null value tree node that has those two elements as the two children, and its own weight will be the sum of the two children's weight. then insert this node back into the priority queue
			- ![[Pasted image 769.png]]
		- 4. repeat until the priority queue is empty and there's your optimal coding scheme! Now the code for each character is equal to the path from the root to that leaf node
			- ![[Pasted image 771.png]]
		- we're building up the tree 'bottom up' so that low-frequency-character nodes are lower in the tree and thus have longer paths
- here's the same algorithm again: 
	- ![[Pasted image 772.png]]
- to decompress a coding scheme, the tree must be given with the string. so sometimes it takes up more data to send the encoding tree and compressed string than it would be it you just sent the uncompressed string
	- -> it is impossible to create a perfect compression algorithm


- one more example
	- the string "MEMES" would have 
		- the priority queue
			- {{'S', 1} {'!', 1}, {'M', 2} {'E', 2}}
			- {{"", left->'S', right->'!'} 2}, {'M', 2} {'E', 2}}
			- { { {"", left->{"", left->'S', right->'!'}, right->'M'}, 4},{'E', 2}}
			- { { {"", left->{"", left->{"", left->'S', right->'!'}, right->{'E', 2}} , 6} }
		- the tree 
			```
			          *
					/   \
				   *    'E'
				 /   \
				*    'M'
			  /  \
			'S'  '!'
			```

		- the code 011011000001

- there are multiple valid trees-code combinations for each string based on how priority ties are split


## Hashing
- allows us to have O(1) lookup on ADTs while still using a fixed amount of space (as opposed to like some endlss array)
- **hash functions** take in arbitrary inputs and outputs a value(hash value/code) of a *fixed size/length*
	- must be deterministic (same outputs for same inputs)
	- two different inputs will (usually) produce different outputs
- we don't normally design our own hash functions, we use prexisting functions


### Hashtables - Hashsets and Hashmaps
- ADTs that use hashtables to organize data
	- ![[Pasted image 773.png]]
- these are preferable for efficiency, but the one benefit of regular tree-based sets and maps are that they're automatically ordered
- **hashtables**
	- think of a hashtable like a chest of drawers (buckets), where each object has a designated drawer (determined by the hash function)
	- ![[Pasted image 774.png]] so "urania" will go to bucket 2. Now for lookup, just find that bucket number again and traverse through the ADT within that bucket
		- ![[Pasted image 775.png]]

- if we use a *strong* hash function (distributes elements among buckets evenly), then the efficiency is
	- ![[Pasted image 776.png]]
	- we call `n/b` the load factor `\alpha`. If it gets too big, the buckets will be large and slow, if it's too big, there will be too many buckets that take too much space
	- so if `\alpha` is a weird size (we will make thresholds), we will rehash the values and repopulate a different sized hash table
		- ![[Pasted image 777.png]] 
- **collisions** = when two or more elements end up in  the same bucket. We handle this with **chaining** where we connect the elements through a linked list

- **Implenting a Hashset**
	- ![[Pasted image 778.png]] rehash will handle when `\alpha` breaches a threshold. That double point syntax (`Hasnode**`) is an array of pointers
	- ![[Pasted image 784.png]] - this insertion function has O(1)! It handles collisions by adding to the beginning of the linked list/chaining it on
	- ![[Pasted image 781.png]] - this traveral function is just O(1) if the buckets have <=2 elements in average!
		- same for the clear function :![[Pasted image 782.png]]
	- the rehash function is very similar to the priority queue expansion method
		- ![[Pasted image 783.png]]
		- remember, all the traversals with short runtimes rely on the load factor being small enough 
	- (full code was published after lecture) 


### Other uses for hashing
- when external services store a password
- (cryptography) for secure and encoded communications and data tampering checkings





















