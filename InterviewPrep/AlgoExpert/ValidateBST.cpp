/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Leetcode solution
#define ll long long int
class Solution {
public:
    bool isValidBST(TreeNode* tree,ll m=-1e11,ll M=1e11) {
        if(!tree){
            return true;
        }
        if((ll)tree->val<=m || (ll)tree->val>=M){
            return false;
        }
        return (isValidBST(tree->left,m,tree->val) && isValidBST(tree->right,tree->val,M));
    }
};
