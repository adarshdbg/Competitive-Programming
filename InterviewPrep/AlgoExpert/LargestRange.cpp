#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int find_ind(vector<int> a,int si,int ei,int extra){
	
	int ans=-1;
	while(si<=ei){
		int mid=(si+ei)/2;
		if(a[mid]-extra<mid){
			si=mid+1;
		}
		else{
			if(a[mid]-extra==mid){
				ans=mid;
                ei=mid-1;
			}
			else{
                break;
            }
		}
	}
	return ans;
}

vector<int> largestRange(vector<int> a) {
  // Write your code here.
	if(a.size()==1){
		return vector<int> {a[0],a[0]};
	}
    vector<int> b;
    map<int,int> m;
    for(auto i:a){
        m[i]++;
    }
    for(auto i:m){
        b.push_back(i.first);
    }
    a=b;
	int Min=*min_element(a.begin(),a.end());
    Min-=100;
	if(Min<0){
		for(int i=0;i<a.size();i++){
			a[i]-=Min;
		}
	}
	vector<int> v;
	sort(a.begin(),a.end());
	int x=INT_MAX,y=0;
	for(int i=1;i<a.size();i++){
		int extra=a[i]-i;
		int ind=find_ind(a,0,i-1,extra);
		if(ind!=-1){
			if(a[i]-a[ind]>y-x){
				y=a[i];
				x=a[ind];
			}
		}
	}
	if(Min<0){
		x+=Min;
		y+=Min;
	}
	v.push_back(x);
	v.push_back(y);
	return v;
}
