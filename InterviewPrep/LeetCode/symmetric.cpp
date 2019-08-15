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
    bool isSymmetric(TreeNode* root,TreeNode* t=NULL,int level=0) {
        if(level==0){
            if(!root)return true;
            return isSymmetric(root->left,root->right,level+1) && isSymmetric(root->right,root->left,level+1) ;
        }
        if(!root && !t)return true;
        if(!root || !t)return false;
        return (root->val == t->val) && isSymmetric(root->left,t->right,level+1) && isSymmetric(root->right,t->left,level+1);
    }
};
