class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0;
        if(a.size()<2)return 0;
        int m=a[0];
        for(int i=1;i<a.size();i++){
            ans=max(ans,a[i]-m);
            m=min(m,a[i]);
        }
        return ans;
    }
};
