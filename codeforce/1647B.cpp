//djs, implementation
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };
int n, m;
int btn[111][111];
int p[11111];
int sx[11111], sy[11111], ex[11111], ey[11111];
int cum[111][111];
inline int to1d(int x, int y) {
	return y * m + x;
}
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	sx[a] = min(sx[a], sx[b]);
	sy[a] = min(sy[a], sy[b]);
	ex[a] = max(ex[a], ex[b]);
	ey[a] = max(ey[a], ey[b]);
	return 1;
}
int rsum(int sx,int sy,int ex,int ey) {
	return cum[ey][ex] - cum[ey][sx - 1] - cum[sy - 1][ex] + cum[sy - 1][sx - 1];
}
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int i, j; scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%1d", btn[i] + j);
				int ix = to1d(j, i); p[ix] = ix;
				sx[ix] = ex[ix] = j;
				sy[ix] = ey[ix] = i;
 
				cum[i][j] = btn[i][j];
				cum[i][j] += cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1];
			}
			
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
 
				for (int k = 0; k < 4; ++k) {
					int x = j + dx[k], y = i + dy[k];
					if (btn[i][j] == 1 && btn[y][x] == 1) {
						int u = to1d(j,i),v=to1d(x,y);
						dsu(u, v);
					}
				}
			}
		}
		bool flag = 1;
		for (i = 1; i <= n && flag; ++i) {
			for (j = 1; j <= m && flag; ++j) {
				if (btn[i][j] == 1) {
					int ix = to1d(j, i);
					int p = find(ix);
					int lenx = ex[p] - sx[p] + 1;
					int leny = ey[p] - sy[p] + 1;
					if (lenx*leny != rsum(sx[p], sy[p], ex[p], ey[p])) flag = 0;
				}
			}
		}
		if (flag) cout << "YES";
		else cout << "NO";
		cout << "\n";
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				btn[i][j] = cum[i][j]=0;
			}
		}
	}
 
 
	return 0;
}