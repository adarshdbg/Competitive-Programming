#include <bits/stdc++.h>
using namespace std;
#define ll long long 



int main() {
    
    ll tt;
    cin>>tt;
    ll cnt=0;
    while(tt--){
        ll n,r,c,x,y;
        cin>>n>>r>>c>>x>>y;
        string s;
        cin>>s;
        // cout<<s<<" ";
        map<pair<ll,ll>,ll> m;
        m[make_pair(x,y)]=true;
        for(ll i=0;s[i];i++){
            if(s[i]=='E'){
                ll t=y;
                // binary search on [12...y-1]
                ll si=y+1,ei=c;
                ll ans=y+1;
                while(si<=ei){
                    ll mid=(si+ei)/2;
                    if(m.count(make_pair(x,mid))==0){
                        ans=mid;
                        ei=mid-1;
                    }
                    else{
                        si=mid+1;
                    }
                }
                y=ans;
            }
            else if(s[i]=='W'){
                ll si=1,ei=y-1;
                ll ans=1;
                while(si<=ei){
                    ll mid=(si+ei)/2;
                    if(!m.count(make_pair(x,mid))){
                        ans=mid;
                        si=mid+1;
                    }
                    else{
                        ei=mid-1;
                    }
                }
                y=ans;
            }
            else if(s[i]=='N'){
                ll si=1,ei=x-1;
                ll ans=1;
                while(si<=ei){
                    ll mid=(si+ei)/2;
                    if(m.count(make_pair(mid,y))==0){
                        ans=mid;
                        si=mid+1;
                    }
                    else{
                        ei=mid-1;
                    }
                }
                x=ans;
            }
            else{
                ll si=x+1;
                ll ei=r;
                ll ans=x+1;
                while(si<=ei){
                    ll mid=(si+ei)/2;
                    if(m.count(make_pair(mid,y))==0){
                        ans=mid;
                        ei=mid-1;
                    }
                    else{
                        si=mid+1;
                    }
                }
                x=ans;
            }
            m[make_pair(x,y)]=true;
            // cout<<x<<" "<<y<<endl;
        }
        cout<<"Case #"<<++cnt<<": ";
        cout<<x<<" "<<y<<endl;
    }

}
