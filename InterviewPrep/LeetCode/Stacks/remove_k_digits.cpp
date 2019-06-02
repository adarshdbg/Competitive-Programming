class Solution {
public:
    string removeKdigits(string a, int k) {
        if(k>=a.length()){
            return "0";
        }
        stack<char> s;
        s.push(a[0]);
        int cnt=0;
        for(int i=1;a[i];i++){
            if(s.empty() || s.top()<=a[i] || cnt>=k){
                s.push(a[i]);
            }
            else{
                while(!s.empty() && (cnt<k) && s.top()>a[i]){
                    cnt++;
                    s.pop();
                }
                s.push(a[i]);
            }
        }
        string b;
        bool flag;
        flag=false;
        while(!s.empty()){
            if(s.top()!='0')flag=true;
            b.push_back(s.top());
            s.pop();
        }
        if(flag==false)return "0";int i=0;
        reverse(b.begin(),b.end());
        while(b[i] && b[i]=='0'){
            i++;
        }
        return b.substr(i,b.length()-(k-cnt));
    }
};
