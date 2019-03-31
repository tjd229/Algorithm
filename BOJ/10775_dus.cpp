//djs
#include <stdio.h>
int p[100001],g[100001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {//a<b
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, G, P;
	int ans = 0;
	for (scanf("%d%d", &G, &P), i = 1; i <= G; ++i) p[i] = i;
	for (i = 1; i <= P; ++i) scanf("%d",g+i);
	for (i = 1; i <= P; ++i,++ans) {
		int p = find(g[i]);
		if (!p) break;
		un(p - 1, p);
	}
	printf("%d",ans);
	return 0;
}