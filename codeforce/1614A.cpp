//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, l, r, k;
		vector<int> choco;
		for (scanf("%d%d%d%d", &n, &l, &r, &k), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			if (l <= a && a <= r) {
				choco.push_back(a);
			}
		}
		sort(choco.begin(), choco.end());
		int ans = 0;
		for (i = 0; i < choco.size() && k>=0; ++i) {
			if (k - choco[i] >= 0) {
				k -= choco[i];
				++ans;
			}
		}
		printf("%d\n",ans);
	}
 
	return 0;
}