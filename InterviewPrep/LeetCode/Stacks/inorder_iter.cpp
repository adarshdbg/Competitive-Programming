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
    
    void inorder(TreeNode* root,vector<int> & v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> a;
        TreeNode* curr=root;
        while(curr!=NULL || a.empty()==false){
            while(curr!=NULL){
                a.push(curr);
                curr=curr->left;
            }
            curr=a.top();
            a.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
    }
};
