//math
#include <stdio.h>
int a, b;
int ask(int c,int d) {
	printf("? %d %d\n", c, d); fflush(stdout);
	int cmp; scanf("%d",&cmp);
	return cmp;
}
int main() {
	int step = 1 << 29;
	int big = ask(0,0);
	while (step) {
		int f = ask(a + step, b);
		int s = ask(a,b+step);
		if (f == s) {
			if (big > 0) a += step;
			else b += step;
			big = f;
		}
		else if (f < 0) {
			a += step;
			b += step;
		}
		step >>= 1;
	}
	printf("! %d %d", a, b); fflush(stdout);
	return 0;
}