//graph, math, greedy
#include <stdio.h>
#define ll long long
const int lg = 20;
int par[300001][lg];
int a[300001], c[300001];
int depth[300001];
int cnt;
int ans1;
ll ans2;
int climb(int ix, int d) {
	int k = 0;
	while (d != 0) {
		if (d & 1) ix = par[ix][k];
		d >>= 1;
		k++;
	}
	return ix;
}
int up(int ix) {
	for (int j = 19; j >= 0; --j) {
		if (a[par[ix][j]] > 0) return par[ix][j];
	}
	return ix;
}
int main() {
	int i, q; scanf("%d%d%d",&q,a+0,c+0);
	for (i = 1; i <= q; ++i) {
		int t; scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d",&par[i][0],a+i,c+i);
			depth[i] = depth[par[i][0]] + 1;
			for (int j = 1; j <= lg; ++j) {
				par[i][j] = par[par[i][j - 1]][j-1];
			}
		}
		else {
			int v, w; scanf("%d%d",&v,&w);
			ans1 = ans2 = 0;
			while (w > 0) {
				int cur = v;
				while (1) {
					//printf("c:%d\n",cur);
					int upper = up(cur);
					//printf("up:%d\n",upper);
					if (upper == cur) break;
					cur = upper;
				}
				//printf("c:%d\n", cur);
				if (a[cur] == 0) break;
				if (a[cur] > w) {
					ans2 += (ll)w * c[cur];
					ans1 += w;
					a[cur] -=w;
					break;
				}
				ans2 += (ll)a[cur]*c[cur];
				ans1 += a[cur];
				w -= a[cur]; a[cur] = 0;
				
			}
			printf("%d %I64d\n", ans1, ans2); fflush(stdout);
		}
 
	}
 
	return 0;
}
