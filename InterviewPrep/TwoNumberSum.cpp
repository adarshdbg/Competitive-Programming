#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	map<int,int> m;
	vector<int> ans;
	for(int i=0;i<array.size();i++){
		int check=targetSum-array[i];
		if(m.count(check)){
			ans.push_back(array[i]);
			ans.push_back(check);
			break;
		}
		m[array[i]]++;
	}
	sort(ans.begin(),ans.end());
	return ans;
}
