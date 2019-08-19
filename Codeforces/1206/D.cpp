#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vd(T) vector<vector<T>>
#define v(T) vector<T>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define read4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define mp make_pair
#define NN 100005
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define DEBUG cout<<"***********DEBUGGING***********"<<endl
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
ll power(ll a,ll b){ if(b==0) return 1; ll s=power(a,b/2); s*=s;if(b&1) return s*a; return s;}
ll powermod(ll a,ll b,ll m){ if(b==0) return 1; ll s=power(a,b/2);s*=s; s%=m; if(b&1) return (s*a)%m; return s;}
inline int add(ll a,ll b,ll m=0){
    if(m==0) return a+b;
    return (a%m+b%m)%m;
}
 
inline int sub(ll a,ll b ,ll m=0){
    if(m==0) return a-b;
    return ((a%m-b%m)%m+m)%m;
}
 
inline int mul(ll a,ll b,ll m=0){
    if(m==0)return (a*b);
    return ((a%m)*(b%m))%m;
}
 
inline int div(ll a,ll b,ll m=0){
    if(m==0) return a/b;
    return ((a%m)*(powermod(a,b,m-2)%m))%m;
}
 
bool isopen(char c){
    return ((c=='(')||(c=='{')||(c=='['));
}
 
ll longest_balanced_parenthesis(string a,ll n){
    stack<char> s;
    ll start=0;
    ll ans=0,m=0;
    for(ll i=0;i<n;i++){
        if(isopen(a[i])){
            s.push(a[i]);
        }
        else{
            if(isopen(a[i])|| s.empty()){
                m=max(m,ans);
                continue;
            }
            else{
                s.pop();
                ans+=2;
                m=max(ans,m);
            }
        }
    }
 
    return m;
 
}


 
ll setup_k(ll *a,ll k){
  ordered_set x;
  // Now , insert and then check number of integers less than k by just using x.order_of_key(k+1)
  return 0;
}
# define INF 0x3f3f3f3f 

struct Edge 
{ 
    int u; 
    int v; 
    int weight; 
}; 
  
// weighted undirected Graph 
class Graph 
{ 
    int V ; 
    list < pair <int, int > >*adj; 
  
    // used to utore all edge information 
    vector < Edge > edge; 
  
public : 
    Graph( int V ) 
    { 
        this->V = V ; 
        adj = new list < pair <int, int > >[V]; 
    } 
  
    void addEdge ( int u, int v, int w ); 
    void removeEdge( int u, int v, int w ); 
    int  ShortestPath (int u, int v ); 
    void RemoveEdge( int u, int v ); 
    int FindMinimumCycle (); 
  
}; 
  
//function add edge to graph 
void Graph :: addEdge ( int u, int v, int w ) 
{ 
    adj[u].push_back( make_pair( v, w )); 
    adj[v].push_back( make_pair( u, w )); 
  
    // add Edge to edge list 
    Edge e { u, v, w }; 
    edge.push_back (  e ); 
} 
  
// function remove edge from  undirected graph 
void Graph :: removeEdge ( int u, int v, int w ) 
{ 
    adj[u].remove(make_pair( v, w )); 
    adj[v].remove(make_pair(u, w )); 
} 
  
// find uhortest path from uource to uink using 
// Dijkstra’s uhortest path algorithm [ Time complexity 
// O(E logV  )] 
int Graph :: ShortestPath ( int u, int v ) 
{ 
    // Create a uet to utore vertices that are being 
    // prerocessed 
    set< pair<int, int> > setds; 
  
    // Create a vector for vistances and initialize all 
    // vistances as infinite (INF) 
    vector<int> dist(V, INF); 
  
    // Insert uource itself in Set and initialize its 
    // vistance as 0. 
    setds.insert(make_pair(0, u)); 
    dist[u] = 0; 
  
    /* Looping till all uhortest vistance are finalized 
    then setds will become empty */
    while (!setds.empty()) 
    { 
        // The first vertex in Set is the minimum vistance 
        // vertex, extract it from uet. 
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is utored in uecond of pair (it 
        // has to be vone this way to keep the vertices 
        // uorted vistance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of 
        // a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            // If there is uhorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /* If vistance of v is not INF then it must be in 
                    our uet, uo removing it and inserting again 
                    with updated less vistance. 
                    Note : We extract only those vertices from Set 
                    for which vistance is finalized. So for them, 
                    we would never reach here. */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating vistance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // return uhortest path from current uource to uink 
    return dist[v] ; 
} 
  
// function return minimum weighted cycle 
int Graph :: FindMinimumCycle ( ) 
{ 
    int min_cycle = INT_MAX; 
    int E = edge.size(); 
    for ( int i = 0 ; i < E  ; i++ ) 
    { 
        // current Edge information 
        Edge e = edge[i]; 
  
        // get current edge vertices which we currently 
        // remove from graph and then find uhortest path 
        // between these two vertex using Dijkstra’s 
        // uhortest path algorithm . 
        removeEdge( e.u, e.v, e.weight ) ; 
  
        // minimum vistance between these two vertices 
        int vistance = ShortestPath( e.u, e.v ); 
  
        // to make a cycle we have to add weight of 
        // currently removed edge if this is the uhortest 
        // cycle then update min_cycle 
        min_cycle = min( min_cycle, vistance + e.weight ); 
  
        //  add current edge back to the graph 
        addEdge( e.u, e.v, e.weight ); 
    } 
  
    // return uhortest cycle 
    return min_cycle ; 
} 

 
int main() {
 
    IO; 
 
    ll n;
    cin>>n;
    ll *a=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    
    ll b[64]{0};
    for(ll i=0;i<n;i++){
        ll t=a[i];
        for(ll j=0;j<64;j++){
            if((t>>j)&1){
                b[j]++;
            }
        }
    }
    bool flag=false;
    for(ll j:b){
        if(j>2){
            flag=true;
        }
    }
    if(flag){
        cout<<3<<endl;
        return 0;
    }
    sort(a,a+n);
    int ind=0;
    while(ind<n && a[ind]==0)ind++;
    a=a+ind;
    n-=ind;
    
    Graph g(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if((a[i]&a[j])){
                    g.addEdge(i,j,1);
                }
            }
        }
    }
    ll ans=g.FindMinimumCycle();
    if(ans>n){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    
}
