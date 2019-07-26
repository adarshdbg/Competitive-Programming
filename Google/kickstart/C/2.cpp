#include<bits/stdc++.h>
using namespace std;
#define ll int
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

inline int div(ll a,   ll b,ll m=0){
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


ll MIN[301][301][301],MA[301][301][301];

int main() {

    IO; 

    ll tt;
    scanf("%d",&tt);
    for(ll z=1;z<=tt;z++){
        ll r,c,k;
        scanf("%d%d%d",&r,&c,&k);
        vector<ll> a[r];
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                ll x;
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }
        memset(MIN,(ll)1e17,sizeof(MIN));
        memset(MA,INT_MIN,sizeof(MA));
        
        

        // for(ll i=0;i<r;i++){
        //     for(ll j=0;j<c;j++){
        //         cout<<MIN[i][j][c-1]<<" ";
        //     }
        //     cout<<endl;
        // }
        bool flag=false;
        ll ANS=0;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                // start with j in ith row
                MIN[i][j][j]=a[i][j];MA[i][j][j]=a[i][j];
                for(ll l=j+1;l<c;l++){
                    MIN[i][j][l]=min(a[i][l],MIN[i][j][l-1]);
                    MA[i][j][l]=max(a[i][l],MA[i][j][l-1]);
                }
            }
        }

        for(ll i=0;i<c;i++){
            for(ll j=i;j<c;j++){
                ll b[r];
                for(ll l=0;l<r;l++){
                    ll s1=MIN[l][i][j];
                    ll s2=MA[l][i][j];
                    b[l]=((s2-s1)<=k);
                }
                ll ans=0;
                ll curr=0;
                for(ll l=0;l<r;l++){
                    if(b[l]){
                        curr++;
                        ans=max(ans,curr);
                    }
                    else{
                        curr=0;
                    }
                }
                ANS=max(ANS,ans*(j-i+1));
            }
        }

        printf("Case #%d: %d\n",z,ANS);
        // cout<<query1(MA[3],0,c-1,1,2,1)-query(MIN[3],0,c-1,1,2,1)<<endl;
    }
    

}
