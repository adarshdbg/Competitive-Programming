#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
signed main()
{
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(flag){
            for(int j=0;j<n;j++){
                if(j%2==0)cout<<'B';
                else cout<<'W';
            }
            cout<<endl;
        }
        else{
            for(int j=0;j<n;j++){
                if(j%2==0)cout<<'W';
                else cout<<'B';
            }
            cout<<endl;
        }
        flag=(!flag);
    }
    return 0;
}
