#include <iostream>
#include <vector>
#include <string>
#include <sstream>  

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> s;
        stringstream ss(str); // Turn the string into a stream.
        string tok;

        while(getline(ss, tok,' ')) {
            s.push_back(tok);
        }
        unordered_map<char,string> m;
        map<string,int> mm;
        if(s.size()!=pattern.length())return false;
        for(int i=0;pattern[i];i++){
            if(m.count(pattern[i])){
                if(m[pattern[i]]!=s[i])return false;
            }
            else{
                if(mm.count(s[i]))return false;
                m[pattern[i]]=s[i];
                mm[s[i]]++;
            }
        }
        return true;
    }
};
