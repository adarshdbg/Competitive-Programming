class Solution {
public:
    void reverse(vector<int> &a,int l,int r){
        if(r<=l)return ;
        while(l<=r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
};
