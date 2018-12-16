//implementation

#include <stdio.h>
int vis[1000000];
int p[10];
int main() {
	int A, P;
	int i,j;
	for (scanf("%d%d", &A, &P), i = 1; i < 10; ++i) {
		p[i] = 1;
		for (int j = 0; j < P; ++j) p[i] *= i;
	}
	vis[A] = 1;
	for (i = 2;; ++i) {
		int nxt = 0;
		while (A) {
			nxt += p[A % 10];
			A /= 10;
		}
		A = nxt;
		if (vis[A]) break;
		vis[A] = i;		
	}
	printf("%d",vis[A]-1);
	return 0;
}
