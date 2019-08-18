// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
#define ll long long 
class Solution {
public:
    int firstBadVersion(int n) {
        ll si=1,ei=n;
        ll ans=-1;
        while(si<=ei){
            ll mid=(si+ei)/2;
            if(isBadVersion(mid)){
                ans=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return ans;
    }
};
