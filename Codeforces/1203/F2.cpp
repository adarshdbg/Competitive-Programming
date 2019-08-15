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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

bool cmp1(pair<ll,ll> a,pair<ll,ll> b){
    return a.first+a.second>b.first+b.second;
}

map<pair<ll,ll>,ll> m;
ll f(pair<ll,ll> * p,ll n,ll i,ll sum){
    if(sum<0)return -1e10;
    if(i==n){
        return 0;
    }
    if(m.count(make_pair(i,sum))){
        return m[make_pair(i,sum)];
    }
    ll t=max((ll)0,f(p,n,i+1,sum));
    if(sum>=p[i].first){
        t=max(1+f(p,n,i+1,sum+p[i].second),t);
    }
    return m[make_pair(i,sum)]=t;
}
int main() {

    IO; 

    ll n;
    cin>>n;
    ll r;
    cin>>r;
    pair<ll,ll> p[n];
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        if(p[i].second>=0)cnt++;
    }
    ll count1=0,count2=0;
    pair<ll,ll> a[cnt],b[n-cnt];
    for(ll i=0;i<n;i++){
        if(p[i].second<0)b[count2++]=p[i];
        else{
            a[count1++]=p[i];
        }
    }
    sort(a,a+cnt);
    sort(b,b+n-cnt,cmp1);
    for(ll i=0;i<cnt;i++)p[i]=a[i];
    for(ll i=0;i<n-cnt;i++)p[i+cnt]=b[i];
    ll ans=f(p,n,0,r);
    cout<<ans<<endl;

}
