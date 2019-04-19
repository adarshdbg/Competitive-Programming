#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
// #define INF 1e18
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








int x[2010][30], y[2010][30], dp[2010][2010];
const int INF = 1e9;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int i, j, k, l, n, m, a, b, c, d;
		string s,t;
	    cin>>a>>b>>c>>d>>s>>t;

	    n = s.length();
	    m = t.length();

	    for (i = 1; i <= n; i++) {
	        for (j = 0; j < 26; j++)
	            x[i][j] = x[i - 1][j];
	        if (i > 1)
	            x[i][s[i - 2] - 'a'] = i - 1;
	    }
	    for (i = 1; i <= m; i++) {
	        for (j = 0; j < 26; j++)
	            y[i][j] = y[i - 1][j];
	        if (i > 1)
	            y[i][t[i - 2] - 'a'] = i - 1;
	    }
	    for (i = 0; i <= n; i++)
	        for (j = 0; j <= m; j++)
	            if (i || j) {
	                dp[i][j] = INF;
	                if (j)
	                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + a);
	                if (i)
	                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);
	                if (i && j)
	                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]) * c);
	                if ((k = x[i][t[j - 1] - 'a']) && (l = y[j][s[i - 1] - 'a']))
	                    dp[i][j] = min(dp[i][j], dp[k - 1][l - 1] + d + (i - k - 1) * b + (j - l - 1) * a);
	            }
	    cout<<dp[n][m]<<'\n';	
	}
    return 0;
}