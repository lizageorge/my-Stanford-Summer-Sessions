# Trees
### August 3 2020 - day 24

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
- this is the best way to go through things 'in order' (more on why this works tmrw...)

### Post-Order Traversal
- three steps:
	- pre-order traverse the left subtree
	- pre-order traverse the right subtree
	- do smth with curr
- in the above example, if "do smth" was printing the node's value, we would get {banana, durian, coconut, taro, strawberry, pineapple} 
- ![[Pasted image 759.png]]
- this is the best way to free/deallocate trees



