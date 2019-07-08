#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> v[100000];
ll par[100000][50];
ll depth[100000];

void dfs(ll u,ll parent,ll d=0){
    // DFS for computation of height and parent of each node
    par[u][0]=parent;
    depth[u]=d;
    for(ll i:v[u]){
        if(i!=parent){
            dfs(i,u,d+1);
        }
    }
}

ll lca(ll u,ll v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    ll diff=depth[u]-depth[v];
    // Take u and v to the same level 
    for(ll i=0;i<50;i++){
        if((diff>>i)&1){
            u=par[u][i];
        }
    }

    if(u==v){
        return v;
    }

    // Now u and v are at same level
    // And we just have to crawl up every time in powers of 2 until u and v becomes equal
    for(ll i=49;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

int main() {

    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    memset(par,-1,sizeof(par));
    dfs(0,-1,0);
    // Now calculate the parent Array ,par[i][j] represents (1<<j) th parent of ith node
    
    for(ll i=0;i<n;i++){
        for(ll j=1;j<50;j++){
            if(par[i][j-1]!=-1)
                par[i][j]=par[par[i][j-1]][j-1];
        }
    }

    ll u,v;
    cin>>u>>v;
    cout<<lca(u-1,v-1)+1<<endl;

}
