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
        preorder(v,root->left);
        preorder(v,root->right);
                v.pb(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> v;
        if(root==NULL){
            return v;
        }
        stack<node*> a,b;
        a.push(root);
        while(!a.empty()){
            node* t=a.top();
            a.pop();
            b.push(t);
            if(t->left){
                a.push(t->left);
            }
            if(t->right){
                a.push(t->right);
            }
        }
        while(!b.empty()){
            v.push_back(b.top()->val);
            b.pop();
        }
        
        return v;
    }
};
