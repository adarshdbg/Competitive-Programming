class Solution {
public:
    int rob(vector<int>& a) {
        if(a.size()==0)return 0;
        int n=a.size();
        int dp[n][2]{0};
        dp[0][1]=a[0];
        dp[0][0]=0;
        for(int i=1;i<=n-1;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+a[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
