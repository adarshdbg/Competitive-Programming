#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeNumberSum(vector<int> a, int s) {
  // Write your code here.
	vector<vector<int>> ans;
	sort(a.begin(),a.end());
	
	if(a.size()<=2){
		return ans;
	}
	
	for(int i=2;i<a.size();i++){
		int sum=s-a[i];
		// count the number of pairs having sum equal to sum
		int l=0,r=i-1;
		while(l<r){
			if((a[l]+a[r])==sum){
				vector<int> temp;
				temp.push_back(a[l]);
				temp.push_back(a[r]);
				temp.push_back(a[i]);
				ans.push_back(temp);
				l++;
			}
			else if((a[l]+a[r])>sum){
				r--;
			}
			else{
				l++;
			}
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}
