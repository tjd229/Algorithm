//d&c
#include <stdio.h>
char s[131073];
int good(char c,int st,int ed) {
	if (st == ed) return c != s[st];
	int m = (st + ed) >> 1;
	int cost = 0;
	for (int i = st; i <= m; ++i) cost += s[i] != c;
	cost += good(c + 1, m + 1, ed);
	int pre = cost;
	cost = 0;
	for (int i = m + 1; i <= ed; ++i) cost += s[i] != c;
	cost += good(c + 1, st, m);
	int post = cost;
	return pre < post ? pre : post;
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf(" %c",s+i);
		printf("%d\n",good('a',1,n));
	}
	return 0;
}
