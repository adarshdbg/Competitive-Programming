class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        vector<int> s;
        if(n==0)return v;
        s.push_back(1);
        v.push_back(s);
        
        for(int i=1;i<n;i++){
            vector<int> vv;
            for(int j=0;j<v[v.size()-1].size();j++){
                vv.push_back(v[v.size()-1][j]+(j?v[v.size()-1][j-1]:0));
            }
            vv.push_back(1);
            v.push_back(vv);
        }
        return v;
    }
};
