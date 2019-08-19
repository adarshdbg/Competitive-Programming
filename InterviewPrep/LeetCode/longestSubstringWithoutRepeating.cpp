class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int l=0;
        int len=0;
        int ans=0;
        for(int i=0;s[i];i++){
            int k=l;
            while(m.count(s[i])){
                m[s[k]]--;
                len--;
                if(m[s[k]]==0)m.erase(s[k]);
                k++;
            }
            l=k;
            m[s[i]]++;
            len++;
            ans=max(ans,len);
        }
        return ans;
    }
};
