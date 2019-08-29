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
 
ll cmp(pp(ll) a,pp(ll) b){
    return a.second>b.second;
}
 
bool isPossible(map<ll,vector<ll>> a,ll k){
    for(ll i=0;i<k;i++){
        ll b[a.size()]{0};
        for(ll j=0;j<a.size();j++){
            for(ll l:a[j]){
                if(l==i+1)b[j]++;
            }
        }
        for(ll j=0;j<a.size();j++){
            for(ll l=0;l<a.size();l++){
                if(abs(b[j]-b[l])>1)return false;   
            }
        }
    }
    return true;
}
 
int main() {
 
    IO; 
 
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll a[n];
    ll b=1e12;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b=min(b,a[i]);
    }
    bool flag=false;
    map<ll,vector<ll>> m;
    for(ll i=0;i<n;i++){
        m[i].clear();
    }
    ll color=1;
    while(1){
        for(ll i=0;i<n;i++){
            if(a[i]>0){
                m[i].push_back(color);
                a[i]--;
            }
        }
        for(ll i=0;i<n;i++){
            if(a[i]){
                flag=true;
            }
        }
        if(flag){
            flag=false;
        }
        else{
            break;
        }
        
        color++;
        if(color>k)color=1;
    }
    if(!isPossible(m,k)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(ll i=0;i<n;i++){
            for(auto j:m[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    
}
