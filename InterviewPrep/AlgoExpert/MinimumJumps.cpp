#include <bits/stdc++.h>
using namespace std;

int minNumberOfJumps(vector<int> a) {
  // Write your code here.
  int n=a.size();
  if(n<=1){
      return 0;
  }
	int ans=1;
	
	int curr=a[0];
	int maxJ=a[0];
	for(int i=1;i<n-1;i++){
		maxJ=max(maxJ,a[i]+i);
		curr--;
		if(curr==0){
			ans++;
			curr=maxJ-i;
			maxJ=-1;
		}
		
	}
	return ans;
}

