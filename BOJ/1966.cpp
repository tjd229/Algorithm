//math
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int i, tc;
	for (scanf("%d", &tc); tc--;) {
		int N,k;
		int piv;
		int doc;
		int loc = -1;
		int ans = 0;
		vector<int> pos[10];
		for (scanf("%d%d", &N, &k), i = 0; i < N; ++i) {
			scanf("%d",&doc);
			pos[doc].push_back(i);
			if (i == k) piv = doc;
		}
		for (i = 9; i > piv; --i) {
			if (pos[i].empty()) continue;
			auto it = lower_bound(pos[i].begin(), pos[i].end(),loc);
			if (it == pos[i].begin()) it = pos[i].end();
			loc=*(--it);
			ans += pos[i].size();
		}
		if (loc < k)
			ans += upper_bound(pos[i].begin(), pos[i].end(), k)
			- lower_bound(pos[i].begin(), pos[i].end(), loc);
		else
			ans += pos[i].end() - lower_bound(pos[i].begin(), pos[i].end(), loc)
			+ upper_bound(pos[i].begin(), pos[i].end(), k) - pos[i].begin();
		printf("%d\n",ans);
	}
	return 0;
}
