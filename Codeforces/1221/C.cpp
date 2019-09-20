#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int f(int ans,int c,int m,int x){
    if(min(c,m)<ans)return false;
    int  MIN=ans;
    int MAX=c-ans+m-ans;
    return (x+MAX>=ans);
}
 
signed main()
{
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    
    int q;
    cin>>q;
    while(q--){
        int c,m,x;
        cin>>c>>m>>x;
        int ans=0;
        int si=0,ei=1e12;
        while(si<=ei){
            int mid=(si+ei)>>1;
            if(f(mid,c,m,x)){
                ans=mid;
                si=mid+1;
            }
            else
                ei=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
3
0
0
1
3
*/
