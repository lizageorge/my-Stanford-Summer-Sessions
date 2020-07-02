# Unordered Data Structures (Set, Maps)
### June 30, 2020 - day 6

## Sets
- a set in an unordered data structure that doesn't contain duplicates, making it very efficient to use and search!
	- ** we'll learn about the underlying logic of this no-duplicates system later in the course
	- to iterate through a set, you *have* to use a foreach loop because again there are no indeces
	- set operations can be used on these adts;
		- equality ( `==` or `!=`)
		- union (`s1 += s2`), intersection (`s1*=s2`), difference (`s1 -= s2`, order matters)

## Map
- = a collection of **key-value** pairs. You can actually use the key to access specific values.
- initialization looks a little different because there are two different types to account for, two values for each pair
	- ![[Pasted image 116.png]]
- Lot's of methods!
	- ![[Pasted image 115.png]]
- again, you can only iteratre duting foreach loops. You can either iterate through the `elem: map`, but if so, don't edit the keys as you work!!!
	- if you do want to edit the keys, use  `elemKey: map.Keys()` - this will create a copy of the old keys for the for loop so you can edit the keys normally
- auto-insert; when a map has a key called that doesn't already exist in the map, c++ will create a new key-value pair in the map with that key and an empty value! 
	- if you use the square bracket operators, the empty value would be returned *and* a new key-value pair (with the key being what was searched for and the value being the default value for that type) will be added to the map
	- if you use the .get() operator, a default value will be returned but nothing will be changed in the map
	- ![[Pasted image 117.png]]so this will run without error always
	- can cause bugs!! if you try and check for a value
		- ![[Pasted image 118.png]] 
		- ![[Pasted image 119.png]] use .get() or .contains instead!

