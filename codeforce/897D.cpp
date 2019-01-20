//bs
#include <stdio.h>
int n, m, c;
int l, r;
int sheet[1001];
void left(int p) {
	int i;
	for (i = 1; i <= l && sheet[i] <= p; ++i);
	if (i > l) ++l;
	sheet[i] = p;
	printf("%d\n", i); fflush(stdout);
}
void right(int p) {
	int i;
	for (i = n; i >=r && sheet[i] >= p; --i);
	if (i < r) --r;
	sheet[i] = p;
	printf("%d\n", i); fflush(stdout);
}
int main() {
	int p;
	scanf("%d%d%d",&n,&m,&c);
	int half = c >> 1;
	l = 0;
	r = n+1;
	while (scanf("%d", &p)) {
		if (p > half) right(p);
		else left(p);
		if (r - l == 1) break;
	}
	return 0;
}
