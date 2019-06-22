#include  <bits/stdc++.h>
using namespace std;

int waterArea(vector<int> a) {
	if(a.size()<=2){
		return 0;
	}
  // Write your code here.
	int ans=0;
	int n=a.size();
	int left[n]{0},right[n]{0};
	left[0]=a[0];
	for(int i=1;i<n;i++){
		left[i]=max(left[i-1],a[i]);
	}
	right[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		right[i]=max(right[i+1],a[i]);
	}
	for(int i=0;i<=n-1;i++){
		ans+=(min(left[i],right[i])-a[i]);
	}
	return ans;
}
