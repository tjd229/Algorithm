//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
vector<int> a[1000001];
vector<int> range_min[1000001];
vector<int> range_max[1000001];
int piv[1000001], pop[1000001];
int qiv[1000001];
char clr[1000002];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j,n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			a[i].resize(1 + m);
			range_min[i].resize(1 + m); range_max[i].resize(1 + m);
			for (j = 1; j <= m; ++j) scanf("%d",&a[i][j]);
			range_min[i][m] = range_max[i][m]=a[i][m];
			qiv[i] = 1e9;
			for (j = m - 1; j > 0; --j) {
				range_min[i][j] = min(range_min[i][j + 1], a[i][j]);
				range_max[i][j] = max(range_max[i][j + 1], a[i][j]);

			}
		}
		int k = -1; clr[1 + n] = '\0';
		for (j = 1; j < m && k<0; ++j) {
			vector<pii > order;
			vector<pii > RR,LR;
			int RB = 1e9,LB=0;
			for (i = 1; i <= n; ++i) {
				piv[i] = max(piv[i], a[i][j]);
				qiv[i] = min(qiv[i], a[i][j]);
				order.push_back({piv[i],i});
				RR.push_back({ range_max[i][j + 1],i }); pop[i] = 0;
				LR.push_back({ qiv[i],i }); 
				clr[i] = 'R';
			}
			sort(order.begin(), order.end()); sort(RR.begin(), RR.end());
			sort(LR.begin(), LR.end()); reverse(LR.begin(), LR.end());
			for (i = 0; i < n-1; ++i) {
				int ix = order[i].second;
				clr[ix] = 'B'; 
				pop[ix] = 1; 
				RB = min(RB, range_min[ix][j + 1]);
				LB = max(LB, piv[ix]);
				while (pop[RR.back().second])
					RR.pop_back();
				while (pop[LR.back().second])
					LR.pop_back();
				if (LR.back().first > LB && RR.back().first < RB) {
					k = j;
					break;
				}
			}
		}
		if (k < 0) printf("NO\n");
		else {
			printf("YES\n%s %d\n",clr+1,k);
		}
		for (i = 1; i <= n; ++i) {
			a[i].clear();
			range_min[i].clear(); range_max[i].clear();
			piv[i] = 0;
		}
	}

	return 0;
}