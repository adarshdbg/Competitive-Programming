#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
 
int MAX=1e6+1;
const int mod = 1e9+7;
 
 
int power(int a,int b){
    if(b==0){
        return 1;
    }
    int s=power(a,b/2);
    s*=s;
    s%=mod;
    if(b&1)return (s*a)%mod;
    return s;
}
 
signed main() {
    fast;
    
    int n,m;
    cin>>n>>m;
    int r[n],c[m];
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int j=0;j<m;j++){
        cin>>c[j];
    }
    
    int final[n][m];
    memset(final,-1,sizeof(final));
    for(int i=0;i<n;i++){
        for(int j=0;j<r[i];j++){
            if(final[i][j]!=-1 && final[i][j]!=1){
                flag=false;
            }
            if(final[i][j]==-1){
                final[i][j]=1;
            }
        }
        if(r[i]!=m){
            if(final[i][r[i]]!=0 && final[i][r[i]]!=-1)flag=false;
            final[i][r[i]]=0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<c[i];j++){
            if(final[j][i]!=-1 && final[j][i]!=1)flag=false;
            if(final[j][i]==-1){
                final[j][i]=1;
            }
        }
        if(c[i]!=n){
            if(final[c[i]][i]!=0 && final[c[i]][i]!=-1)flag=false;
            final[c[i]][i]=0;
        }
    }
    if(flag==false){
        cout<<0<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnt+=(final[i][j]==-1);
        }
    }
    cout<<power(2,cnt)<<endl;
	return 0;
}
