5.Given an array A of n elements and a permutation P, apply P to A.

So, basically we want A[P[i]]=A[i].

vector<int> c=A;
We apply the permutation P to this c using A.
We finally return c;

Time complexity - O(n)
Space Complexity - O(n)

Optimised Solution ::

A[i]+=M*(A[p[i]]%M)
And finally we do A[i]/=M;
Where M=max(A[i]) + 1.
