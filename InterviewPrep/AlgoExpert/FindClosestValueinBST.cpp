#include<bits/stdc++.h>
#define ll int
class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
	if(tree==NULL){
		return INT_MAX;
	}
	int left=findClosestValueInBst(tree->left,target);
	int right=findClosestValueInBst(tree->right,target);
	ll diff=min(abs(tree->value-target),min(abs(target-left),abs(target-right)));
	if(abs(target-tree->value)==diff){
		return tree->value;
	}
	else if(abs(target-left)==diff)return left;
							else return right;
	
	
}
