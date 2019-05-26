#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
map <ll, int> dp;
int DP(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp.count(n)) return dp[n];
    int res = 0;
    if (n & 1) res = (DP(n / 2) * 2 % mod + DP(n / 2 - 1)) % mod;
    else res = (DP(n / 2) + DP(n / 2 - 1) * 2 % mod) % mod;
    return dp[n] = res;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    cout << DP(n) << endl;
    return 0;
}
