#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree* parent;

    BinaryTree(int value, BinaryTree* parent = NULL);
    void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree* tree, void (*callback)(BinaryTree* tree)) {
  // Write your code here.
	stack<BinaryTree*> s;
	BinaryTree* curr=tree;
	while(curr!=NULL || !s.empty()){
		while(curr){
			s.push(curr);
			curr=curr->left;
		}
		callback(s.top());
		
		curr=s.top()->right;
		s.pop();
	}
	
}
