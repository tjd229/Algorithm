//math, graph
#include <stdio.h>
int gen[10001];
int vis[10001];
int calc(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int dfs(int x) {
	if (vis[x]) return gen[x];
	vis[x] = 1;
	int nxt = x + calc(x);
	if (nxt <= 10000) {
		gen[nxt] = x;
		dfs(nxt);
	}
	return gen[x];
}
int main() {
	for (int i = 1; i <= 10000; ++i) {
		if (!dfs(i)) printf("%d\n",i);
	}
	return 0;
}