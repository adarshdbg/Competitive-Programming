#include <bits/stdc++.h>
using namespace std;

pair<int,int> ispossible_binary_search(vector<int> a,int first){
	
	int si=0,ei=a.size()-1;
	int pivot=-1;
	while(si<=ei){
		int mid=(si+ei)/2;
		if(a[mid]<first){
			si=mid+1;
			pivot=mid;
		}
		else{
			if(a[mid]==first){
				return make_pair(0,a[mid]);
			}
			ei=mid-1;
		}
	}
	if(pivot==-1){
		return make_pair(abs(first-a[0]),a[0]);
	}
	if(pivot==a.size()-1){
		return make_pair(abs(first-a[pivot]),a[pivot]);
	}
	if(abs(first-a[pivot])<abs(first-a[pivot+1])){
		return make_pair(abs(first-a[pivot]),a[pivot]);
	}
	return make_pair(abs(first-a[pivot+1]),a[pivot+1]);
	
}

vector<int> smallestDifference(vector<int> a, vector<int> b) {
  // Write your code here.
	int diff=INT_MAX;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int> ans;
	for(int i=0;i<a.size();i++){
		pair<int,int> if_this_is_answer=ispossible_binary_search(b,a[i]);
		if(diff>if_this_is_answer.first){
			diff=if_this_is_answer.first;
			vector<int> t;
			t.push_back(a[i]);
			t.push_back(if_this_is_answer.second);
			ans=t;
		}
	}
	return ans;
}
