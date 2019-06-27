#include <bits/stdc++.h>
using namespace std;


bool inorder(vector<int> a,int i){
	if(a.size()==1)return true;
	if(i==0){
		return a[0]<=a[1];
	}
	else if(i==a.size()-1){
		return a[a.size()-1]>=a[a.size()-2];
	}
	else{
		return (a[i]>=a[i-1] && a[i]<=a[i+1]);
	}
}

vector<int> subarraySort(vector<int> a) {
  // Write your code here.
	int si=-1,ei=-1;
	if(a.size()<=1){
		return vector<int> {-1,-1};
	}
	for(int i=0;i<a.size();i++){
		if(inorder(a,i)){
			continue;
		}
		si=i;
		break;
	}
	for(int i=a.size()-1;i>=0;i--){
		if(inorder(a,i))continue;
		ei=i;
		break;
	}
	int m=INT_MAX,M=INT_MIN;
	for(int i=0;i<=a.size()-1;i++){
		if(inorder(a,i)){
			continue;
		}
		m=min(a[i],m);
		M=max(a[i],M);
	}
	
	
	if(m==INT_MAX){
		return vector<int> {-1,-1};
	}
	
	int subleft=0,subright=a.size()-1;
	while(m>=a[subleft]){
		subleft++;
	}
	while(M<=a[subright]){
		subright--;
	}
	
	
	return vector<int> {subleft,subright};
	
	
}
