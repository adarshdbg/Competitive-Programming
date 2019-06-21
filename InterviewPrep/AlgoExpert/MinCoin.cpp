#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;

int f(int n,int i,vector<int> a){
	if(n==0){
		return 0;
	}
	if(n<0){
		return 100000000;
	}
	if(i==a.size()){
		if(n){
			return INT_MAX;
		}
		return 0;
	}
	if(m.count(make_pair(n,i))){
		return m[make_pair(n,i)];
	}
	m[make_pair(n,i)]=0;
	m[make_pair(n,i)]+=f(n,i+1,a);
	m[make_pair(n,i)]=min(m[make_pair(n,i)],1+f(n-a[i],i,a));
	return m[make_pair(n,i)];
}

int minNumberOfCoinsForChange(int n, vector<int> a) {
	if(n==0){
		return 0;
	}
  // Write your code here.
	m.clear();
	int ans=f(n,0,a);
	if(ans>=100000000){
		return -1;
	}
	return ans;
}
