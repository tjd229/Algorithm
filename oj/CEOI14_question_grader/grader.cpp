#include <stdio.h>
#include <stdlib.h>

static void ERROR (const char *s) {
	printf("Error - %s\n", s);
	exit(0);
}

#define MAXT 2000005
static int N, T;
static int H[MAXT], Q[MAXT], A[MAXT], X[MAXT], Y[MAXT];

int encode (int N, int x, int y);
int decode (int N, int q, int h);

int main() {
	int i;

	if(scanf("%d%d", &N, &T) != 2) ERROR("N and T must be given in the first line");
	if(N < 1 || N > 920) ERROR("N is out of range([1, 920])");
	if(T < 1 || T > 2000000) ERROR("T is out of range([1, 2000000])");

	int maxh = -1;
	for(i = 0; i < T; i++) {
		int x, y, q; 
		if(scanf("%d%d%d", &x, &y, &q) != 3) ERROR("x and y must be given in the following N lines");
		if(x < 1 || x > N) ERROR("x is out of range([1, N])");
		if(y < 1 || y > N) ERROR("y is out of range([1, N])");
		if(x == y) ERROR("x and y must be different");
		if(q != x && q != y) ERROR("q must be equal to x or equal to y");
		H[i] = encode(N, x, y);
		if(maxh < H[i]) maxh = H[i];
		if(H[i] < 1) {
			printf("Incorrect - the encoded value must be greater than or equal to 1");
			printf(" : encode(%d, %d, %d)\n", N, x, y);
			return 0;
		}
		Q[i] = q; A[i] = (q == x) ? 1 : 0; X[i] = x, Y[i] = y;
	}

	for(i = 0; i < T; i++) {
		int a = decode(N, Q[i], H[i]);
		if(a != A[i]) {
			printf("Incorrect - Wrong answer on case %d: "
				"x = %d, y = %d, q = %d, h = %d, answer = %d, your_answer = %d\n"
				, i+1, X[i], Y[i], Q[i], H[i], A[i], a);
			return 0;
		}
	}

	printf("Correct - max_h = %d\n", maxh);
	return 0;
}
