8. Write a program which takes an array as input of integers, where A[i] denotes the maximum you can advance from index i, and return whether it is possible to advance to the last index starting from the beginning of the array.

class CanReachTheEnd{
Public:
	Bool CanReach(const vector<int> &A){
		int farthest_reach=A[0],step=1;
		for(int i=1;i<n;i++){
			farthest_reach=max(farthest_reach,a[i]+i);
			Step--;
			if(step==0){
				if(farthest_reach-i<=0)return false;
				step=farthest_reach-i;
			}
		}
	}
};
