#include<bits/stdc++.h>
#define ll long long
class Solution {
public:
    bool isPalindrome(ll x) {
        if(x<0)return false;
        if(((x)/10)==0)return true;
        
        if(x<0)return false;
        string s;
        while(x){
            s.push_back(x%10+48);
            x/=10;
        }
        string a=s;
        reverse(s.begin(),s.end());
        return (s==a);
    }
};
