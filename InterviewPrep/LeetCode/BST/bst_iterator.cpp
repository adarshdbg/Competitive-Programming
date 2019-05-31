/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    queue<TreeNode*> q;
public:
    TreeNode* root;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if(root != NULL) q.push(root);
        inorder(root->right);
        return;
    }
    /** @return the next smallest number */
    int next() {
        auto ret = q.front();
        q.pop();
        return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
