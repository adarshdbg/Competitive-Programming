class Solution {
public:
    int maxProfit(vector<int>& a) {
        if(a.size()<2)return 0;
        int dp[a.size()+1];
        int n=a.size();
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            for(int j=i-1;j>=0;j--){
                if(a[i]>=a[j]){
                    dp[i]=max(dp[i],a[i]-a[j]+(j?dp[j-1]:0));
                }
            }
        }
        return dp[n-1];
    }
};
