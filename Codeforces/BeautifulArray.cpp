#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast() ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
const int MAX=3e5+7;
int dp[MAX][2][2][2];
int n,a[MAX],x;
int f(int pos,bool running, bool used,bool started){
 if(pos==n){
   return 0;
 }
 int &res=dp[pos][running][used][started];
 if(res!=-1){
   return res;
 }
 res=0;
 
 if(started){
   if(running){
     res=max(res,f(pos+1,0,1,started)+max(a[pos],a[pos]*x));
     res=max(res,a[pos]*x);
     res=max(res,f(pos+1,1,1,1)+a[pos]*x);
   }
   else{
     res=max(res,f(pos+1,0,used,1)+a[pos]);
     if(!used){
	res=max(res,f(pos+1,1,1,1)+a[pos]*x);
	res=max(res,f(pos+1,1,1,1)+a[pos]);
     }
   }	
 }
 else{
  res=max(res,f(pos+1,0,0,1)+a[pos]);
  res=max(res,f(pos+1,0,0,0));
  res=max(res,f(pos+1,1,1,1)+a[pos]*x);
  res=max(res,f(pos+1,1,1,1)+a[pos]);
 }
 if(res<0)res=0;
 return res;
}

signed main(){
  
 fast();
 
 cin>>n>>x;
 
 for(int i=0;i<n;i++){
   cin>>a[i];
 }

 // now find the answer ,i mean maximum subarray sum by multiplying the subarray by x if you need
 memset(dp,-1,sizeof(dp));
 int b=f(0,0,0,0);
 //memset(dp,-1,sizeof(dp));
 //b=max(b,f(0,0,0,1));
 cout<<b<<endl; 

}


