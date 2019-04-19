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












const ll mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TT=1;
    cin>>TT;
    while(TT--){
        ll M, n;
        cin >> M >> n;
        vector<ll> v(n);
        ll sum = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum -= v[i];
            pre = max(pre, sum);
        }

        ll h = M;
        for (int i = 0; i < n; i++) {
            h += v[i];
            if (h <= 0) {
                cout << i + 1 << endl;
                break;
            }
        }
        if (h <= 0) continue;

        if (sum <= 0) {
            cout << "never\n";
            continue;
        }

        ll full = (M - pre) / sum;
        M -= full * sum;
        
        ll sol = full * n;
        for (int i = 0;; i++) {
            M += v[i % n];
            sol++;
            if (M <= 0) {
                cout << sol << endl;
                break;
            }
        }
    }
    return 0;
}