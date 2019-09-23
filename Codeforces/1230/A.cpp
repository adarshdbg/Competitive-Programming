#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
const int mod=1e9+7;
 
bool ans=false;
int a[4];
void f(int i,int s){
    if(i==4){
        if(s==0)ans= true;
        return ;
    }   
    if(s>=a[i])f(i+1,s-a[i]);
    f(i+1,s);
}
 
 
signed main() {
 
    IO; 
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    int s=a[0]+a[1]+a[2]+a[3];
    if(s%2){
        cout<<"NO"<<endl;
    }
    else{
        f(0,s/2);
        
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
 
}
