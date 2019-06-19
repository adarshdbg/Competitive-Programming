#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
	int a=-100000000;
	int b=a,c=a;
	for(int d:array){
		if(d>=a){
			c=b;
			b=a;
			a=d;
		}
		else if(d>=b){
			c=b;
			b=d;
		}
		else if(d>c){
			c=d;
		}
	}
	vector<int> ans(3);
	ans[0]=c;
	ans[1]=b;
	ans[2]=a;
	return ans;
}
