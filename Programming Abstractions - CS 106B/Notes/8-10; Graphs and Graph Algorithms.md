# Graphs and Graph Algorithms
### August 10, day 28
- graphs can represent a whole bunch of stuff from real life
	- social networks, highway systems, the internet
	- chemical bonds
	- flowcharts

#### Some terminology
- a **graph** is a structured way to represent relations(edges) between entities(nodes)
	- two nodes are **neighbors** if they're directly connected by an ede
	- a **path** is the chain of edges and nodes between two nodes, and the **length of the path** is the number of edges in a path
		- a **cycle** is a path that starts and ends in the same node
	- a **loop** is an edge that connects a node to itself (only allowed in some graphs)
	- a **graph** is connected if every node can be reached from any node, and **complete** if every node is directly connected to every other node
- *types of graphs*
	- **directed** = the relations are unidirectional, **undirected** = every relationship is bidirectional/symmetric
	- **weighted** = not all the relations between entities are equal ([] a highway map where each edge has a weight of the length of the road), vs **unweighted**


### Graphs as Linked Data Structures
- trees are like graphs with no cycles and a special parent-child relationship. graphs are linked data structures with next to no restrictions like that

- multiple ways to represent graphs;

#### Adjacency Lists
- a table of nodes and all the nodes they're adjacent to
	- ![[Pasted image 798.png]]
- could be done with Maps (using Vectors or Sets for the lists of neighbors), or if your Node struct could contain a Vector/Set of neighbors then you can just have a Vector/Set of Nodes.
#### Adjacency Matrix
- a 2D array/matrix of bools/bits representing if a connection exists between nodes in the row and collumn
	- ![[Pasted image 800.png]]
	- will be diagonally symmetric on undirected graphs
-  this is less efficient for a large graph without as many edges, it's just nice bc of its mathematical properties
-  you could use a Grid for this

## Graph Algorithms
### Graph Traversal
- multiple approaches
- 1. *Breadth-First Search*
	- keep track of nodes visited with a queue and search through the entire graph by emptying it(look at 7-01 for full algorithm). 
		- ![[Pasted image 801.png]]
	- this will visit the nodes in order of length of the path (from a start node- you can actually make a BFS tree that orders nodes in terms of length of path from the start node acting as a root node)
		- ![[Pasted image 802.png]]
	- but this won't take edge weights into account
- 2. *Dijkstra's Algorithm*
	- allows us to find the *shortest path* based on edge *weights* (not the number of edges)
	- very similar to bfs, but uses a priotiyQueue instead of just a regular queue! every added node will have a priority of the sum of weights of path to that node
		- ![[Pasted image 803.png]]
		- for each node you visit, look at its neighbors, and add them to the pq with a prioiryt of the currentPriority+their edge weights
			- ![[Pasted image 804.png]]
			- you might find shorter paths to nodes than is stored from previous nodes, in which case you would replace it
- 3. *A\* Search*
	- if you have some additional information of nodes and where you want to go/extrernal knowledge (**a heuristic**), you can prioritize searching some paths over other.
		- ![[Pasted image 805.png]] as opposed to BFS which would search a great big circle before reaching the red square
		- these heuristics are unique to each problem. They should always *underestimate* the path length you would get if you followed it
		- []  For example, when finding the shortest path to SF, you would start by *looking north* and claiming that the shortest estimate distance to sf is 40 miles. 
	- now you would add some heuristic value to the priority of each node in the dijkstra algortihm
- there are more!
	- ![[Pasted image 806.png]]