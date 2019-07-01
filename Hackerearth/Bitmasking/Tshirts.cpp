#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define mod 1000000007
#define ll long long 
vector<ll> v[101];
int n,a;char c;
ll dp[101][(1<<11)];
ll f(ll i,ll mask){
    if(i==101){
        return (mask==(1<<n)-1);
    }
    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    ll &res=dp[i][mask];
    
    bool flag=false;
    ll ans=0;
    ans+=f(i+1,mask);
    for(ll j:v[i]){
        
        if(!((1<<j)&mask)){
            ans+=(f(i+1,mask|(1<<j)));
            flag=true;
            ans%=mod;
        }
    }
    return res=ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&n);
		for(ll i=0;i<101;i++){
		    v[i].clear();   
		}
		for(int i=0;i<n;i++)
		{
		    a=-1;
			for(int j=0;;j++)
			{
			    int x=a;
				scanf("%d%c",&a,&c);
				if(a==x){
				    break;
				}
				v[a].push_back(i);
				if(c=='\n')break;
			}
		}
// 		for(ll i=1;i<101;i++){
// 		    if(v[i].size()){
// 		        cout<<i<<"-->";
// 		        for(ll j:v[i]){
// 		            cout<<j<< " ";
// 		        }
// 		        cout<<endl;
// 		    }
// 		}
		
		memset(dp,-1,sizeof(dp));
		cout<<f(1,0)<<endl;
	}
	return 0;
}
