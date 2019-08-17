12. Rotate a 2D array.
	Brute force using extra space. Since we are not explicitly required to allocate a new array , it is natural to ask if we can perform the rotation in-place ,i.e. In O(1) space.

Transpose the matrix
Reverse each column
Because the observation is i-th column of initial array becomes the ith row of the modified array but in reverse order.
1 2 3      7 4 1
4 5 6 → 8 5  6
7 8 9      9 6 3
 	Alternative Solutions :: Do it layer by layer .
