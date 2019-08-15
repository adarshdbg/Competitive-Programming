#define ll long long 
class Solution {
public:
    int trailingZeroes(int n) {
        ll cnt_5=0,cnt_2=0;
        int a=n;
        ll p=2;
        p=5;
        while(a/p){
            cnt_5+=a/p;
            p*=5;
        }
        return cnt_5;
    }
};
