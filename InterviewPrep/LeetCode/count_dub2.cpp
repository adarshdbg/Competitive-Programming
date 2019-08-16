class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++){
            if(m.count(a[i])){
                if(i-m[a[i]]<=k)return true;
            }
            m[a[i]]=i;
        }
        return false;
    }
};
