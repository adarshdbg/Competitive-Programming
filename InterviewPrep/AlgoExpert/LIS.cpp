#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> a) {
  // Write your code here.
	int n=a.size();
	vector<int> temp;
	if(n==0){
		return temp;
	}
	if(n==1){
		temp.push_back(a[0]);
		return temp;
	}
	pair<int,int> dp[n+1];
    
	for(int i=1;i<=n;i++){
		dp[i].first=1;
		dp[i].second=i;
		for(int j=1;j<i;j++){
			if(a[j-1]<a[i-1]){
                if(dp[j].first+1>dp[i].first){
                    dp[i].second=j;
                }
				dp[i].first=max(dp[i].first,dp[j].first+1);
				
			}
		}
	}
	int ans=0;
	int ind;
	for(int i=1;i<=n;i++){
		if(ans<dp[i].first)ind=i;
		ans=max(dp[i].first,ans);
	}
	vector<int> v;
	for(int i=ind;i>0;i--){
        // cout<<ind<<" ";
		v.push_back(a[i-1]);
		if((dp[i].second)==i)break;
		i=dp[i].second+1;
	}
    // cout<<endl;
	reverse(v.begin(),v.end());
	return v;
}
