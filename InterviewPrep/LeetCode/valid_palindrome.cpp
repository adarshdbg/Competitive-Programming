class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0)return true;
        string a;
        for(auto i:s){
            if((i>='a' && i<='z')||(i>='A' && i<='Z') || (i>='0' && i<='9')){
                if((i>='A' && i<='Z'))a.push_back(i-'A'+'a');
                else{
                    a.push_back(i);
                }
            }
        }
        string b=a;
        // cout<<a<<endl;
        reverse(a.begin(),a.end());
        return (a==b);
    }
};
