#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 ll n ;
  cin>>n;
  ll a[n+1],b[n];
  for(ll i=0;i<n+1;i++){
   cin>>a[i]; 
  }
  for(ll i=0;i<n;i++)cin>>b[i];
  ll ans=0;
  for(ll i=0;i<n;i++){
	if(i==-1){
    }
    else{
     if(b[i]>=a[i]){
         ans+=a[i],b[i]-=a[i],a[i]=0; 
         if(b[i]>=a[i+1]){
             ans+=a[i+1];
             a[i+1]=0;
         }
         else{
             ans+=b[i];
             a[i+1]-=b[i];
         }
     }
      else{
       ans+=b[i]; b[i]=0;
      }
    }
  }
  cout<<ans<<endl;
}
