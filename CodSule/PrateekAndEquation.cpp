#include<bits/stdc++.h>
using namespace std;
#define ll long long int 



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









ll n, bb;
int mod, a, b, bpn;
int C[800][800];
int ans[800], oans[800];

int modPow(ll a, ll n) {
  a %= mod;
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    n >>= 1;
  }
  return res;
}

void Calc(ll n) {

  if (n == 0) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1 % mod;
    bpn = 1 % mod;
    return;
  }

  if (n % 2 == 0) {

    Calc(n - 1);
    bpn = (1ll * bpn * b) % mod;

    int np = 1;
    n %= mod;
    for (int i = 0; i <= a; ++i) {
      ans[i] = (ans[i] + 1ll * np * bpn) % mod;
      np = (1ll * np * n) % mod;
    }
    return;
  }

  ll m = (n + 1) / 2;
  Calc(m - 1);

  memcpy(oans, ans, sizeof(int) * (a + 1));
  int bpm = (1ll * bpn * b) % mod;
  bpn = (1ll * bpm * bpn) % mod;

  m %= mod;
  for (int i = 0; i <= a; ++i) {
    int pm = 1;
    for (int j = i; j >= 0; --j) {

      int now = (1ll * C[i][j] * pm) % mod;
      now = (1ll * now * oans[j]) % mod;
      now = (1ll * now * bpm) % mod;
      pm = (pm * m) % mod;
      ans[i] = (ans[i] + now) % mod;
    }
  }
}
void Solve() {
  scanf("%lld%d%lld%d", &n, &a, &bb, &mod);
  b = bb % mod;
  if (b < 0)
    b += mod;

  for (int i = 0; i <= a; ++i) {
    C[i][0] = 1 % mod;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  Calc(n);
  printf("%d\n", ans[a]);
}

int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--)
    Solve();
  return 0;
}
