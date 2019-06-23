#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void permute(vector<int> a,int i){
	if(i==a.size()){
		ans.push_back(a);
		return ;
	}
	for(int j=i;j<=a.size()-1;j++){
		swap(a[j],a[i]);
		permute(a,i+1);
		swap(a[j],a[i]);
	}
}

vector<vector<int>> getPermutations(vector<int> a) {
	if(a.size()==0){
		vector<vector<int>> v;
		return v ;
	}
	ans.clear();
  // Write your code here.
	permute(a,0);
	return ans;
}
