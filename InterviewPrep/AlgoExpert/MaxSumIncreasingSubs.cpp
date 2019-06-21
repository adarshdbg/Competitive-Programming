#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,vector<int>>> m;

pair<int,vector<int> > f(int i,vector<int> a){
	
	// Base Case
	if(i==a.size()){
        vector<int> t;
		return make_pair(0,t);
	}
	// Rec Case
	if(m.count(i)){
		return m[i];
	}
	m[i].first=-10000000;
	vector<int> temp;
	m[i].second=temp;
  bool flag=false;
	for(int j=i+1;j<a.size();j++){
		if(a[j]>a[i]){
			pair<int,vector<int>> nextcall=f(j,a);
			if(m[i].first<nextcall.first+a[i]){
				m[i]=nextcall;
                m[i].first+=a[i];
                m[i].second.push_back(a[i]);
			}
            flag=true;
		}
	}
    if(!flag){
        m[i].first=a[i];
        m[i].second.push_back(a[i]);
    }
	return m[i];	
}

vector<vector<int> > maxSumIncreasingSubsequence(vector<int> a) {
  // Write your code here.
	
	
	m.clear();
	pair<int,vector<int>> ans=f(0,a);
	vector<vector<int>> v(2);
	vector<int> t;
	t.push_back(ans.first);
	v[0]=t;
	v[1]=ans.second;
	reverse(v[1].begin(),v[1].end());
	if(v[0][0]==-(10000000)){
		v[1].clear();
		int ans=-10000000;
		for(int i:a){
			if(ans<i){
				ans=i;
			}
		}
		v[1].push_back(ans);
		v[0][0]=ans;
		return v;
	}
	return v;
	
	
}
