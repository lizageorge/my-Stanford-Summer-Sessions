# Sorting
### July 28, 29, 2020 - day 22, 23

- there are a *lot* of strategies/algorithms we can use to sort data;	
	- selection sort
	- insertion sort
	- merge sort
	- quick sort
	- (there are more!)
- ![[Pasted image 708.png]]


### Selection Sort
- find the smallest element, move it to the first, then find the smallest in the remaining and move it, repeat
- ![[Pasted image 679.png]]
- O(n * (N+1) / 2) = O(n * (N+1)) = O(n^2 + n) = O(n^2)	

### Insertion Sort
- for each element in the array, insert it into the right position in the sorted sequence *behind* int
- ![[Pasted image 680.png]]
- Technically O(n^2) in the worst case, but in the best case is O(n), and for anything in the middle still has a better runtime than selection sort 

### Merge Sort
- divide and conquer algorithms (merge + quick sort)!
	- imagine the insertion sort applied to a vector V takes t seconds. bc it's O(n^2), sorting a vector of half the length takes t/4 seconds!
	- so we can split up any list, sort, and then merge the sorted portions together
	- ![[Pasted image 700.png]] (notice the self-similarity...)
- -> recursive algorithm!
	- ![[Pasted image 701.png]]
- helper functions... (pass by reference alows us to edit multiple values at once)
	- ![[Pasted image 702.png]]
	- merge() is the same as in earlier hws
- mergeSort
	- ![[Pasted image 703.png]]
- so mergesort takes **O(n logn)** 
	- logn levels, each takes O(n)
	- it's actually impossible to write a sorting algorithm that has a better average runtime than O(n logn) (**fundamental limit**)
	
### Quick Sort
- we *partition* the list around a *pivot* element (three subgroups - everything smaller, equal to, and greater than the pivot), and then recursively sort the smaller-than and larger-than partitions (base case == one elem in list), and then concatenate the three together
	- so the divide step is harder, but the 'merge' step (really just concatination) is easier
- for now, we're just picking the first elem as pivot;
- ![[Pasted image 704.png]]
- helper functions...  (pass by reference alows us to edit multiple values at once)
	- ![[Pasted image 705.png]]
	- ![[Pasted image 706.png]]
- quickSort()
	- ![[Pasted image 707.png]]
- also O(n logn)
	- however!! If you pick a poor  choice of pivot (smth close to the smallest/largest values), this can degrade to being as bad as O(n^2)
- there's smth called inPlaceQuickSort that doesn't require so much extra space

- merge sort and quick sort are just about interchangable. (quicksort can be more space efficient, but can have slow runtime if a poor pivot is picked, mergesort is more consistent )























