//dp
#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int no[100001];
int d[200002][1 << 8];
int parity[1<<8];
int f;
int ab(int stat) {
	int inv = f ^ stat;
	return inv & -inv;
}
int main() {
	
	int i, n, m, k;
	vector<pii > evt;
	for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i) {
		int L, R; scanf("%d%d",&L,&R);
		evt.push_back({L,i});//op
		evt.push_back({R+1,-i});
	}

	evt.push_back({-1,-1});
	sort(evt.begin(), evt.end());
	evt.push_back(evt.back());
	f = (1 << k) - 1;
	for (i = 0; i <= f; ++i) {
		int num = i;
		int cnt = 0;
		while (num) {
			num -= (num&-num);
			++cnt;
		}
		parity[i] = cnt & 1;
	}
	int ans = 0;
	int stat = 0;
	int nn = n + n;
	for (i = 0; i <= nn; ++i) {
		for (int j = 0; j <= f; ++j)
			d[i][j] = -2e9;
	}


	for (i = 1,d[0][0]=0; i <=nn; ++i) {
		int len = evt[i + 1].first - evt[i].first;
		int ix = evt[i].second;
		if (ix > 0) { //op
			no[ix] = ab(stat);
			for (int b = 0; b <= f; ++b) {
				if (b&no[ix])
					d[i][b] = d[i - 1][b^no[ix]] + len * parity[b];
				else
					d[i][b] = d[i - 1][b] + len * parity[b];
				if (ans < d[i][b]) ans = d[i][b];
				//printf("%d,%d:%d\n",i,b,d[i][b]);
			}
			stat += no[ix];
		}
		else {
			ix = -ix;
			for (int b = 0; b <= f; ++b) {
				if ((b&no[ix]) == 0) {
					int base = d[i - 1][b] < d[i - 1][b + no[ix]] ? d[i - 1][b + no[ix]] : d[i - 1][b];

					//d[i][b] = d[i - 1][b] + len * parity[b];
					d[i][b] =base + len * parity[b];
				}
				if (ans < d[i][b]) ans = d[i][b];
				//printf("!:%d,%d:%d\n", i, b, d[i][b]);
			}
			stat -= no[ix];
		}
	}
	printf("%d",ans);
	return 0;
}
