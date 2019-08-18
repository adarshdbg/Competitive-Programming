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
    string get_string(int n){
        string s;
        if(n<0)s.push_back('-');
        n=abs(n);
        while(n){
            s.push_back(n%10+48);
            n/=10;
        }
        reverse(s.begin()+(s[0]=='-'),s.end());
        return s;
    }
    vector<string> ans;
    void f(TreeNode* root,string s="") {
        if(!root){
            return ;
        }   
        if(!root->left && !root->right){
            if(s.length()){
                s+="->";
                s+=(get_string(root->val));
            }
            else{
                s+=(get_string(root->val));
            }
            if(s.length()){
                ans.push_back(s);
            }
            return ;
        }
        if(s.length()){
            s+="->";
            s+=(get_string(root->val));
        }
        else{
            s+=(get_string(root->val));
        }
        f(root->left,s);
        f(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         f(root);
        return ans;
    }
};
