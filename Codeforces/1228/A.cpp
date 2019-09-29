#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
 
 
const int mod = 1e9+7;
 
bool f(int n){
    unordered_map<int,int> m;
    while(n){
        if(m.count(n%10))return false;
        m[n%10]++;
        n/=10;
    }
    return true;
}
 
signed main() {
    fast;
    
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(f(i)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
	return 0;
}
