//djs
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
int n, m;
string b[1000];
int p[1000000];
int sz[1000000];
int btm[1000000];
int top[1000000];
int use[1000000];
int clr[1000000];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
	if (top[a] > top[b]) top[a] = top[b];
	if (btm[a] < btm[b]) btm[a] = btm[b];
}
int to1D(int x,int y) {
	return y * m + x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans = 0;
	int i, j; cin >> n >> m;
	for (i = 0; i < n; ++i) cin >> b[i];
	int ix = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			p[ix] = ix;
			sz[ix] = 1;
			btm[ix] = top[ix] = ix;
			clr[ix] = b[i][j] - 'a';
			++ix;
		}
	}
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < m; ++j) {
			if (b[i][j] == b[i + 1][j]) un(to1D(j,i),to1D(j,i+1));
		}
	}

	for (i = 1; i < n - 1; ++i) {	
		j = 0;
		while (j < m) {
			ll cnt = 0;
			int pj = find(to1D(j,i));
			int topj = top[pj];
			int btmj = btm[pj];
			int clrj = clr[pj];
			if (topj < m) { ++j; continue; }
			if (btmj + m >= n * m) { ++j; continue; }
			if (use[pj]) { ++j; continue; }
			int t = find(topj - m);
			int b = find(btmj + m);
			if(sz[pj]>sz[t] || sz[pj]>sz[b]) { ++j; continue; }			
			//printf("row:%d\n",i);
			int k = j;
			for (; k < m; ++k) {
				int pk = find(to1D(k, i));
				int topk = top[pk];
				int btmk = btm[pk];
				int clrk = clr[pk];

				if (btmk / m != btmj / m) break;
				if (topk / m != topj / m) break;
				if (topk < m) break;
				if (btmk + m >= n * m) break;
				if (clrk != clrj) break;
				if (clr[t] != clr[topk - m]) break;
				if (clr[b] != clr[btmk + m]) break;
				
				if (sz[pj] > sz[find(topk - m)]
					|| sz[pj] > sz[find(btmk + m)]) break;
				++cnt;
				
			}
			//cnt
			//printf("c:%lld\n",cnt);
			for (; j < k; ++j) use[find(to1D(j,i))] = 1;
			use[pj]=1;
			ans += ((cnt)*(cnt + 1)) >> 1;
			//j = k;
		}
	}
	cout << ans;
	return 0;
}