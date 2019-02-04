//implementation
#include <stdio.h>
int main() {
	int N, X, A;
	int i;
	int ans = 0;
	for (scanf("%d%d", &N, &X), i = 0; i < N; ++i) {
		scanf("%d",&A);
		if (X > A) printf("%d ",A);
	}
}
