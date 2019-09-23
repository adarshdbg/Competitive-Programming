#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
const int mod=1e9+7;
 
signed main() {
 
    IO; 
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k==0){
        cout<<s<<endl;
        return 0;
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n<=k){
        cout<<1;
        for(int i=1;i<n;i++)cout<<0;
        cout<<endl;
        return 0;
    }
    if(s[0]!='1'){
        if(k>0){
            s[0]='1';
            k--;
        }
    }
    for(int i=1;s[i];i++){
        if(s[i]!='0'){
            if(k>0){
                s[i]='0';
                k--;
            }
        }
    }
    
    cout<<s<<endl;
    
 
}
