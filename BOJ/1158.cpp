//implementation

#include <stdio.h>
int l[5001], r[5001];
int main() {
	int i,j;
	int N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N;++i) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	l[1] = N;
	r[0] = r[N] = 1;
	int cur = 0;
	printf("<");
	for (i = 1; i < N; ++i) {
		for (j = 0; j < M; ++j) 
			cur = r[cur];
		l[r[cur]] = l[cur];
		r[l[cur]] = r[cur];
		printf("%d, ",cur);
	}
	printf("%d>",r[cur]);
	

	return 0;
}
