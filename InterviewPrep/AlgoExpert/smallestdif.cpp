#include <bits/stdc++.h>
using namespace std;



vector<int> smallestDifference(vector<int> a, vector<int> b) {
  // Write your code here.
	int diff=INT_MAX;
	vector<int> ans;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(abs(a[i]-b[j])<diff){
				diff=abs(a[i]-b[j]);
				vector<int> t;
				t.push_back(a[i]);
				t.push_back(b[j]);
				ans=t;
			}
		}
	}
	return ans;
}
