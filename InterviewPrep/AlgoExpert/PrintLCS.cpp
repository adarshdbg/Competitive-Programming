#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<char> longestCommonSubsequence(string a, string b) {
  // Write your code here.
	ll c=a.length(),d=b.length();
	ll dp[c+1][d+1]{0};
	for(ll i=1;i<=c;i++){
		for(ll j=1;j<=d;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
		}
	}
	ll maxLength=dp[c][d]-1;
    // cout<<maxLength<<endl;
	vector<char> v;
	if(a=="" || b==""){
		return v;
	}
	
	ll i=c,j=d;
	while(i && j){
		if(a[i-1]==b[j-1]){
			v.push_back(a[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1])i--;
			else j--;
		}
	}
    reverse(v.begin(),v.end());
	return v;
}
