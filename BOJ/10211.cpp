//dp
#include <stdio.h>
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, N;
		int sum = 0;
		int ans = -1e9;
		for (scanf("%d", &N), i = 1; i <= N; ++i) {
			int X;
			scanf("%d",&X);
			sum += X;
			if (ans < X) ans = X;
			if (ans < sum) ans = sum;
			if (sum < 0) sum = 0;
		}
		printf("%d\n",ans);
	}
	return 0;
}