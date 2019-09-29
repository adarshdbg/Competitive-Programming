#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
 
int MAX=1e6+1;
const int mod = 1e9+7;
 
 
int power(int a,int b){
    if(b==0){
        return 1;
    }
    int s=power(a,b/2);
    s*=s;
    s%=mod;
    if(b&1)return (s*a)%mod;
    return s;
}
 
int inv(int n){
    return power(n,mod-2);
}
 
int f[1000];
 
int nCr(int n,int r){
    int ans=f[n];
    ans*=inv(f[r]);
    ans%=mod;
    ans*=inv(f[n-r]);
    ans%=mod;
    return ans;
}
 
signed main() {
    fast;
    
    int n;
    cin>>n;
    int k;
    cin>>k;
    f[0]=1;
    for(int i=1;i<1000;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    
    int ans=0;
    for(int i=0;i<=n;i++){
        int b=((i%2==0)?1:-1);
        int tt=power(k,n-i)-power(k-1,n-i);
        tt=((tt%mod)+mod)%mod;
        int t=nCr(n,i)*b*power(tt,n);
        t=(t%mod+mod)%mod;
        t*=power(k-1,n*i);
        t%=mod;
        ans+=t;
        ans%=mod;
    }
    cout<<ans<<endl;
	return 0;
}
