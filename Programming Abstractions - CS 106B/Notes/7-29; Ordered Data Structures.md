# Ordered Data Structures (Grid, Stacks, and Queues)
### June 29, 2020 - day 5

There are four different ordered ADTs to work with;
- Vectors
- Grids
- Queues
- Stacks

## Grids
- a 2D array (established, non-flexible dimensions)
- `include "grid.h"`
- three ways to create grids
	- 1. 
		`Gride<type> grideName;
		gridName.resize(rows, collumns);`
	- 2. 
		`Grid<type> gridName(rows, collumns)`
	- 3. 
		`Grid<type> = { {1, 2}, {3, 4} };`
- methods you can use with grids: ![[Pasted image 103.png]]
- Traversing through a grid with a nested for-loop is exactly like in java, except! you can't access just a single row (like `grid[0]`), you can only access single cells

## Struct
- a way to group anything together, like creating a custom datatype (or a kind of object in java)
- the `GridLocation` struct - used to store grid locations
  - ![[Pasted image 104.png]]
  - ![[Pasted image 105.png]]
  - to access an elem in a grid of a certain gridlocation loc's location, you can just say `grid[loc]`
  - []so if you wanted to store the locations of a ship in battleship, you can have a vector of type `GridLocation` with all the locations of a ship

## Queues and Stacks
### Queues
- FIFO (First In, First Out)
- methods to use;
![[Pasted image 106.png]]
- enque will add something to the end, deque will remove something from the front
- `#include "queue.h"`
	
### Stacks
- LIFO (Last one in the first one out)
- methods to use;
	![[Pasted image 107.png]]
- push will add smth to the end, pop will remove smth from the end (and return that value)
- `#include "stacks.h"`

### Patterns;
- emptying a queue/stack
	- ![[Pasted image 108.png]]
- iterating through and modifying
	- ![[Pasted image 109.png]]
	- ** don't leave a .size() method call in the for-loop, bc that size() will be changing. store it in a seperate variable first

### Disadvantages/Feautures
- (-)you can't access a specific index in a stack/queue
- (+)useful for LIFO/FIFO models
- [ ] ![[Pasted image 111.png]]


- A summary of indexable and non-indexable ADTs so far
	- ![[Pasted image 112.png]]