//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int d[3];
		scanf("%d%d%d",d,d+1,d+2);
		sort(d, d + 3);
		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			if (d[i]) ++ans, --d[i];
		}
		if (d[1] > 0 && d[2] > 0) ++ans,--d[1],--d[2];
		if (d[0] > 0 && d[2] > 0) ++ans, --d[0], --d[2];
		if (d[1] > 0 && d[0] > 0) ++ans, --d[0], --d[1];
		if (d[0] > 0 && d[1] > 0 && d[2] > 0) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}