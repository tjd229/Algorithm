//sqrt Decomp.
#include <stdio.h>
#include <queue>
using namespace std;
const int X = 1 << 9;
queue<int> plan[200001];
int op[200001], k[200001];
int x[200001], y[200001];
int e[200001];
int st[200001];
int mod[X][X];
int main() {
	int i, n, m;
	int mx_len = 0;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%d%d",x+i,y+i);
	for (i = 1; i <= m; ++i) {
		scanf("%d%d", op + i, k + i);
		plan[k[i]].push(i);
	}
	for (i = 1; i <= m; ++i) {

		if (x[k[i]] + y[k[i]] >= X) {
			if (op[i] == 1) {
				int cur = i; plan[k[i]].pop();
				int ed = m + 1;
				if (plan[k[i]].size()) {
					int rm = plan[k[i]].front(); plan[k[i]].pop();
					if (ed > rm) ed = rm;
				}
				while (cur < ed) {
					if ( cur + x[k[i]] <ed) {
						e[cur + x[k[i]]] += 1;
					}
					else break;
					if (cur + x[k[i]]+y[k[i]] < ed) {
						e[cur + x[k[i]] +y[k[i]] ] -=1;
					}
					else {
						e[ed] -= 1;
						break;
					}
					cur += x[k[i]] + y[k[i]];
				}
			}
		}
		else {
			int d = -1;
			if (op[i] == 1) d=1,st[k[i]] = i;
			int c = x[k[i]] + y[k[i]]; int *blk = mod[c];
			int ix = st[k[i]] - 1 + x[k[i]];
			for (int j = 0; j < y[k[i]]; ++j)
				blk[(j + ix) % c] += d;

			if (mx_len < c) mx_len = c;
		}

		e[i] += e[i - 1];
		int c = 0;
		for (int j = 2; j <= mx_len; ++j)
			c += mod[j][(i - 1) % j];
		printf("%d\n",e[i]+c);
	}

	return 0;
}