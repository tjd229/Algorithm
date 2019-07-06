//graph
#include <stdio.h>
int d[100001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		++d[u]; ++d[v];
	}
	for (i = 1; i <= n; ++i) {
		if (d[i] == 2) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}