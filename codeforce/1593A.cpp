//implementation
#include <stdio.h>
int max(int a, int b) { return a < b ? b : a; }
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		int A, B, C;
		int mx = max(b, c);
		if (a > mx) A = 0;
		else A = mx - a + 1;
		mx = max(a, c);
		if (b > mx) B = 0;
		else B = mx - b + 1;
		mx = max(a, b);
		if (c > mx) C = 0;
		else C = mx - c + 1;
		printf("%d %d %d\n",A,B,C);
	}
 
	return 0;
}