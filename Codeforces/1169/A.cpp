#include <iostream>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    ll n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    bool ans=false;
    while(a!=x && b!=y){
        if(a==b){
            ans=true;
            break;
        }
        a=a+1;
        if(a>n)a=1;
        b--;
        if(b<=0)b=n;
        if(a==b){
            ans=true;
            break;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
	return 0;
}
