//graph, djs

#include <stdio.h>
int p[201];
int find(int a) {
	if (p[a] != a)p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i,j, N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) p[i] = i;
	for(i=1;i<=N;++i){
		for (j = 1; j <= N; ++j) {
			int adj; scanf("%d",&adj);
			if (adj) un(i, j);
		}
	}
	bool flag = 1;
	int A, B;
	for (scanf("%d", &A), i = 1; i < M; ++i) {
		scanf("%d",&B);
		flag &= (find(A) == find(B));		
	}
	printf("%s",flag? "YES":"NO");
	return 0;
}