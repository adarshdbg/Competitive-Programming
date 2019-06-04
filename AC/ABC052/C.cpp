#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vd(T) vector<vector<T>>
#define v(T) vector<T>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define mp make_pair
#define NN 100005
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define DEBUG cout<<"***********DEBUGGING***********"<<endl
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
ll power(ll a,ll b){ if(b==0) return 1; ll s=power(a,b/2); s*=s;if(b&1) return s*a; return s;}
ll powermod(ll a,ll b,ll m){ if(b==0) return 1; ll s=power(a,b/2);s*=s; s%=m; if(b&1) return (s*a)%m; return s;}
inline int add(ll a,ll b,ll m=0){
    if(m==0) return a+b;
    return (a%m+b%m)%m;
}

inline int sub(ll a,ll b ,ll m=0){
    if(m==0) return a-b;
    return ((a%m-b%m)%m+m)%m;
}

inline int mul(ll a,ll b,ll m=0){
    if(m==0)return (a*b);
    return ((a%m)*(b%m))%m;
}

inline int div(ll a,ll b,ll m=0){
    if(m==0) return a/b;
    return ((a%m)*(powermod(a,b,m-2)%m))%m;
}

bool isopen(char c){
    return ((c=='(')||(c=='{')||(c=='['));
}

ll longest_balanced_parenthesis(string a,ll n){
    stack<char> s;
    ll start=0;
    ll ans=0,m=0;
    for(ll i=0;i<n;i++){
        if(isopen(a[i])){
            s.push(a[i]);
        }
        else{
            if(isopen(a[i])|| s.empty()){
                m=max(m,ans);
                continue;
            }
            else{
                s.pop();
                ans+=2;
                m=max(ans,m);
            }
        }
    }

    return m;

}

ll setup_k(ll *a,ll k){
  ordered_set x;
  // Now , insert and then check number of integers less than k by just using x.order_of_key(k+1)
}
ll pr[1000001];
vector<vector<ll>> f(1000001);
ll solve(){
    fill(pr,pr+1000001,0);
    for(ll i=3;i<1000001;i++)pr[i]=1;
    pr[2]=1;
    for(ll i=2;i<1000001;i+=2)f[i].push_back(2);
    for(ll i=3;i*i<1000001;i+=2){
        if(pr[i]){
            for(ll j=i*i;j<1000001;j+=2*i){
                pr[j]=0;
            }
            for(ll j=i;j<1000001;j+=i){
                f[j].push_back(i);
            }
        }
    }
}


int main() {

    IO; 
    solve();
    ll n;
    cin>>n;
    map<ll,ll> m;
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ll t=i;
        
        for(auto j:f[i]){
            ll cnt=0;
            while(t%j==0){
                t/=j;
                cnt++;
            }
            m[j]+=cnt;
        }
        if(t!=1){
            m[t]+=1;
        }
    }
    for(auto i:m){
        ans*=(i.second+1);
        ans%=mod;
    }
    cout<<ans<<endl;
    

}
