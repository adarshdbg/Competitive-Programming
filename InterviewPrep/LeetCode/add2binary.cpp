#define ll long long
class Solution {
public:
    string addBinary(string a, string b) {
        string t;
        if(a.length()<b.length())swap(a,b);
        ll c=0;
        ll i=0,j=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(i<a.length() && j<b.length()){
            ll s=a[i]-'0'+b[i]-'0'+c;
            t.push_back(s%2+48);
            c=s/2;
            i++;
            j++;
        }
        while(i<a.length()){
            ll s=a[i]-'0'+c;
            t.push_back(s%2+48);
            c=s/2;
            i++;
        }
        while(c){
            t.push_back(c%2+48);
            c/=2;
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
