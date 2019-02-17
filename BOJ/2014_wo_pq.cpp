//greedy
#include <stdio.h>
int arr[100001];
int p[100];
int pt[100];
int main() {
	int i, j,K, N;
	for (scanf("%d%d", &K, &N), i = 0; i < K; ++i) scanf("%d",p+i);
	arr[0] = 1;
	for (i = 1; i <= N; ++i) {
		int &mn = arr[i];
		mn = -1;
		int k = 0;
		for (j = 0; j < K; ++j) {
			long long r = p[j] * arr[pt[j]];
			if (mn<0 || mn>r) mn = r, k = j;
			else if (mn == r) ++pt[j];
		}
		++pt[k];
	}
	printf("%d",arr[N]);
	return 0;
}