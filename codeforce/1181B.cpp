//implementation
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
string n;
int _n[100000];
int candi[20][200001];
int c[200001];
int sz[20];
void add(int l, int r, int &len, int *B) {
	if (_n[l + 1] == 0) {
		len = 1e9;
		return;
	}
	int bnd = l;
	//printf("%d,%d\n", l, r);
	memset(c, 0, sizeof(c));
	while (bnd < r || l >= 0) {
		B[len] = c[len];
		if (bnd < r) B[len] += _n[r--];
		if (0 <= l) B[len] += _n[l--];
		if (B[len] >= 10) {
			c[len + 1] += B[len] / 10;
			B[len] %= 10;
		}
		//printf("%d,%d\n",B[len],c[len+1]);
		++len;

	}
	while (c[len]) {
		B[len] = c[len];
		if (B[len] > 10) {
			c[len + 1] += B[len] / 10;
			B[len] %= 10;
		}
		++len;
	}
}
int cmp(int a, int b) {//ret mn
	if (sz[a] > sz[b]) return b;
	else if (sz[a] < sz[b]) return a;
	else if (sz[a] < 150000) {
		int ix = sz[a] - 1;
		while (ix >= 0) {
			if (candi[a][ix] < candi[b][ix]) return a;
			else if (candi[a][ix] > candi[b][ix]) return b;
			--ix;
		}
	}
	return a;
}
int main() {
	int l; cin >> l >> n;
	for (int i = 0; i < l; ++i) _n[i] = n[i] - '0';
	int e = l - 1;
	int s = l >> 1;
	int ans = 0;
	int ix = 0;
	add(s, e, sz[ix], candi[ix]);

	++ix;
	add(s + 1, e, sz[ix], candi[ix]);
	ans = cmp(ans, ix);

	++ix;
	add(s - 1, e, sz[ix], candi[ix]);
	ans = cmp(ans, ix);

	
	while (s < e && _n[s + 1] == 0) {
		++s;
	}
	if (s != e) {
		++ix;
		add(s, e, sz[ix], candi[ix]);
		ans = cmp(ans, ix);
	}
	s = l >> 1;
	while (s >= 0 && _n[s + 1] == 0) --s;
	if (s >= 0) {
		++ix;
		add(s, e, sz[ix], candi[ix]);
		ans = cmp(ans, ix);
	}
	
	int i = sz[ans] - 1;
	while (i >= 0) printf("%d", candi[ans][i]), --i;
	

	return 0;
}