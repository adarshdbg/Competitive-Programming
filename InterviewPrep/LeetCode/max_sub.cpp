#define ll long long 

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans=-1e17;
        int s=0;
        for(int i=0;i<a.size();i++){
            s+=a[i];
            ans=max(ans,s);
            if(s<0)s=0;
        }
        
        return ans;
    }
};
