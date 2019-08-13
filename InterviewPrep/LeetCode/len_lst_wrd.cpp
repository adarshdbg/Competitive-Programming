#define ll int
class Solution {
public:
    int lengthOfLastWord(string s) {
       ll cnt=0;
        ll ind=0;
        for(ll i=0;i<s.length();i++){
            if(s[i]==' ')continue;
            ll j=i;
            while(s[j] && s[j]!=' '){
                j++;
            }
            ind=j-i;
            i=j-1;
        }
        return ind;
    }
};
