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
    map<int,vector<int>> m;
    void dfs(TreeNode* root,int level){
        if(!root)return ;
        dfs(root->left,level+1);
        m[level].push_back(root->val);
        dfs(root->right,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        dfs(root,0);
        for(auto i:m){
            v.push_back(i.second);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
