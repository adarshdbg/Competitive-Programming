#include <vector>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

BinaryTree* f(BinaryTree *left,BinaryTree * root){
	if(!left){
		return NULL;
	}
	root=new BinaryTree(left->value);
	root->left=f(left->right,root->left);
	root->right=f(left->left,root->right);
	
	return root;
	
}

void invertBinaryTree(BinaryTree* tree) {
  // Write your code here.
	if(!tree){
		return ;
	}
	BinaryTree* temp=NULL;
	temp=f(tree,temp);
	tree->left=temp->left;
	tree->right=temp->right;
}
