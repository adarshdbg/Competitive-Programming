#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;

ll dp[100006][16];

ll f(string s,ll i,ll rem){
    if(i==s.length()){
        if(rem==5)return 1;
        return 0;
    }
    if(dp[i][rem]!=-1){
        return dp[i][rem]%mod;
    }
    if(s[i]!='?'){
        return dp[i][rem]=f(s,i+1,(rem*10+(s[i]-'0'))%13);
    }
    dp[i][rem]=0;
    for(ll j=0;j<10;j++){
        dp[i][rem]+=f(s,i+1,(rem*10+j)%13);
        dp[i][rem]%=mod;
    }
    return dp[i][rem]%mod;
}


int main(){
    string s;
    cin>>s;
    // cout<<s<<endl;
    memset(dp,-1,sizeof(dp));
    ll ans=f(s,0,0);
    cout<<ans<<endl;
}
