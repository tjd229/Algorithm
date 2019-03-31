//djs
#include <stdio.h>
int p[10001];
int A[10001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
	if (A[a] > A[b]) A[a] = A[b];
}
int main() {
	int i, N, M, k;
	int tot = 0;
	for (scanf("%d%d%d", &N, &M, &k), i = 1; i <= N; ++i) {
		scanf("%d", A +i);
		p[i] = i;
	}
	while (M--) {
		int v, w; scanf("%d%d",&v,&w);
		un(v, w);
	}
	for (i = 1; i <= N; ++i) {
		if (find(i) == i) tot += A[i];
	}
	if (tot > k) printf("Oh no");
	else printf("%d",tot);
	return 0;
}