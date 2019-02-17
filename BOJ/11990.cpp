//greedy, st
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int> 
using namespace std;
const int LEAF = 1 << 20;
int l[LEAF + LEAF], r[LEAF + LEAF];
int ul, ur, dl, dr;
int max(int a, int b, int c, int d) { return max(max(a,b),max(c,d)); }
void upd(int ix, int val, int *st) {
	st[ix] += val;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix + 1] + st[ix + ix];
		ix >>= 1;
	}
}
void dfs(int ix) {
	if (ix > LEAF) {
		int r1 = max(dl + l[ix], dr+r[ix], ul, ur);
		int r2 = max(dl, dr, ul + l[ix], ur + r[ix]);
		if (r1 < r2) dl += l[ix], dr += r[ix];
		else ul += l[ix], ur += r[ix];
		return;
	}
	int u = ix + ix;
	int d = u + 1;
	if (max(ul + l[u], ur + r[u]) > max( dl + l[d], dr + r[d])) {
		dl += l[d];
		dr += r[d];
		dfs(u);
	}
	else {
		ul += l[u];
		ur += r[u];
		dfs(d);
	}
}
int main() {
	vector<pii > cow;
	int i, N;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		int x, y;
		scanf("%d%d",&x,&y);
		cow.push_back({x,y});
		upd(LEAF + y, 1, r);
	}
	sort(cow.begin(), cow.end());
	i = 0;
	int last = -1;
	int ans = N;
	for (;i<N;) {
		last = cow[i].first;
		while (i<N && last == cow[i].first) {
			int y = cow[i].second;
			++i;
			upd(LEAF + y, 1, l); upd(LEAF + y, -1, r);
		}
		ul = ur = dl = dr = 0;
		dfs(1);
		int res = max(ul,ur,dl,dr);
		if (ans > res) ans = res;
		//++i;
		//printf("res:(%d,%d,%d,%d)\n",res,ul,ur,dl,dr);
	}
	printf("%d",ans);

	return 0;
}