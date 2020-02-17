//dp, st, lazy propagation
#include <stdio.h>
#include <memory.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 15;
int st[LEAF + LEAF], pg[LEAF + LEAF];
int ani[52][20002];
int s[52][20002];
int d[52][20002];
void propagate(int ix) {
	st[ix] += pg[ix];
	if (ix < LEAF) {
		pg[ix + ix] += pg[ix];
		pg[ix + ix + 1] += pg[ix];
	}
	pg[ix] = 0;
}
void upd(int ix,int s,int e,int from,int to,int d) {
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		pg[ix] += d;
		propagate(ix);
		return;
	}
	if (ix < LEAF) {
		upd(ix + ix, s, (s + e) >> 1, from, to, d);
		upd(ix + ix + 1, 1 + ((s + e) >> 1), e, from,to, d);
		st[ix] = st[ix + ix];
		if (st[ix] < st[ix + ix + 1]) st[ix]=st[ix + ix + 1];
	}
}
int main() {
	int i, j, n, m, k;
	for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			scanf("%d",ani[i]+j);		
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j)
			s[i][j] = s[i][j - 1] + ani[i][j];
	}
	for (j = 1; j + k - 1 <= m; ++j)
		d[2][j] = s[2][j + k - 1] - s[2][j - 1]+s[1][j+k-1]-s[1][j-1];
	for (i = 3; i <= n+1; ++i) {
		priority_queue<pii > q;//val,ix
		memset(st, 0, sizeof(st));
		memset(pg, 0, sizeof(pg));
		for (j = 1; j <= k; ++j) 
			upd(1, 0, LEAF - 1, j, j, d[i - 1][j]-(s[i-1][k]-s[i-1][j-1]));
		
		for (j = k + 1; j <= m; ++j)
			q.push({d[i-1][j],j});
		for (j = 1; j+k-1 <= m; ++j) {
			propagate(1);
			int mx = st[1];
			while (q.size() && q.top().second < j + k && j-k < q.top().second)
				q.pop();
			if (q.size()) {
				int h = q.top().first;
				if (mx < h) mx = h;
			}
			d[i][j] = mx+s[i][j+k-1]-s[i][j-1]+ s[i-1][j + k - 1] - s[i-1][j - 1];
			//printf("%d,(%d,%d)\n",st[1],q.top().first,q.top().second);
			//printf("%d+%d+%d=%d\n", mx, s[i][j + k - 1] - s[i][j - 1],s[i - 1][j + k - 1] - s[i - 1][j - 1],d[i][j]);
			if (j - k + 1 > 0) {
				q.push({ d[i - 1][j - k + 1],j - k + 1 });
				upd(1, 0, LEAF - 1, j - k + 1, j - k + 1, -d[i - 1][j - k + 1]);
			}
			//int from = 1, to = m - k + 1;
			int from = j - k, to = j;
			if (from < 1) from = 1;
			upd(1, 0, LEAF - 1, from, to, ani[i - 1][j]);
			from = j + 1; to = j + k;
			if (to > m - k + 1) to = m - k + 1;
			else//upd d[][]
				upd(1, 0, LEAF - 1, to, to, d[i - 1][to]);
			upd(1, 0, LEAF - 1, from, to, -ani[i - 1][j + k]);
			//printf("%d,%d\n",mx,d[i][j]);
		}
		//puts("");
		
	}
	int ans = 0;
	for (j = 1; j + k - 1 <= m; ++j) {
		if (ans < d[n + 1][j]) ans = d[n + 1][j];
	}
	printf("%d",ans);
	/*for (i = 1; i <= n+1; ++i) {
		for (j = 1; j + k - 1 <= m; ++j)
			printf("%02d ",d[i][j]);
		puts("");
	}*/

	return 0;
}