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
    pair<int,bool> f(TreeNode* root){
        if(!root)return make_pair(0,true);
        pair<int,int> left=f(root->left),right=f(root->right);
        return make_pair(max(left.first,right.first)+1,(abs(left.first-right.first)<=1) && left.second && right.second);
    }
    bool isBalanced(TreeNode* root) {
        if(!root || (!root->left && !root->right))return true;
        return f(root).second;
    }
};
