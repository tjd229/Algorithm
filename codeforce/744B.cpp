//math
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> row[1001];
int n;
void game(vector<int> &v) {
	if (v.empty()) return;
	printf("%d\n",v.size());
	for (auto x : v) printf("%d ",x);
	printf("\n"); fflush(stdout);
	for (int i = 1; i <= n; ++i) {
		int M; scanf("%d",&M);
		row[i].push_back(M);
	}
	for (auto x : v) row[x].pop_back();
}
int main() {
	int i, j; scanf("%d",&n);
	vector<int> v[10]; int mv;
	for (mv = 0; n >= (1 << mv); ++mv);
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < mv; ++j) {
			if (i&(1 << j)) v[j].push_back(i);
		}
	}
	for (i = 0; i < mv; ++i) game(v[i]),v[i].clear();
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < mv; ++j) {
			if ((i&(1 << j))==0) v[j].push_back(i);
		}
	}
	for (i = 0; i < mv; ++i) game(v[i]);

	for (printf("-1\n"), i = 1; i <= n; ++i)
		printf("%d ",*min_element(row[i].begin(),row[i].end()));
	fflush(stdout);
	return 0;
}