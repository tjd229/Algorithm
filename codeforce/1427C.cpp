//dp
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
int x[100001], y[100001], t[100001];
int d[100001];
inline int md(int a,int b) {
	int dx = x[a] - x[b];
	int dy = y[a] - y[b];
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	return dx + dy;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, r, n; cin >> r >> n;
	int ans = 0;
	int mx = -1;
	for (i = 1; i <= n; ++i) {
		cin >> t[i] >> x[i] >> y[i];
		d[i] = -1;
	}
	t[0] = 0; x[0] = y[0] = 1;
	d[0] = 0;
	int tm = 0;
	for (int i = 1; i <= n; ++i) {
		while (tm<i && t[tm] + r + r <= t[i]) {
			if (mx < d[tm]) mx = d[tm];
			++tm;
		}
		if(mx!=-1)
			d[i] = mx+1;
		//printf("%d:%d\n",i,d[i]);
		for (int j = i - 1; j >= tm; --j) {
			if (t[i] - t[j] < md(i, j)) continue;
			if (d[j] < 0) continue;
			if (d[i] < d[j] + 1) d[i] = d[j] + 1;
			//printf("%d:%d\n", i, d[i]);
		}
		if (ans < d[i]) ans = d[i];
	}
	printf("%d",ans);
	return 0;
}