//djs
#include <stdio.h>
int p[1000001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i)p[i] = i;
	while (m--) {
		int c, a, b;
		scanf("%d%d%d",&c,&a,&b);
		if (c) printf("%s\n",find(a)==find(b)? "YES":"NO");
		else un(a, b);
	}
	return 0;
}