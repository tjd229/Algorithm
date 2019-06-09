//math, line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int lg = 19;
vector<pii > it;
int x[200001], y[200001];
int master[500001];
int bs[lg][200001];//k,ix
int main() {
	int i, j, n, m;
	int bnd = 0; it.push_back({-1,-1});
	for (scanf("%d%d", &n, &m), i = 0; i < n; ++i) {
		int l, r; scanf("%d%d",&l,&r);
		it.push_back({l,r});
		if (bnd < r) bnd = r;
	}
	for (i = 0; i < m; ++i) {
		scanf("%d%d",x+i,y+i);
		if (bnd < y[i]) bnd = y[i];
	}
	sort(it.begin(), it.end()); j = 1;
	int ix = j; int to = -1;
	for (i = 0; i <= bnd; ++i) {//i is coord.
		while (j<=n && i == it[j].first) {
			if (to < it[j].second) {
				to = it[j].second;
				ix = j;
			}
			++j;
		}
		if (i >= to) master[i] = 0;
		else master[i] = ix;
	}
	for (i = 1; i <= n; ++i) bs[0][i] = master[it[i].second];
	for (i = 1; i < lg; ++i) {
		for (j = 1; j <= n; ++j) {
			bs[i][j] = bs[i-1][bs[i-1][j]];
		}
	}
	

	for (i = 0; i < m; ++i) {
		int ix = master[x[i]];
		if (ix == 0) {
			puts("-1");
			continue;
		}
		else if (it[ix].second >= y[i]) {
			puts("1");
			continue;
		}
		int ans = 1;
		for (j = lg - 1; j >= 0; --j) {
			int to = bs[j][ix];
			if (to == 0) continue;
			if (it[to].second < y[i]) {
				ix = to;
				ans += (1 << j);
			}
		}
		if (bs[0][ix] == 0) ans = -1;
		else ++ans;
		printf("%d\n",ans);
	}
	/*for (i = 0; i <= bnd; ++i)
		if (master[i] < 0) printf("%d: %d\n",i,-1);
		else
			printf("%d: %d~%d\n",i,it[master[i]].first,it[master[i]].second);
*/
	return 0;
}