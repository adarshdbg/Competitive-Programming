class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]{0};
        for(int i=0;s[i];i++){
            a[s[i]-'a']++;
        }
        for(char i:t){
            a[i-'a']--;
        }
        for(int i:a){
            if(i)return false;
        }
        return true;
    }
};
