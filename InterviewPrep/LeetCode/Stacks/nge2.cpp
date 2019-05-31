class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a(nums.size(),-1);
        if(nums.size()==0){
            return a;
        }
        for(int i=0;i<nums.size();i++){
            int ans=INT_MAX;
            for(int j=(i+1)%nums.size();j!=i;j=(j+1)%nums.size()){
                if(nums[j]>nums[i]){
                    ans=nums[j];
                    break;
                }
            }
            a[i]=(ans==INT_MAX)?-1:ans;
        }
        return a;
    }
};    
