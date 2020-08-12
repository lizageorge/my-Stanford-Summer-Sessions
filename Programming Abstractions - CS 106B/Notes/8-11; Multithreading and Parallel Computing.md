# Multithreading and Parallel Computing
### August 11, 2020, day 29 
#### Trip's Guest Lecture, not techically tested or anything. just fun :)

- how to use the different cores in a computer in order to parallelize work safely?

### a review of how code works -threads
- code is executed from top to bottom. **thread** = an abstraction that represents the sequential (top-to-bottom) execution of code
- maybe the thread starts in the first { of main, and make its way to the last } of main. It might squiggle away for different methods or loop or jump around, but still gets from point a to point b
- each program you run takes up a thread. complex programs might even have multiple threads. So your computer would have multiple threads running at once, like thousands
- (note - there's a difference between threads and processes to learn about. processes don't share state as easily so its harder to multiprocess than multithread )

### crossing to hardware - cores and the OS
- but remember, a thread is still an abstraction. Each CPU will have multiple **cores** that are in charge of running programs with a thread. Most processors have four cores, so four programs can be run concurrently.
- If all the cores are busy with other threads, a thread has to wait until a core frees up.
- the **operating system** is code that manages the relationship between hardware and software
	- this is what determines how long a thread can stay on a core. they say threads have to leave when a thread leaves, but also when another more important thread has to run, but also when a thread 'volunteers' to temporarily leave the core

### I/O bounds and the need for parallelization
- imagine a thread that needed an **I/O Bound**, or any task that requires outside communication. This would create a bottleneck, bc the program is just *waiting* for a response from the I/O Bound. So the thread will remove itself while waiting!	When it tries to re-enter the core, the OS will let it. This process of moving on and off a core happens *every single time* that task is called -and it takes next to no time
- this switching is necessary bc having too many threads takes up a lot of memory, and too many physical cores gets expensive
- **parallelization** = any way we get multiple programs to run simultaneously


### multithreading!
- one method of parallelization
- instead of having a single thread moving in and out of the core, we can create a new thread for every task called!
	- create threads in cpp using `#import thread.h`, `thread newThread = new thread(funcName);`
- but we have to be careful - for one, creating a thread makes it immediately start running. threads are also memory intensive, so we have to delete it after spawning and using it, like pointers (using `threadName.join()` - join will wait until the thread's function finishes running)
- [] ![[Pasted image 864.png]]
	- now the whole program took 1 sec instead of 10 secs! this is bc there are multiple threads from the same program on several cores at once. while one thread is waiting for task to finish before getting back on core, another thread is created by main and put on. So each thread is only the core for a fraction of a second to set up the I/O and leave, and then after one second it returns to complete.
		- ![[Pasted image 865.png]]
		- note that the threads might be created in weird orders bc code runs so fast...
- **race condition** = when threads run concurrently and compete with each other and things just mess up and get unpredictable. For example, using smth slow like `cout` is not thread-safe
	- but you can define an operation to be **atomic**, which means it can only be run before or after another operation, not during. protect code like this by wrapping it around `mutex` statements
		- ![[Pasted image 866.png]] 
		- ![[Pasted image 867.png]]
	- not that making smth atomic removes it from the parallelization process, so it shouldn't be overused