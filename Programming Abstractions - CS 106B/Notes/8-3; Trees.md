# Trees
### August 3,4 2020 - day 24-25

- Basically a linked list, but organized into a tree structure
- Relinking lists into trees to make traversal shorter than O(n)



## Trees in general
- trees have many uses
	- decision trees for recursive algorithms
	- file structures/html DOM tree
	- heirarchies
- trees are inherenetly recursive!
- **tree** = a hierarchical data organization structure composed of a root node connected to zero or more non-empty sub-trees
- we can 'create' a tree with linked nodes by connecting parets to children, where the leaf nodes point to null
	- ![[Pasted image 754.png]]
- **paths** = linked list from a parent to a child
	- depth = length of path from the node to the root node (root node has depth of zero)
	- height = number of levels a tree has/greatest depth +1

## Implementing Trees with LinkedLists
- now for traveral to *any* node in the tree, you only have to traverse through the *depth*, not the every single node. So the longest possible path in a search tree has a length equal to the height, finding any node in the tree has O(height) = O(log n). 
- usually in code we work with binary trees, to make it easier to represent and check children (and this branching factor really is enough)
	- so our treenode struct will have pointers for left and right children
- ![[Pasted image 755.png]]

- there are three different ways to traverse a tree:
### Pre-Order Traversal
- three steps:
	- do smth with curr
	- pre-order traverse the left subtree
	- pre-order traverse the right subtree
- in the above example, if "do smth" was printing the node's value, we would get {pineapple, coconut, banana, durian, strawberry, taro} 
- ![[Pasted image 757.png]]
- this is like the default way to traverse a tree
### In-Order Traversal
- three steps:
	- pre-order traverse the left subtree
	- do smth with curr
	- pre-order traverse the right subtree
- in the above example, if "do smth" was printing the node's value, we would get {banana, coconut, durian, pineapple, strawberry, taro} 
- ![[Pasted image 758.png]]
- this is the best way to go through things 'in order' in a BST (bc it's already sorted)
### Post-Order Traversal
- three steps:
	- pre-order traverse the left subtree
	- pre-order traverse the right subtree
	- do smth with curr
- in the above example, if "do smth" was printing the node's value, we would get {banana, durian, coconut, taro, strawberry, pineapple} 
- ![[Pasted image 759.png]]
- this is the best way to free/deallocate trees


## Data Organization with Trees
### Binary Search Tree
- a binary tree is constructed to that the left child always has elements with smaller value than the parent, and the right child has elements with greater values 
	- ![[Pasted image 760.png]]
- again, remember that the path to any node from the parent is **O(log n)
- to check if a value is in the tree...
	- check each child node and compare to the search value to decide which path to go on, recursively!
	- ![[Pasted image 761.png]] 
- to find the largest value, keep going right until you hit null
- to create an *optimal* BST
	- by optimal we mean one that has the *median* of the data set as the root node, and is *balanced* = it's height is equal to O(log n) (the left and right subtrees have lengths that are no more than one apart)
		- finding the median of a dataset efficiently won't be covered in this class T^T
	- this is a valid but very not-optimal tree;
		- ![[Pasted image 762.png]]
	- there are actually such a thing as a *self-balancing BST* (red-black trees, AVTs, but its out of the scope of this class)
- unordered ADTs like Stanford's Set and Map are implemented with trees

#### Implementing OurSet with a BST
- public interface:
	- ![[Pasted image 763.png]]
- we'll have private `int numItems` and `TreeNode* root` variables, and a private `freeTree` helper function
- make sure the destructor fully deallocates the tree (call freeTree (uses post-order traveral) on the root not). `clear` should also deallocate the tree, and reset the member variables
- `contains`
	- ![[Pasted image 764.png]]
- `add` is very similar, a search but also add an element
	- ![[Pasted image 766.png]]
	- notice that we implicitly not add any duplicates to the tree
	- you only ever have to add to the leaves, never rearrange the middle of the tree
- there's a remove function in the lecture code the more complicated rewiring processes
- on a balanced tree, all of these functions would have an O(log n) runtime!

### Lossless compression and the Hoffman algorithms
- we would compress a string/askii character using a prefix coding scheme, that coding scheme can be represented in a tree!
	- ![[Pasted image 767.png]]
- To creat that prefix coding scheme...
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

- to decompress a coding scheme, the tree must be given with the string. so sometimes it takes up more data to send the encoding tree and compressed string than it would be it you just sent the uncompressed string
	- -> it is impossible to create a perfect compression algorithm












