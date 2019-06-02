#include<bits/stdc++.h>
class Solution {
public:
    string removeDuplicates(string S) {
        if(S.length()==0){
            string s;
            return s;
        }
        stack<char> s;
        s.push(S[0]);
        for(int i=1;S[i];i++){
            if(s.empty()){
                s.push(S[i]);
            }
            else if(s.top()!=S[i]){
                s.push(S[i]);
            }
            else{
                while(!s.empty() && s.top()==S[i]){
                    s.pop();
                }
            }
        }
        string a;
        while(!s.empty()){
            a.push_back(s.top());
            s.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};
