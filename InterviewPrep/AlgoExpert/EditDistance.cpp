#include<bits/stdc++.h>
using namespace std;
map<pair<int,int> ,int> m;
int f(int i,int j,string a,string b){
	// Base Case
	if(i==a.length() && j==b.length()){
		return 0;
	}
	if(i==a.length()){
		return b.length()-j;
	}
	if(j==b.length()){
		return a.length()-i;
	}
	// Rec Case
	if(m.count(make_pair(i,j))){
		return m[make_pair(i,j)];
	}
	
	m[make_pair(i,j)]=0;
	if(a[i]==b[j]){
		return m[make_pair(i,j)]=f(i+1,j+1,a,b);
	}
	m[make_pair(i,j)]=f(i+1,j,a,b)+1;
	m[make_pair(i,j)]=min(m[make_pair(i,j)],1+f(i,j+1,a,b));
	m[make_pair(i,j)]=min(m[make_pair(i,j)],1+f(i+1,j+1,a,b));
	return m[make_pair(i,j)];
	
}

int levenshteinDistance(string a, string b) {
	if(a.length()==0){
		return b.length();
	}
	if(b==""){
		return a.length();
	}
  // Write your code here.
	m.clear();
	return f(0,0,a,b);
}
