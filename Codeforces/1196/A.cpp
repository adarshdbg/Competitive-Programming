#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vd(T) vector<vector<T>>
#define v(T) vector<T>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define read4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
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
  return 0;
}
 
int main() {
 
    IO; 
 
    ll q;
    cin>>q;
    while(q--){
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        // a b
        sort(a,a+3);
        ll ans=0;
        // a[2]
        // x+a[0]=a[1]+a[2]-x
        // 2x=a[1]+a[2]-a[0]
        ll x=(a[1]+a[2]-a[0]);
        x/=2;
        ans=min(a[0]+x,a[1]+a[2]-x);
        // x+a[1]=a[0]+a[2]-x
        x=(a[2]+a[0]-a[1])/2;
        ll ans1=0,ans2=0;
        ans1=min(a[1]+x,a[0]+a[1]-x);
        x=(a[0]+a[1]-a[2])/2;
        ans2=min(a[2]+x,a[0]+a[1]-x);
        ans=max(ans,max(ans1,ans2));
        cout<<ans<<endl;
    }
 
}
