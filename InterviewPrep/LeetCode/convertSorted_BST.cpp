/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& a) {
        if(a.size()==0)return NULL;
        int mid=a.size()/2;
        auto first=a.cbegin()+mid;
        auto second=a.cbegin()+a.size();
        vector<int> left(a.cbegin(),first),right(a.cbegin()+mid+1,second);
        
        TreeNode* root=new TreeNode(a[mid]);
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};
