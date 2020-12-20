//djs
#include <stdio.h>
int par[10001],p[10001];
int find(int a) {
	if (par[a] != a) par[a] = find(par[a]);
	return par[a];
}
void dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	par[b] = a;
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d",p+i);
		par[i] = i;
	}
	for (i = 1; i <= n; ++i) dsu(i, p[i]);
	int num = 0;
	for (i = 1; i <= n; ++i) num += par[i] == i;
	printf("%d", num);

	return 0;
}