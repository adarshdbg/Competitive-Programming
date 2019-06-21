#include <bits/stdc++.h>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	int dp[array.size()+1];
	if(array.size()==0){
		return 0;
	}
	if(array.size()==1){
		return array[0];
	}
	dp[0]=0;
	dp[1]=array[0];
	for(int i=2;i<=array.size();i++){
		dp[i]=max(dp[i-1],dp[i-2]+array[i-1]);
	}
	return dp[array.size()];
}
