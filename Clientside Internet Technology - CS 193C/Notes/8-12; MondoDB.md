# MondoDB
### August 12, 2020 - lecture 12

- a **Database** is a storage system set up so that several programs across the internet can access it. It allows
	- Persistent storage (also in basic file systems)
	- Application access (the several programs over internet can access it thing)
	- Transaction management (makes sure that actions like transactions of money is *atmoic* (either sending and recieving happens simultaneously or neither happes))
	- Efficient search ( :) cute)

- most DBs are **relational databases** (think of tables that relate things by property)
	- usually written with **SQL** (structured query language)
	- most standard DBs are relational 


## What is Mongo
- relational DBs are not designed for distributed information (not having everything on a single server in the world)
- **no-SQL** DBs are made for distributed information. Some are based on key-value pairs or graphs
	- [] MongoDB
	- [] AWS's Dynamo DB
	- usually either not always perfectly uptodate	or more expensive to be uptodate	


- what you can work with into the console after opening mongo db; 
	- ![[Pasted image 904.png]]
	- ![[Pasted image 905.png]]
	- notice that things are stored internally works like JS Objects, and can be accessed with JS functions

### MEAN
- like a set of softwares that all relate to JS, so ppl tend to use them all together
- **M**ongo
- **E**xpress
- **A**ngular
- **N**ode


- As opposed to **LAMP** (Linux, Apache, MySQL, PHP/Python), which requires greater diversity of knowledge in a team