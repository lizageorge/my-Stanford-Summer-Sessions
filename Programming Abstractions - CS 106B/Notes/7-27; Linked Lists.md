# Linked Lists
### July 25, 27 2020 - day 19-20

## omg catch up lecture 19


- linked lists can be used "standalone"

## Linked List Operations
 (more from lecture 19)
 
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
	- this method is O(n) bc we had to find the very last node's index...
	- the order of elements you append was preserved, which is the benefit over prepending






