# Designing our own ADTs
### July 20, 21 2020 - day 16, 17

- combining what we learned about c++ classes and memory allocation to replicate the ADTS we've used from Stanford library

## Vector
- create an OurVector class that replicates the Stanford Vector Class
- Vectors have
	- nice methods (arrays don't have funstions)
	- bounds-checking
	- well abstracted design
- our constraints
	- we're only making like sixish methods
	- only storing ints (the Stanford library uses smth called a Generic/Template class?)
	- having a max # elems to store
	- we're not going to redefine operators
	
	### Design
	- what's the public interface/public fuctions going to be?
		- add(), get(), insert(), remove(), size(), isEmpty()
	- private member variables?
		- pointer to the array that's acting as the underlying storage (`int* elements`)
		- a size integer represnting *allocated* capacity, and another representing the number of variables 
	- constructor?
		- initialize those three vars. allocatedCapacity will be some set max length, and numItems to 0, and the pointer to an actual array
	- destructor to deallocated memory
	- full header: ![[Pasted image 544.png]]
	- in this example, we're using a constant INITIAL_SIZE, but we can dynamically resize that

### Implementation!
```
//OurVector.cpp file, insert tags haven't been included here

OurVector::OurVector(){
	allocatedCapacity = INITIAL_CAPACITY;
	numItems = 0;
	elements = new int[allocatedCapacity];
}

//oops i forgot the return types for all of these lmao

OurVector::~OurVector(){
	delete[] elements
}

OurVector::get(int index){
	if(index<0 || index>= numItems){
		error("invalid index!")
	}
	return elements[index];
}

OurVector::add(int value){
	if(numItems == allocatedCapacity){
		error("out of space")
	}
	int nextEmptySlotIndex = numItems;
	elements[nextEmptySlotIndex] = value;
	numItems++;
}

OurVector:: size(){
	return numElems;
}
OurVector:: isEmpty(){
	return (numElems == 0);
}

OurVector::remove(int index){
	if(index<0 || index>= numItems){
		error("invalid index!")
	}
	
	//shift elems to the left, watch out for off-by-one errors
	for(int i = index; i < numItems - 1; i++){
		elements[i] = elements[i+1]; //overwritting those values
	}
	
	numItems--;
}

OurVector::insert(int index, int value){
	if (index < 0 || index > numItems){
        error("Invalid vector index! Should be in range [0 - "
              + integerToString(numItems - 1) + "]");
    }

    if(numItems == allocatedCapacity){
		error("out of space")
	}

    for (int i = numItems; i > index; i--) {
        elements[i] = elements[i-1];
    }
    elements[index] = value;
    numItems++;
	
}
```

### Initialization/the Client side
- once the constructor is called (when INITIAL_CAPACITY was set to 8)
	- ![[Pasted image 537.png]]
	- remember that an array elem's initial value is just garbage (not smth nice like 0)
- the **add(index n)** method
	- ![[Pasted image 538.png]]
- the **remove(index n)** method	
	- we shift over the elements to the right of index n one step to the left
	- the last elem in our values won't be deleted, but we'll just treat it as garbage
	- edit the numElems var
	- ![[Pasted image 539.png]] 
	- note we never actually "delete" anything
- the **insert(index n)** method
	- ![[Pasted image 540.png]]
	- for every element from index to numItems, shift them to the right
	- then fill in the index with the value, and increment addItems
- get() just returns the value at the specified index, and would also include bounds checking
- size() returns numEelems, isEmpty() returns if numElems is equal to 0


### Dynamic Array Growth
- think about a hermit crab that finds new and bigger shells as they outgrow their old shell. Once they outgrow a shell..
	- ![[Pasted image 542.png]]
- because we can't change the size of an array, we have to create and move to a *new* array of a greater size when we have too many elements in the Vector.
	- ![[Pasted image 543.png]]
- we normally make the new array *twice* as large as the old array to spread out the cost of all this reallocating work. So even though add() when you have to resize will be O(n), bc it's nicely spread out, add() has an *average* (or **amortized**) runtime of O(1)

- so we'll create a helper function called "expand" to do this
	- this method has to be *private*, so it's in the private section of the header

```
void OurVector::resize(){
	//ask for new space in a new array
	int* newElements = new int[2 * allocatedCapacity];
	
	//copy the values over
	for(int i = 0; i < numItems; i++){
		newElements[i] = elements[i];
	}
	
	//delete old array
	delete[] elements;
	
	//point elements pointer to new array
	elements = newElements;
	
	//update capacity
	allocatedCapacity *= 2;
}
```

- we can call this helper function everytime we called an error in the impletmentation above

## Multiple Levels of Abstraction
- we can have multiple abtraction boundaries (the dotted line to the right is the boundary for the user of the ADTs)
	- ![[Pasted image 574.png]]

### [] Priority Queue
- a Queue that is sorted based on a specified priority
- three operrations;
	- enqueue(priorityValue, element)
	- dequeue(); removes element with highest priority
	- peek(); check element with highest priority
	- also size(), isEmpty(), and clear() 
#### Design
- it's not great to just keep an *underlying array* that is sorted and get the last elem from that for peek() and dequeue(0) (although this is smth you'll do on assign4)

- instead, we'll store that priority queue as a binary heap for optimization 
- **binary heaps**
	- **heap** = a tree based structure that follows the heap property (= parents have higher priority than children) and is complete (=rows are filled from left to right)
	- binary heap = a heap where every parent has two children
	- two types of heaps
		- **min heap** = smaller numbers have higher property/are closer to root (parents have smaller values than children)
			- []![[Pasted image 576.png]]
		- **max heap** = larger numbers have higher property/are closer to root
	- tree structures like binary trees can be stored as vectors! (this is because they are filled from left to right)
		- ![[Pasted image 577.png]] (this goes the other way to - for a child of index i, the parent has index (i-1)/2 bc of integer division)
	- implementation of the heap
		- ![[Pasted image 578.png]] (note that enqueue was supposed to have priorirty param)
		- enqueue()
			- add elem to the last index in the array (rigth after numItems basically)
			- if it doesn't maintain heap property, swap it with its parent ( = **bubbling up**)
				- ![[Pasted image 579.png]]
				- complexity = O(logn) - now this is faster than O(n), which is what would happen if we implemented priority queue with just a sorted array!
		- dequeue()
			- remove the highest priority (aka the root)
			- replace the root with the *last* elem in the root (last valid/non-garbage thing in the array), and then **bubble down** ( = if violating heap property, swap parent with the *smaller* of the two children)
			- again, O(logn) (2logn simplified)


























