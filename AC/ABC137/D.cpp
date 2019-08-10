#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int, int> P;

int n, m;
vector<P> sal;
priority_queue<int> unchi;

bool cmp(const P&, const P&);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        sal.push_back(P(a, b));
    }

    sort(sal.begin(), sal.end(), cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        while (!sal.empty() && sal.back().first == i) {
            unchi.push(sal.back().second);
            sal.pop_back();
        }
        
        if (!unchi.empty()) {
            ans += unchi.top();
            unchi.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}


bool cmp(const P &a, const P &b) {
    if (a.first > b.first) return true;
    else return false;
}
