/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

string get_Str(int n){
    string s;
    if(n==0)s.push_back('0');
    while(n){
        s.push_back(n%10+48);
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)return (string)"";
        
        string s;
        if(t->val<0)s.push_back('-');
        string ss=get_Str(abs(t->val));
        s+=ss;
        if(!t->left && !t->right)return s;
        if(1){
            s.push_back('(');
            string ss=tree2str(t->left);
            s+=ss;
            s.push_back(')');
        }
        if(t->right){
            s.push_back('(');
            string ss=tree2str(t->right);
            s+=ss;
            s.push_back(')');
        }
        return s;
    }
};
