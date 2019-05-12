//bs
#include <stdio.h>
int N;
int c[151];
int ask(int s,int e,int piv=0) {
	int len = e - s + 1 + (piv > 0);
	if (len == 1) return 1;
	printf("%d ",len);
	for (int i = s; i <= e; ++i) printf("%d ",i);
	if (piv) printf("%d ",piv);
	printf("\n"); fflush(stdout);
	int diff; scanf("%d",&diff);
	return diff;
}
int find(int piv,int s,int e) {
	if (s == e) return s;
	int m = (s + e) >> 1;
	if (ask(s, m, piv) == ask(s, m))
		return find(piv,s,m);
	return find(piv, m + 1, e);
}
int main() {
	int i, cnt = 0;
	for (scanf("%d",&N),i = 1; i < N; ++i) {
		if (!c[i]) c[i]=++cnt;
		if (ask(i, N) == ask(i + 1, N)) {
			int r = find(i,i+1,N);
			c[r] = c[i];
		}
	}
	if (!c[i]) c[i] = ++cnt;
	for (printf("0 "), i = 1; i <= N; ++i) printf("%d ",c[i]);
	fflush(stdout);
	return 0;
}