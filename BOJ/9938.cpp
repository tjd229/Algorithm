//graph, djs
#include <stdio.h>
int p[300001];
int cap[300001], in[300001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
	cap[a] += cap[b];
	in[a] += in[b];
}
int main() {
	int i, N, L;
	for (scanf("%d%d", &N, &L), i = 1; i <= L; ++i) p[i] = i, cap[i] = 1;
	while (N--) {
		int A, B; scanf("%d%d",&A,&B);
		un(A, B);
		A = find(A);
		if (in[A] < cap[A]) {
			++in[A];
			printf("LADICA\n");
		}
		else printf("SMECE\n");
	}
	return 0;
}