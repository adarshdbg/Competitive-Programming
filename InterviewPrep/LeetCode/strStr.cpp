#define ll long long 
class Solution {
public:
    int strStr(string a, string b) {
        if(b.length()==0 && a.length()==0)return 0;
        if(b.length()>a.length())return -1;
        
        ll ind=-1;
        for(ll i=0;i<a.length();i++){
            ll k=i;
            ll j=0;
            while(a[k] && b[j] && (b[j]==a[k])){
                k++;
                j++;
            }
            if(!b[j]){
                return i;
            }
        }
        return -1;
    }
};
