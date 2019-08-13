#define ll long long 
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        ll si=0,ei=x;
        ll ans=1;
        while(si<=ei){
            ll mid=(si+ei)/2;
            if(mid*mid<=x){
                ans=mid;
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        return ans;
    }
};
