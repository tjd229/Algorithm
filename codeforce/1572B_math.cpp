//math, greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[200001];
 
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		vector<int> ans;
		int cum = 0; int sum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i); cum ^= a[i];
			sum += a[i];
		}
		if (cum) {
			printf("NO\n");
			continue;
		}
		else if (sum == 0) {
			printf("YES\n0\n");
			continue;
		}
		if (n & 1) {
			vector<int> ans;
			for (i = 1; i + 2 <= n; i += 2) ans.push_back(i);
			for (i = ans.back() - 2; i > 0; i -= 2) ans.push_back(i);
			printf("YES\n%d\n",ans.size());
			for (auto x : ans) printf("%d ",x);
			puts("");
		}
		else {
			cum = 0; int m = -1;
			for (i = 1; i <= n; ++i) {
				cum ^= a[i];
				if (cum == 0 && (i & 1)) {
					m = i;
					break;
				}
			}
			if (m < 0)
				printf("NO\n");
			else {
				for (i = 1; i + 2 <= m; i += 2) ans.push_back(i);
				if(ans.size())
					for (i = ans.back() - 2; i > 0; i -= 2) ans.push_back(i);
				
				for (i = m + 1; i + 2 <= n; i += 2) ans.push_back(i);
				for (i = ans.back() - 2; i > m; i -= 2) ans.push_back(i);
				printf("YES\n%d\n", ans.size());
				for (auto x : ans) printf("%d ", x);
				puts("");
			}
		}
	}
 
	return 0;
}