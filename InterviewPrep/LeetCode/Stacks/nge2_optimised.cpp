class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                while (!stk.empty() && nums[stk.top()] < nums[i]) {
                    res[stk.top()] = nums[i];
                    stk.pop();
                }
                if (j == 0) stk.push(i);
            }
        }
        return res;
    }
};
