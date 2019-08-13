class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        if(digits.size()==0){
            ans.push_back(1);
            return ans;
        }
        int s=0;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++){
            int sum=digits[i]+s+(i==0);
            ans.push_back(sum%10);
            s=sum/10;
        }
        while(s){
            ans.push_back(s%10);
            s/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
