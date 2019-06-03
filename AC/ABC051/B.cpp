#include<bits/stdc++.h>
using namespace std;
int main(){

    int k,s;
    cin>>k>>s;
    int ans=0;
    map<pair<int,pair<int,int>>,int> a;
    for(int i=0;i<=k;i++){
        map<int,int> m;
        for(int j=0;j<=i;j++){
            m[j]++;
        }
        for(int j=i;j<=k;j++){
            int n=i+j;
            if(m.count(s-n)){
                a[make_pair(i,make_pair(j,s-n))]++;
            }
        }
    }
    for(auto i: a){
        map<int,int> my;
        my[i.first.first]++;
        my[i.first.second.first]++;
        my[i.first.second.second]++;
        if(my.size()==3){
            ans+=6*i.second;
        }
        else if(my.size()==2){
            ans+=3*i.second;
        }
        else ans+=i.second;
    }
    cout<<ans<<endl;

}
