class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        int s=a[0];
        int cnt=1;
        for(int i=1;i<a.size();i++){
            if(a[i]==s){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    s=a[i];
                    cnt=1;
                }
            }
        }
        return s;
    }
};
