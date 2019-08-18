class Solution {
public:
    map<int,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) {
        int ans=0;
        reverse(s.begin(),s.end());
        ans+=m[s[0]];
        for(int i=1;s[i];i++){
            if(m[s[i]]<m[s[i-1]]){
                ans-=m[s[i]];
            }
            else{
                ans+=m[s[i]];
            }
        }
        return ans;
    }
};
