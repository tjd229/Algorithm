//st
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 20;
int st[LEAF + LEAF];
void upd(int ix, int val) {
	while (ix >= 1) {
		st[ix] += val;
		ix >>= 1;
	}
}
int kth(int ix, int k) {
	if (ix >= LEAF) return ix - LEAF;
	int l = ix + ix;
	int r = l + 1;
	if (st[l] >= k) return kth(l, k);
	return kth(r, k - st[l]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		upd(LEAF + a, 1);
	}
	while (q--) {
		
		int k; cin >> k;
		if (k < 0) {
			int pos = kth(1, -k);
			//cout << pos << endl;
			upd(LEAF + pos, -1);
		}
		else upd(LEAF + k, 1);
	}
	//cout << st[1] << endl;
	if (st[1])
		cout << kth(1, 1);
	else cout << 0;
 
	return 0;
}