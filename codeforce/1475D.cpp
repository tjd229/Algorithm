//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int a[200001], b[200001];
 
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int i, n, m; scanf("%d%d", &n, &m);
		vector<int> stk1, stk2;
		ll cap = -m;
		ll use = 0;
		ll conv = 0; ll tot = 0;
		for (i = 1; i <= n; ++i) scanf("%d", a + i), cap += a[i];
		for (i = 1; i <= n; ++i) scanf("%d", b + i), tot += b[i];
		if (cap < 0) {
			printf("-1\n");
			continue;
		}
		for (i = 1; i <= n; ++i) {
			if (b[i] == 1) stk1.push_back(a[i]);
			else stk2.push_back(a[i]),use+=a[i];
		}
		sort(stk1.begin(), stk1.end()); sort(stk2.begin(), stk2.end());
		reverse(stk1.begin(), stk1.end());
		conv = 2 * stk2.size();
		ll ans = tot;
		while (stk2.size()) {
			while (stk1.size() && stk1.back() + use <= cap) {
				++conv;
				use += stk1.back(); stk1.pop_back();
			}
			if (cap >= use && ans > tot - conv) ans = tot - conv;
			use -= stk2.back(); stk2.pop_back();
			conv -= 2;
		}
		while (stk1.size() && stk1.back() + use <= cap) {
			++conv;
			use += stk1.back(); stk1.pop_back();
		}
		if (cap >= use && ans > tot - conv) ans = tot - conv;
		
		printf("%I64d\n", ans);
	}
	return 0;
}