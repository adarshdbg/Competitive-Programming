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
        stack<pair<node*,int>> a;
        a.push(make_pair(root,0));
        while(!a.empty()){
            pair<node*,int> b;
            b=a.top();
            a.pop();
            if(b.second==0){
                a.push(make_pair(b.first,1));
                if(b.first->left)
                    a.push(make_pair(b.first->left,0));
            }
            else if(b.second==1){
                a.push(make_pair(b.first,2));
                if(b.first->right)
                    a.push(make_pair(b.first->right,0));
            }
            else{
                v.push_back(b.first->val);
            }
        }
        return v;
    }
};
