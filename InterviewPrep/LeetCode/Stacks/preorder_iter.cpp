/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
#define node TreeNode
class Solution {
public:
    void preorder(vector<int> &v, TreeNode*root){
        if(!root){
            return ;
        }
        v.pb(root->val);
        preorder(v,root->left);
        preorder(v,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<node*> a;
        a.push(root);
        while(!a.empty()){
            node* b=a.top();
            a.pop();
            if(!b) continue;
            v.push_back(b->val);
            a.push(b->right);
            a.push(b->left);
        }
        return v;
    }
};
