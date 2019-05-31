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
    int minDiffInBST(TreeNode* root) {
        if(!root){
            return INT_MAX;
        }
        if(!root->left && !root->right){
            return INT_MAX;
        }
        int left=minDiffInBST(root->left);
        int right=minDiffInBST(root->right);
        int a=INT_MAX;
        TreeNode* b=root->left;
        while(b && b->right){
            b=b->right;
        }
        if(b){
            a=abs(root->val-b->val);
        }
        b=root->right;
        while(b && b->left){
            b=b->left;
        }
        if(b){
            a=min(a,abs(root->val-b->val));
        }
        return min(a,min(left,right));
    }
};
