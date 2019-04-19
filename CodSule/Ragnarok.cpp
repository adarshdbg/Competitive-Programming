#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define pair pair<ll,ll> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>



#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%ld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define INF 1e18
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct node {
	vi val;
	node* left;
	node* right;

	node() {
		val.resize(50,0);
		this->left = this->right = NULL;
	}
};





const ll mod =1e9+7;

ll power(ll a,ll b){
	if(b==0) return 1;
	ll s=power(a,b/2);
	s*=s;
	if(b&1) return s*a;
	return s;
}

ll f(ll i,ll n){


	ll cnt=0;
	while(n){
		if((n&1)==0){
			cnt++;
		}
		n>>=1;
	}

	return power(2,cnt);

}

int main(){

	
	ll a;
	cin>>a;
	// Count of numbers x such that a+x == (a^x)
	cout<<f(0,a)<<endl;

}