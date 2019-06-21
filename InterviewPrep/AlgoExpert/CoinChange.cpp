#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
int f(int n,int i,vector<int> a){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(i==a.size()){
		if(n==0)return 1;
		return 0;
	}
	if(m.count(make_pair(n,i))){
		return m[make_pair(n,i)];
	}
	m[make_pair(n,i)]=0;
	// Rec Case
	m[make_pair(n,i)]+=f(n,i+1,a);
	m[make_pair(n,i)]+=f(n-a[i],i,a);
	return m[make_pair(n,i)];
}
int numberOfWaysToMakeChange(int n, vector<int> a) {
	if(n==0)return 1;
  // Write your code here.
	// Base Case
	m.clear();
	return f(n,0,a);
}
