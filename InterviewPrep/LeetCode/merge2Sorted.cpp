class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
	    while(n) A[m + n] = (!m || A[m - 1] < B[n - 1]) ? B[--n] : A[--m];
    }
};
