#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
 
int MAX=1e6+1;
const int mod = 1e9+7;
 
int p[1000001]{0};
vector<int> f;
void solve(){
    p[2]=1;
    for(int i=3;i<MAX;i+=2)p[i]=1;
    for(int i=3;i*i<MAX;i+=2){
        if(p[i]){
            for(int j=i*i;j<MAX;j+=2*i){
                p[j]=0;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(p[i])f.push_back(i);
    }
}
 
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
 
int max_power(int a,int n){
    int ans=0;
    int b=a;
    while(n){
        ans+=(n/b);
        n/=b;
    }
    return ans;
}
 
signed main() {
    fast;
    
    int x,n;
    cin>>x>>n;
    solve();
    vector<int> fac;
    int pp=f[0],j=0;
    while(pp*pp<=x){
        if(x%pp==0){
            while(x%pp==0){
                x/=pp;
            }
            fac.push_back(pp);
        }
        j++;
        pp=f[j];
    }
    if(x!=1){
        fac.push_back(x);
    }
    int ans=1;
    for(int j:fac){
        ans*=power(j,max_power(j,n));
        ans%=mod;
    }
    cout<<ans<<endl;
    
    
	return 0;
}
