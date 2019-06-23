#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourNumberSum(vector<int> a, int s) {
  // Write your code here.
	sort(a.begin(),a.end());
	int x,b,c,d;
	vector<vector<int> > ans;
	bool flag=false;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			int si=j+1,ei=a.size()-1;
			int sum=s-a[i]-a[j];
			while(si<ei){
				int sa=s-sum+a[si]+a[ei];
				if(sa==s){
					x=a[i];
					flag=true;
					b=a[j];
					c=a[si];
					d=a[ei];
					vector<int> t;
					t.push_back(x);
					t.push_back(b);
					t.push_back(c);
					t.push_back(d);
					ans.push_back(t);
					si++;
				}
				else if(sa>s){
					ei--;
				}
				else{
					si++;
				}
			}
		}
	}
	if(!flag){
		return ans;
	}
	return ans;
}
