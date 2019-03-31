//math
#include <stdio.h>
#define ll long long
int sieve[1000001];
int happy[1000001];
int vis[1000001];
int calc(int n) {
	int res = 0;
	while (n) {
		int b = n % 10;
		n /= 10;
		res += b * b;
	}
	return res;
}
int dfs(int n) {
	if (n == 1) 
		return 1;
	vis[n] = 1;
	int nxt = calc(n);
	if (vis[nxt] == 0) dfs(nxt);
	happy[n] = happy[nxt];
	return happy[n];
}
int main() {
	int i,n;
	for (i = 2, scanf("%d",&n); i <= n; ++i) {
		if (sieve[i]) continue;
		for (ll j = (ll)i*i; j <= n; j += i) sieve[j] = 1;
	}
	happy[1] = 1;
	for (i = 7; i <= n; ++i) {
		if(!sieve[i] && dfs(i))
			printf("%d\n", i);
	}
	return 0;
}