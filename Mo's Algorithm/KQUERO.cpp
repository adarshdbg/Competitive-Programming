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

int main() {

    IO; 

    ll n;
    cin>>n;
    ll a[n];
    loop(i,0,n){
        cin>>a[i];
    }
    ll block=sqrt(n);
    vector<vector<ll>> b(block+1);

    for(ll i=0;i<n;i++){
        b[i/block].push_back(a[i]);
    }

    for(ll i=0;i<=block;i++){
        sort(b[i].begin(),b[i].end());
    }
    ll ans=0;
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll x;
        cin>>x;
        l--;
        r--;
        
        ans=0;
        if(r>=l){
            
            if((l/block) ==(r/block)){
                for(ll j=l;j<=r;j++){
                    ans+=(a[j]>x);
                }
            }
            else{
                ll temp=l/block;
                if(l%block!=0){
                    temp++;
                }
                ll i;
                for(i=l;i<temp*block;i++){
                    ans+=(a[i]>x);
                }
                while(i+block-1<=r){
                    ll index=i/block;
                    // Now, we have to search in block no 'index'
                    ans+=b[index].end()-upper_bound(b[index].begin(),b[index].end(),x);
                    i+=block;
                }
                while(i<=r){
                    ans+=(a[i]>x);
                    i++;
                }
            }
            
        }
        cout<<ans<<endl;
    }

}
