//greedy, math, bs
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int ans[10000];
vector<int> v[10000];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		int a; scanf("%d",&a);
		v[a].push_back(i);
	}
	for (i = 1; i <= 5000; ++i) {
		if (v[i].empty()) continue;
		for (int j = 1; j <= 8192; ++j) {
			if (ans[j]) {
				auto it = upper_bound(v[i].begin(), v[i].end(), ans[j]);
				int nxt = i ^ j;
				if (it != v[i].end()) {
					if (ans[nxt] == 0 || ans[nxt] > *it)
						ans[nxt] = *it;
				}
			}
		}
		if (ans[i] == 0 || ans[i] > v[i][0]) ans[i] = v[i][0];
	}
	int k = 1;
	for (i = 1; i <= 8192; ++i) k += ans[i] > 0;
	for (printf("%d\n0", k), i = 1; i <= 8192; ++i) {
		if(ans[i])
			printf(" %d", i);
	}
	return 0;
}