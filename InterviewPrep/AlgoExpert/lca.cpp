#include <vector>
using namespace std;

class AncestralTree {
  public:
    char name;
    AncestralTree* ancestor;

    AncestralTree(char name) {
      this->name = name;
      this->ancestor = NULL;
    }
    
    void addAsAncestor(vector<AncestralTree*> descendants);
};

#define root OrgChart
#define OrgChart AncestralTree 
root* ans1=NULL;
vector<root*> lca(root*a ,root* b){
	vector<root*> ans;
	while(b!=a){
		ans.push_back(b);
		b=b->ancestor;
	}
	ans.push_back(a);
	return ans;
}

OrgChart* getYoungestCommonAncestor(OrgChart* a, OrgChart* b, OrgChart* c) {
	if(b==c){
		return b;
	}
  // Write your code here.
	vector<root*> first=lca(a,b);
	vector<root*> second=lca(a,c);
	for(root* i:first){
		for(root* j:second){
			if(i==j){
				return i;
			}
		}
	}
}
