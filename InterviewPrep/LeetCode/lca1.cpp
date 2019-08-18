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
    bool flag=false;
    
    TreeNode* lca;
    
    pair<bool,bool> f(TreeNode* root,TreeNode* a,TreeNode* b){
        if(!root)return make_pair(0,0);
        if(flag)return make_pair(1,1);
        pair<int,int> left=f(root->left,a,b);
        pair<int,int> right=f(root->right,a,b);
        pair<int,int> ans={0,0};
        
        if(root==a)ans.first=true;
        if(root==b)ans.second=true;
        ans.first|=left.first;
        ans.first|=right.first;
        ans.second|=(left.second|right.second);
        if(ans.first && ans.second && flag==false){
            flag=true;
            lca=root;
        }
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<int,int> c=f(root,p,q);
        return lca;
    }
};


class Solution2 {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if(!root)
        return NULL;
    
    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    
    else if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
      
    return root;
}
};
