class Solution {
public:
    vector<int> twoSum(vector<int>& a, int s) {
        unordered_map<int,int> m;
        // if(a.size()==0)
        m[a[0]]=1;
        for(int i=1;i<a.size();i++){
            if(m.count(s-a[i])){
                vector<int> c={m[s-a[i]],i+1};
                return c;
            }
            m[a[i]]=i+1;
        }
        return vector<int>{0,0};
    }
};
