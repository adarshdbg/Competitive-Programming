#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

ll cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	ll k=cnt[a[position]];
	answer+=(a[position]*k*k)-(a[position]*(k-1)*(k-1));
}

void remove(int position) {
	cnt[a[position]]--;
	ll k=cnt[a[position]];
	answer+=(a[position]*k*k)-(a[position]*(k+1)*(k+1));
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	
	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<endl;
}
