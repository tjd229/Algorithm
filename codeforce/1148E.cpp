//line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
struct Tuple { int x, y, z; };
int s[300000], t[300000];
int main() {
	int i, n;
	vector<Tuple> ans;
	vector<pii > order;
	vector<int> stk;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d",s+i);
		order.push_back({s[i],i});
	}
	for (i = 0; i < n; ++i) scanf("%d",t+i);
	sort(order.begin(), order.end());
	sort(t, t+ n);
	for (i = 0; i < n; ++i) {
		int j = order[i].second;
		int d = t[i] - s[j];
		if (d > 0) stk.push_back(i);
		else if (d < 0) {
			int d2 = -d;
			while (d2) {
				if (stk.empty()) {
					printf("NO");
					return 0;
				}
				int top = stk.back(); stk.pop_back();
				int l = order[top].second;
				int d1 = t[top] - s[l];
				int min_d = d1 < d2 ? d1 : d2;
				ans.push_back({l+1,j+1,min_d});
				d1 -= min_d; d2 -= min_d;
				s[l] += min_d; s[j] -= min_d;
				if (d1) stk.push_back(top);
			}
			
		}
	}
	if (stk.size()) printf("NO");
	else {
		printf("YES\n%d\n",ans.size());
		for (auto t : ans) printf("%d %d %d\n",t.x,t.y,t.z);
	}
	return 0;
}