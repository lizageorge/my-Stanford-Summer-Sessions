# Sorting
### July 28, 2020 - day 21

- there are a *lot* of strategies/algorithms we can use to sort data;	
	- selection sort
	- insertion sort


### Selection Sort
- find the smallest element, move it to the first, then find the smallest in the remaining and move it, repeat
- ![[Pasted image 679.png]]
- O(n * (N+1) / 2) = O(n * (N+1)) = O(n^2 + n) = O(n^2)	

### Insertion Sort
- for each element in the array, insert it into the right position in the sorted sequence *behind* int
- ![[Pasted image 680.png]]
- Technically O(n^2) in the worst case, but in the best case is O(n), and for anything in the middle still has a better runtime than selection sort 



