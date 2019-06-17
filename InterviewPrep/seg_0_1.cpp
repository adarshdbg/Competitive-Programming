#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll i=0,j=0;
  while(i<n && j<n){
    while(i<j && a[i]==0)i++;
    while(i<j && a[j]==1)j--;
    if(i<j){
      swap(a[i],a[j]);
      i++;
      j--;
    }
  }
  
  // Now , we have segregated 0s and 1s
  for(ll i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;

}
