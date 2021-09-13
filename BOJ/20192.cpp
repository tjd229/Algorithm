//greedy
#include <stdio.h>
int A[300001];
int main() {
	int i, N;
	int d = 0;
	for (scanf("%d", &N), i = 1; i <= N-d; ++i) {
		scanf("%d", A + i);
		if (A[i] == A[i - 1]) {
			--i;
			++d;
		}
	}
	N -= d;
	int m = 1;
	for (i = 1; i <= N && m; ++i) {
		if (A[i - 1] > A[i]) m = 0;
	}
	if (m) {
		printf("0");
		return 0;
	}
	int seg = 0;
	int head = -1, tail=0;
	for (i = 1;i<=N;) {
		int j = i + 1;
		int sign=1-tail;
		if (i == 1)
			sign = A[j] >= A[i];
		if (j <= N) {
			while (j <= N) {
				if (sign && A[j] < A[j - 1]) break;
				else if (sign == 0 && A[j] >= A[j - 1]) break;
				++j;
			}
		}
		i = j;
		++seg;
		if (head < 0) head = sign;
		tail = sign;
	}
	int ans=0;
	if (head == 0) ++seg;
	while (seg>1) {
		if (seg & 1) ++seg;
		seg >>= 1;
		++ans;
	}
	printf("%d\n",ans);

	return 0;
}
