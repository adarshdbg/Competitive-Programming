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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll rgb[n]{0},gbr[n]{0},brg[n]{0};
        for(ll i=0;i<n;i++){
            if(i==0){
                rgb[i]=(s[i]!='R');
            }
            else{
                if(i%3==0)
                rgb[i]=rgb[i-1]+(s[i]!='R');
                else if(i%3==1)
                rgb[i]=rgb[i-1]+(s[i]!='G');
                else
                rgb[i]=rgb[i-1]+(s[i]!='B');
            }
        }
        for(ll i=0;i<n;i++){
            if(i==0){
                gbr[i]=(s[i]!='G');
            }
            else{
                if(i%3==0){
                    gbr[i]=gbr[i-1]+(s[i]!='G');
                }
                else if(i%3==1){
                    gbr[i]=gbr[i-1]+(s[i]!='B');
                }
                else{
                    gbr[i]=gbr[i-1]+(s[i]!='R');
                }
            }
        }
        for(ll i=0;i<n;i++){
            if(i==0){
                brg[i]=(s[i]!='B');
            }
            else{
                if(i%3==0){
                    brg[i]=brg[i-1]+(s[i]!='B');
                }
                else if(i%3==1){
                    brg[i]=brg[i-1]+(s[i]!='R');
                }
                else{
                    brg[i]=brg[i-1]+(s[i]!='G');
                }
            }
        }
        ll ans=1e9;
        for(ll i=0;i<=n-k;i++){
            // i to (i+k)
            // if we start this subarray as RGBRGB...
            if(1){
                //1 
                ans=min(ans,rgb[i+k-1]-(i?rgb[i-1]:0));
            }
            if(1){
                //2 
                ans=min(ans,gbr[i+k-1]-(i?gbr[i-1]:0));
            }
            if(1){
                ans=min(ans,brg[i+k-1]-(i?brg[i-1]:0));
            }
        }
        cout<<ans<<endl;
    }
    

}
