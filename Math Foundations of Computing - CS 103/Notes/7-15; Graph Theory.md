# Graph Theory
### July 15 - lecture 9


## Defining Graphs
- think about examples in real life; maps (roads linking cities), molecules (atoms linked by bonds), flowcharts, the internet(computers linked by various links)
- *A graph is a mathematical structure showing relationships. Nodes/vertices are connected by edges/arcs*
- Graphs of two types
	- **directed graphs** have edges that have a start and an end. So the link itself has a direction ([]tournaments ![[Pasted image 426.png]])
	- **undirected graphs** no notion of direction in the links ([] adjacent words ![[Pasted image 427.png]]) 
- unless otherwise specified, a "graph" is undirected and has a finite number of nodes
- a directed graph can have two edges connecting a pair of nodes that go in opposite directions. This is the equivalent of having an undirected edge within a directed graph
	- ![[Pasted image 437.png]]
### Rigorous Definition
- An undirected graph is an ordered pair G=(V, E) where V is a set of nodes (which can be anything) and E is the set of edges (which are the unordered pairs of nodes drawn from V)
- A directed graph is an ordered pair G=(V, E) where V is a set of nodes and E is the set of edges (which are ordered pairs of nodes drawn from V)
	- ![[Pasted image 429.png]]
- **unordered pairs** a set of `{a, b}` where a != b and order doesn't matter (usualy represented with `{}` instead of `()`)

- **Self-Loops**
	- when a node has a node to itself.
	- Undirected graphs are usually not allowed to have self-loops


## Standard Definitions
- two nodes are **adjacent** if they have one node directly linking them
	- ![[Pasted image 430.png]]
	- `Let G = (V, E). Two nodes u, v \in V are adjacent if {u, v} \in E`
- a **path** is a sequence of nodes where consecutive nodes are adjacent
	- ![[Pasted image 432.png]]
	- the **length** of a path is the *number of edges* (`in a path v1, v2, ...vn is n-1`)(think about the distance you travel relating to the numer of highways, not the number of cities) 
		- a single node has a path of length of 0
	- a **cycle** is a path from one node back to itself (by convention, not allowed to have length zero)
		- ![[Pasted image 433.png]]
		- now the length is still one less than the number of cities, but the path includes the same name twice so the length is equal to the number of nodes listed (so the length of a cycle is the *number of distinct nodes still = number of edges*)
	- a **simple path** is a path that does not repeat any nodes or edges
		- [/] ![[Pasted image 434.png]]
	- a **simple cycle** is a cycle that does not repeat any nodes or edges except the first/last node
		- [/] ![[Pasted image 435.png]]
		- [/] `SF, Sac, SF` has a repeated edge
	- for directed graphs, the consecutive elements in a path must follow the direction of the edges
- two notes are **connected** is there is a path between them
	- a graph as a whole is called connected if any pair of nodes is connected ( [/] ![[Pasted image 436.png]]). (an empty graph with no nodes is vacously connected)
	- the **connected component** is the set of all the nodes connected to a specific node
		- `[v] = {x \in V | v is connected to x}`
		- [] ![[Pasted image 438.png]]
		- *connectivity is an equivalence relation* (it's reflexive, symmetric and transitive) (formal proof: ![[Pasted image 439.png]]), so 
		- *connected components are equivalence relations of the connectivity relation!*  (this is how we can split up a graph )
- the **degree** of a node is the number of other nodes the node is adjacent to
	- ![[Pasted image 442.png]] 
- **clique** is a graph with all possible edge
	- (this is a 6-clique, ignore the colours)![[Pasted image 451.png]]

- **trees** = a connected, non-empty (undirected)graph with no simple cycles, 
	- There's only one node from any one node to another node
	- **maximally acyclic** = adding any empty edge creates a simple cycle
	- **minimally connected** = deleting any edge disconnect the graph

## Pigeonhole Principle

- = If you have *m* objects distributed among *n* bins, at least one bin will have to contain more than one object. 
- ![[Pasted image 881.png]]
- if you manipulate your situation to adjust the *m* or *n* such that *m > n*, you can use pigeonhole principle!
	- [] ![[Pasted image 882.png]] 
- you can also often try proof by contradiction and see that things simply won't fit

### The Generalized pigeonhole principle
- **if you have m objects and n bins, some bin will have at least ceil(m/n) objects in it and some bin will have at most floor(m/n)**
	- []![[Pasted image 446.png]] - there has to be at least one bin with three pigeons, and at least one with two
	- ![[Pasted image 447.png]], ![[Pasted image 448.png]], or ![[Pasted image 449.png]]
- proof; ![[Pasted image 450.png]]

- proofs with pigeonhole
- [ ] clique two triangles proof
- [ ] ramsey's proof;
	- [ ] ![[Pasted image 452.png]]
		- [ ] sf
- [ ] ![[Pasted image 453.png]]
	- we can also say **if you have m objects and n bins, some bin will have at least ceil(m/n) objects in it iff some bin will have at most floor(m/n)**
	- "without loss of generality" is used when you just label things *arbitrarily*


- basically most of the time when working with graph theory and grouping nodes, or really when grouping anything, keep this in the back of your mind. Use the template "If there are m objects and n bins, then some bin will have at least/most m/n(ceil/floor) objects in it!"














