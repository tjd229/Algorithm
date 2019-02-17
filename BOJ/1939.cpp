//graph, djs, greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int A[100000], B[100000], C[100000];
int order[100000];
int p[10001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i,ix;
	int N, M;
	int u, v;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) p[i] = i;
	for (i = 0; i < M; ++i) scanf("%d%d%d",A+i,B+i,C+i),order[i]=i;
	sort(order, order + M, [](int ix1, int ix2) {
		return C[ix1] > C[ix2];
	});
	for (scanf("%d%d", &u, &v), i = 0; i < M; ++i) {
		ix = order[i];
		un(A[ix], B[ix]);
		if (find(u) == find(v)) break;
	}
	printf("%d",C[ix]);
	return 0;
}