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

inline ll nCr(ll n){
    return (n*(n-1))/2;
}

ll R[10],C[10];
ll r,c;

vector<string> dp[15][15];

void precompute(){
    // Fill the dp table where dp[i][j] represents the list of binary strings which has length i out of which j bits are set.
    dp[0][0].push_back((""));
    string str="0";
    for(ll i=1;i<15;i++){
        dp[i][0].push_back(str);
        str.push_back('0');
    }
    for(ll i=1;i<15;i++){
        for(ll j=1;j<=i;j++){
            // length i ** out of which j bits are set 
            for(string k:dp[i-1][j]){
                string t=k;
                t.push_back('0');
                dp[i][j].push_back(t);
            }
            for(string k:dp[i-1][j-1]){
                string t=k;
                t.push_back('1');
                dp[i][j].push_back(t);
            }
        }
    }
}

string ans_mat[10];

ll sum(string s){
    ll ans=0;
    for(char c:s){
        ans+=(c=='1');
    }
    return ans;
}

void print(){
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cout<<ans_mat[i][j]<<" ";
        }
        cout<<endl;
    }
}



void solve(string s[],ll i,ll &ans){
    if(i==r){
        // Base Case
        bool flag=true;
        ll c_cpy[10]{0};
        memset(c_cpy,0,sizeof(c_cpy));
        for(ll j=0;j<c;j++){
            for(ll l=0;l<r;l++){
                c_cpy[j]+=(s[l][j]=='1');
            }
        }
        for(ll j=0;j<c;j++){
            if(c_cpy[j]!=C[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
            for(ll j=0;j<c;j++)
            {
                ans_mat[j]=s[j];
            }
        }
        return ;
    }
    ll c_cpy[10]{0};
    for(ll j=0;j<i;j++){
        for(ll k=0;k<c;k++){
            c_cpy[k]+=(s[j][k]=='1');
        }
    }
    for(string k:dp[c][R[i]]){
        s[i]=k;
        ll c_cpy1[10]{0};
        for(ll l=0;l<c;l++){
            if(s[i][l]=='1')c_cpy1[l]++;
        }
        bool flag=false;
        for(ll l=0;l<c;l++){
            if(c_cpy[l]+c_cpy1[l]>C[l]){
                flag=true;
            }
        }
        if(flag)continue;
        solve(s,i+1,ans);
    }
}


int main() {

    IO; 
    
    ll tt;
    cin>>tt;

    precompute();
    // for(string s:dp[4][1]){
    //     cout<<s<<" ";
    // }
    while(tt--){
        cin>>r>>c;
        for(ll i=0;i<r;i++){
            cin>>R[i];
        }
        for(ll i=0;i<c;i++){
            cin>>C[i];
        }
        ll ans=0;
        string s[10];
        solve(s,0,ans);
        if(ans){
            if(ans==1){
                print();
            }
            else{
                cout<<ans<<endl;
            }
        }
        else{
            cout<<"No Possible Way"<<endl;
        }
    }
    // for(string s:dp[4][2]){
    //     cout<<s<<" ";
    // }
    // cout<<endl;
    
}
