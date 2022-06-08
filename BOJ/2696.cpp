//bs
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int P[9999];
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, M;
		vector<int> ans;
		set<pair<int,int> > st;
		for (scanf("%d", &M), i = 0; i < M; ++i) {
			scanf("%d", P+i);
			st.insert({P[i],i});
		}
		auto it = st.begin();
		for (i = 0; i < M / 2; ++i) it = next(it);
		i = M - 1;
		while (i > 1) {
			ans.push_back(it->first);
			int l = 0, r = 0;
			auto p1 = st.lower_bound({ P[i],i }); --i;
			if (*p1 < *it) ++l;
			else if (*p1 > *it) ++r;

			auto p2 = st.lower_bound({ P[i],i }); --i;
			if (*p2 < *it) ++l;
			else if (*p2 > *it) ++r;

			if (l + r == 2) {
				st.erase(p1); st.erase(p2);
				if (l > r)it = next(it);
				else if (l < r) it = prev(it);
			}
			else {
				auto x = *it;
				st.erase(p1); st.erase(p2);
				it = st.upper_bound(x);
				if (l < r) it = prev(it);
			}
			
		}
		ans.push_back(it->first);
		reverse(ans.begin(), ans.end());

		for (printf("%d\n", ans.size()), i = 0; i < ans.size(); ++i) {
			if (i > 0 && i % 10 == 0) puts("");
			printf("%d ", ans[i]);
		}
		if (i % 10 > 0) puts("");

	}
	return 0;
}
