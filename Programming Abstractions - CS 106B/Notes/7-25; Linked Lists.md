# Linked Lists
### July 25, 27,28 2020 - day 20-22

- how we can organize memory *non-contigously* (not in arrays)
- again, we use pointers to organize computer memor
	- ![[Pasted image 664.png]]

- **linked list** = a series of nodes that each has a piece of data and  a'link'(a pointer to another node). The last node points to nullptr
	- ![[Pasted image 665.png]]
	- the Node struct
		- ![[Pasted image 666.png]] (this structure is almost defined recursively! but the compiler is fine here bc you're only using the Node* type in this definition, not Node itself)
- benefits
	- more flexible than arrays bc not contiguous
		- easier to rearrange and remove/insert from the middle
	- never have that massive copy step like when resizing arrays 
- creating a node
	- ![[Pasted image 667.png]] (using the dereferencer)
	- you can also use the `->` arrow notation, which combines the derefencing and accessing steps
		- ![[Pasted image 668.png]]

- linked lists can be used in classes (like the myStack example ADT) or"standalone"

## Linked List Operations
 (more from lecture 19)

### Rewiring
- [] implementing a stack using linked lists
	- keep a pointer variable as a member variable keeping the 'top' of the stack. the linked list will add downwards
	- header file; 
		- ![[Pasted image 669.png]]
	- **common error - rewiring a pointer before handling the data that was originally pointing to**
		- be really careful when rewiring. you don't want to just change what a pointer is pointing to without first having something pointing to what that pointer was originally pointing to, or you'll loose access to that stuff and have a memory leak
		- push()
			- ![[Pasted image 670.png]] vs.
			- ![[Pasted image 671.png]]
		- pop()
			- ![[Pasted image 672.png]] vs.
			- ![[Pasted image 673.png]]
	- **common error - dereferencing deleted pointers**
		- sometimes the code will still work as intended bc the data the pointer was pointing to is technically left untouched, until something else writes to that data slot. So this has *undeterminable* behaviour!
		- detructor
			- ![[Pasted image 674.png]] vs 
			- ![[Pasted image 676.png]]

 ### Traversal
 - using a while loop is the most common way to traverse a list
	 - [] printing a linked list
		 ```
		 void printList(Node* list){
			while(list != nullPtr){
				cout<<list->data<<endl;
				list=list->next;
			}
		 } 
		```
		- ![[Pasted image 656.png]]
	- [] finding length
		- ![[Pasted image 657.png]]
- be really careful about memory deallocation! Keep temporary pointers 
	- []freeing linked lists
		- ![[Pasted image 659.png]]
- using recursion with linked lists! remember by definition, for each node in a linked list, it only cares about itself - it's either pointing to nullptr or its pointing to another node
	- [] ![[Pasted image 660.png]] 
	- note that a list with n nodes requires n stack frames, which limits the size of list we can process, so *generally it's better to run utility functions on linked lists itteratively*. but recursive solutions are really nice for trees


### Insertion
- inserting into the front of the linked list;
	- you must pass the pointer by reference! if you don't, any new nodes you create and add to the *copy* of a passed-by-value list will be out of scope once the function finished running
	- ![[Pasted image 662.png]]
	- (very similar to push for the stack ADT)

- inserting to the end of a linked list;
	- three steps;
		- 1. create a new node
		- 2. find the last node in the list
		- 3. change the pointer of that last node from nullptr to our new node
	- ![[Pasted image 663.png]]
	- note that the edge cases of end starting as null and an empty list being inputted are handled!
	- the order of elements you append was preserved, which is the benefit over prepending
	- this method is O(n) bc we had to find the very last node's index...
	- BUT!! this is hecking horrible with timing. So instead, we'll keep a pointer to keep track of the last pointer
		- compare createList( O(n^2)) with createListWithTailPointer ( O(n) ) 
			- ![[Pasted image 677.png]]

- inserting/deleting in the middle of the list
	- ![[Pasted image 678.png]]
	- ![[Pasted image 681.png]]
	- notice how many pointers (cur and prev) we're using to keep track of different elems in traversal
	- notice how at the end, before dereferncing, we always protect against dereferencing nullpts






