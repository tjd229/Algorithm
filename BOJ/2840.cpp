//implementation
#include <stdio.h>
char wedge[25];
bool flag = 0;
int main() {
	int i, N, K;
	for (scanf("%d%d", &N, &K), i = 0; K--;) {
		int S;
		char c;
		scanf(" %d %c",&S,&c);
		i = (i + S) % N;
		if (wedge[i]) flag |= wedge[i]!=c;
		wedge[i] = c;
	}
	K = i;
	int stat = 0;
	for (i = 0; i < N; ++i) {
		if (wedge[i]) {
			if (stat&(1 << (wedge[i] - 'A'))) flag = 1;
			stat |= (1 << (wedge[i] - 'A'));
		}
	}
	if (flag) printf("!");
	else {
		i = K;
		K = N;
		while (K--) {
			printf("%c",wedge[i]? wedge[i]:'?');
			if (--i < 0) i = N - 1;
		}
	}
	return 0;
}