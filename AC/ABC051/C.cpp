#include<bits/stdc++.h>
using namespace std;
int main(){

    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    string s;
    if(sx==tx && sy==ty){
        cout<<"";
        return 0;
    }
    for(int i=0;i<abs(sx-tx);i++){
        s.push_back('R');
    }
    for(int i=0;i<abs(sy-ty);i++){
        s.push_back('U');
    }
    for(int i=0;i<abs(sx-tx);i++){
        s.push_back('L');
    }
    for(int i=0;i<abs(sy-ty);i++){
        s.push_back('D');
    }
    s.push_back('D');
    for(int i=0;i<abs(sx-tx)+1;i++){
        s.push_back('R');
    }
    for(int i=0;i<abs(sy-ty)+1;i++){
        s.push_back('U');
    }
    s.push_back('L');
    s.push_back('U');
    for(int i=0;i<abs(sx-tx)+1;i++){
        s.push_back('L');
    }
    for(int i=0;i<abs(sy-ty)+1;i++){
        s.push_back('D');
    }
    s.push_back('R');
    // for(int i=0;i<abs(sx-t))
    cout<<s<<endl;
}
