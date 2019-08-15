class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(0);
        unordered_map<int,int> m;
        for(int i:a)m[i]++;
        for(auto i:m)if(i.second>=2)return true;
        return false;
    }
};
