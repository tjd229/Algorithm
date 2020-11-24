//math
#include <stdio.h>
int A[1001];
int ask(int L, int R) {
	printf("? %d %d\n", L, R); fflush(stdout);
	int num; scanf("%d",&num);
	return num;
}
int main() {
	int i, N; scanf("%d",&N);
	int s12 = ask(1, 2);
	A[3] = ask(1, 3) - s12;
	A[2] = ask(2, 3) - A[3];
	A[1] = s12 - A[2];
	for (i = 4; i <= N; ++i) A[i] = ask(i - 1, i) - A[i - 1];
	for (printf("!"), i = 1; i <= N; ++i) printf(" %d",A[i]);
	fflush(stdout);
	return 0;
}