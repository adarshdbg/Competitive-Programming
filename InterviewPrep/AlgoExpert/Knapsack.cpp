#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,pair<int,vector<int>>> m;

pair<int,vector<int>> find_ans(vector<vector<int>> items,int i,int capacity){
	// Base Case
	if(capacity<0){
		vector<int> temp;
		return make_pair(INT_MIN,temp);
	}
	if(capacity==0){
		vector<int> temp;
		return make_pair(0,temp);
	}
	if(i==items.size()){
		vector<int> temp;
		if(capacity){
			return make_pair(INT_MIN,temp);
		}
		return make_pair(0,temp);
	}
	// Rec Case
	if(m.count(make_pair(i,capacity))){
		return m[make_pair(i,capacity)];
	}
	pair<int,vector<int>> firstCall=find_ans(items,i+1,capacity-items[i][1]);
	if(firstCall.first!=INT_MIN)
		firstCall.first+=items[i][0];
	firstCall.second.push_back(i);
	pair<int,vector<int>> SecondCall=find_ans(items,i+1,capacity);
	if(firstCall.first>SecondCall.first){
		return m[make_pair(i,capacity)]=firstCall;
	}
	if(firstCall.first==SecondCall.first){
		if(firstCall.second.size()>SecondCall.second.size()){
			return firstCall;
		}
		return m[make_pair(i,capacity)]= SecondCall;
	}
	return m[make_pair(i,capacity)]=SecondCall;
}

vector<vector<int> > knapsackProblem(vector<vector<int> > items, int capacity) {
	
	m.clear();
	pair<int,vector<int>> s= find_ans(items,0,capacity);
	vector<vector<int>> ans;
	vector<int> a;
	reverse(s.second.begin(),s.second.end());
	a.push_back(s.first);
	ans.push_back(a);
	if(ans[0][0]==INT_MIN)ans[0][0]=0;
	ans.push_back(s.second);
	return ans;
}
