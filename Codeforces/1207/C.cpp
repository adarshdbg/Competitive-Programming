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
#define ld long double
map<pair<ll,bool>,ld> m;

ll a,b;
ld f(string s,ll i,ll n,bool flag){
    if(i==n){
        if(flag==0){
            return b;
        }
        return 3*1e13;
    }
    if(m.count(make_pair(i,flag)))return m[make_pair(i,flag)];
    if((s[i]=='1') && !flag){
        return m[make_pair(i,flag)]=3*1e13;
    }
    ld res=0;
    res=f(s,i+1,n,flag)+a;
    res+=b*(flag+1);
    if(flag==0){
        ld ans1=f(s,i+1,n,1)+a*2;
        ans1+=b;
        res=min(res,ans1);
    }
    else{
        ld ans=f(s,i+1,n,0)+2*a;
        ans+=2*b;
        if(s[i]!='1')
            res=min(res,ans);
    }
    return m[make_pair(i,flag)]=res;
}

int main() {

    IO; 
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
    
        cin>>n>>a>>b;
        string s;
        cin>>s;
        ll dp[n][2]{0};
        dp[0][0]=b+a;
        dp[0][1]=2*a+2*b;
        for(ll i=1;i<n;i++){
            dp[i][0]=dp[i][1]=1e14;
            if(s[i]=='0'){
                dp[i][0]=min(dp[i-1][1]+2*a+b,dp[i-1][0]+b+a);
            }
            dp[i][1]=min(dp[i-1][1]+2*b+a,dp[i-1][0]+2*a+b*3);
        }
        cout<<dp[n-1][0]+b<<endl;
    }
    
}
