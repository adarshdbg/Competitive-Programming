class Solution {
public:
    void f(int n,int cnt,string s,vector<string> &a){
        if(n==0){
            if(cnt==0)a.push_back(s);
            return ;
        }
        string t=s;
        s+='(';
        f(n-1,cnt+1,s,a);
        if(cnt>0){
            t+=')';
            f(n-1,cnt-1,t,a);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        f(2*n,0,s,ans);
        return ans;
    }
};
