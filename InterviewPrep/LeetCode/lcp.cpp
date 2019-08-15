class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        string s;
        int m=10000000;
        for(int i=0;i<a.size();i++){
            m=min(m,(int)a[i].length());
        }
        for(int i=0;i<m;i++){
            bool flag=true;
            for(int j=1;j<a.size();j++){
                if(a[j][i]!=a[j-1][i]){
                    flag=false;
                    break;
                }
            }
            if(flag && a.size()){
                s.push_back(a[0][i]);
            }
            else{
                break;
            }
        }
        return s;
    }
};
