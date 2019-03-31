//graph, djs
#include <stdio.h>
const int mod = 1000;
int p[20001],len[20001];
int find(int a) {
	if (p[a] != a) {
		int pp = find(p[a]);
		if (pp != p[a]) len[a] += len[p[a]];
		p[a] = pp;
	}
	return p[a];
}
void un(int a, int b) {
	p[a] = b;
	int d = a - b;
	if (d < 0) d = -d;
	len[a] += d % mod;
}
int main() {
	int i, T, N;
	for (scanf("%d", &T); T--;) {
		for (scanf("%d", &N), i = 1; i <= N; ++i) p[i] = i,len[i]=0;
		char c; int I, J;
		while (scanf(" %c", &c)) {
			if (c == 'O') break;
			scanf("%d",&I);
			if (c == 'E') {
				find(I);
				printf("%d\n", len[I]);
			}
			else {
				scanf("%d",&J);
				un(I, J);
			}
		}
	}
	return 0;
}