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
 
bool isposs(string a, string b,ll l){
    if(a.length()==b.length())return 0;
    ll left[a.length()],right[a.length()];
    left[0]=(a[0]==b[0]);
    ll j=(a[0]==b[0]);
    for(ll i=1;a[i];i++){
        if(b[j] && a[i]==b[j]){
            left[i]=left[i-1]+1;
            j++;
        }
        else{
            left[i]=left[i-1];
        }
    }
    right[a.length()-1]=(a[a.length()-1]==b[b.length()-1]);
    j=b.length()-1;
    if(right[a.length()-1])j--;
    for(ll i=a.length()-2;i>=0;i--){
        if(j>=0 && a[i]==b[j]){
            right[i]=right[i+1]+1;
            j--;
        }
        else{
            right[i]=right[i+1];
        }
    }
    for(ll i=0;i<=a.length()-l;i++){
        // i to i+l-1;
        if(i==0){
            if(i+l>=a.length())continue;
            if(right[i+l]<b.length())continue;
            else{
                return true;
            }
        }
        else if(i==a.length()-l){
            if(i && left[i-1]>=b.length())return true;
        }
        else{
            if(left[i-1]+right[i+l]>=b.length())return true;
        }
    }
    return false;
}
 
int main() {
 
    IO; 
 
    string a,b;
    cin>>a>>b;
    if(a.length()==b.length()){
        cout<<0<<endl;
        return 0;
    }
    ll si=0,ei=a.length()-1;
    ll ans=0;
    while(si<=ei){
        ll mid=(si+ei)>>1;
        if(isposs(a,b,mid)){
            ans=mid;
            si=mid+1;
        }
        else{
            ei=mid-1;
        }
    }
    
    cout<<ans<<endl;
}
