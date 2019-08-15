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
    bool hasPathSum(TreeNode* root, int sum,int level=0) {
        if(!root){
            if(level==0)return false;
            if(sum==0)return true;
            return false;
        }
        if(!root->left && !root->right)return root->val==sum;
        if(!root->left)return hasPathSum(root->right,sum-root->val,level+1);
        if(!root->right)return hasPathSum(root->left,sum-root->val,level+1);
        return hasPathSum(root->left,sum-root->val,level+1) || hasPathSum(root->right,sum-root->val,level+1);
    }
};
