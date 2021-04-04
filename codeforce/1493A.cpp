//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, n, k; scanf("%d%d",&n,&k);
		vector<int>ans;
		for (i = k + 1; i <= n; ++i) ans.push_back(i);
		for (i = k - 1; i > 0; --i) {
			int p = k - i;
			if (p > i) break;
			ans.push_back(i);
		}
		printf("%d\n",ans.size());
		for (auto x : ans)printf("%d ",x);
		puts("");
	}
 
	return 0;
}