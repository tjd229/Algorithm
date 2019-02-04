//math

#include <stdio.h>
int T[1001];
int sum[1001];
int main() {
	for (int i = 1; i <= 1000; ++i) T[i] = T[i - 1] + i;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = i; j <= 1000; ++j) {
			int s = T[i] + T[j];
			if (s <= 1000) sum[s] = 1;
		}
	}
	int tc,K;
	for (scanf("%d", &tc); tc--;) {
		bool flag = 0;
		scanf("%d",&K);
		for (int i = 1; i <= 1000  &&!flag; ++i) {
			if (T[i] > K) break;
			flag |= sum[K - T[i]];
		}
		printf("%d\n",flag);
	}
	return 0;
}
