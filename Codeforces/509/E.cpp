#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double 
ld arr[500005],res=0;
int main(){
    string s;
    cin>>s;
    ll n=s.length();
    ll pre[n+1]={0};
    for(ll i=1;i<500005;i++)
    arr[i]=arr[i-1]+1.0/i;
    for(ll i=0;i<n;i++)
    if(s[i]=='I'||s[i]=='E'||s[i]=='A'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
    pre[i+1]=pre[i]+1;
    else
    pre[i+1]=pre[i];
    for(ll i=1;i<=n;i++)
    res+=pre[i]*(arr[i]-arr[n-i]);
    cout<<setprecision(100)<<res;
}
