#include<bits/stdc++.h>
using namespace std;
map<int,int> m;

int getNthFib1(int n) {
  // Write your code here.
	
	if(m.count(n))return m[n];
	int k=n/2;
	if(n%2==0){
		return m[n]=getNthFib1(k)*getNthFib1(k) + getNthFib1(k-1)*getNthFib1(k-1);
	}
	else{
		return m[n]=getNthFib1(k)*(getNthFib1(k-1)+getNthFib1(k+1));
	}
}
int getNthFib(int n){
	m[0]=m[1]=1;
	if(n==1)return 1;
	if(n==2)return 1;
	else return getNthFib1(n-2);
}
