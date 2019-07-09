#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> compute_LPS_array(string s,ll m){

    ll len=0;
    vector<ll> v(m);

    v[0]=0;
    ll i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            pat[i]=len;
            i++;
        }
        else{
            if(!len){
                len=v[len-1];
            }
            else{
                v[i]=0;
                i++;
            }
        }
    }

    return v;

}

vector<ll> KMP_positions(string s,string pat){
    ll n=s.length();
    ll m=pat.length();
    vector<ll> lps=compute_LPS_array(pat,m);
    vector<ll> ans;
    ll i=0, j=0;
    while(i<n){
        if(pat[j]==s[i]){
            i++;
            j++;
        }
        else{
            if(j==m){
                // Pattern Matches
                ans.push_back(i-j);
                j=lps[j-1];
            }
            else{
                // Mismatches after j matches
                if(i < N && pat[j] != txt[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {

    string s;
    cin>>s;


}
