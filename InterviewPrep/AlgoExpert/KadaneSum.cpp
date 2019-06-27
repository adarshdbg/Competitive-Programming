#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> a) {
  // Write your code here.
	int ans=-1e8;
	
	int n=a.size();
	int curr=0;
	for(int i=0;i<n;i++){
		curr+=a[i];
		ans=max(ans,curr);
		if(curr<0){
			curr=0;
		}
	}
	return ans;
}
