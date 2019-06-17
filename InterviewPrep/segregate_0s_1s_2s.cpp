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
  
  ll low=0,mid=0,high=n-1;
  while(mid<n){
    if(a[mid]==0){
      swap(a[mid],a[low]);
      low++;
      mid++;
    }
    else if(a[mid]==1)mid++;
    else{
      swap(a[high],a[mid]);
      high--;
    }
  }
  // Print the array
}
