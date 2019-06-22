#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
bool ispal(string s,int i,int j){
	if(i>j){
		return m[make_pair(i,j)]=0;
	}
	if(i+1==j){
		return m[make_pair(i,j)]=(s[i]==s[j]);
	}
	if(i==j){
		return m[make_pair(i,j)]=1;
	}
	if(m.count(make_pair(i,j))){
		return m[make_pair(i,j)];
	}
	int ans=0;
	ans=((s[i]==s[j])&(ispal(s,i+1,j-1)));
	return  m[make_pair(i,j)]=ans;
}

map<pair<int,int>,int> ans;

int find_ans(string s,int i,int j){
    
    if(i>j){
        return ans[make_pair(i,j)]=0;
    }
    if(m[make_pair(i,j)]){
        return ans[make_pair(i,j)]=0;
    }

    if(ans.count(make_pair(i,j))){
        return ans[make_pair(i,j)];
    }
    int an=INT_MAX;
    
    for(int k=i;k<j;k++){
        an=min(an,find_ans(s,i,k)+1+find_ans(s,k+1,j));
    }
    return ans[make_pair(i,j)]=an;
}

int palindromePartitioningMinCuts(string s) {
  // Write your code here.
	int n=s.length();
	m.clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int ans=ispal(s,i,j);
		}
	}
    ans.clear();
    return find_ans(s,0,n-1);
}
