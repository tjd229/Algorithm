//dp, string
#include <stdio.h>
char s[2001], t[2001];
int d[2001][2001];
int sss[26][2002], tss[26][2002];
int op(int i,int j) {
	if (i == 0) return 0;
	if (i > j) return 1e9;
	if (d[i][j] >= 0) return d[i][j];
	int &cache = d[i][j];
	cache = 1e9;
	if (s[i] == t[j]) {
		int nxt = op(i - 1, j - 1);
		if (cache > nxt) cache = nxt;
	}
	else {
		int nxt = op(i - 1, j) + 1;
		if (cache > nxt) cache = nxt;
		int tgt = t[j] - 'a';
		if (i<j && sss[tgt][i + 1] > tss[tgt][j + 1]) {
			nxt = op(i, j - 1);
			if (cache > nxt) cache = nxt;
		}
	}
	return cache;
}
int main() {
	int i, T;
	for (scanf("%d", &T); T--;) {
		int n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf(" %c",s+i);
		for (i = 1; i <= n; ++i) scanf(" %c",t+i);
		for (i = 0; i < 26; ++i) sss[i][n + 1] = tss[i][n + 1] = 0;
		for (i = n; i > 0; --i) {
			for (int j = 0; j < 26; ++j) {
				sss[j][i] = sss[j][i + 1] + (s[i] == j + 'a');
				tss[j][i] = tss[j][i + 1] + (t[i] == j + 'a');
			}
		}
		bool valid = 1;
		for (i = 0; i < 26 && valid; ++i) 
			valid &= (sss[i][1] == tss[i][1]);
		if (!valid) {
			printf("-1\n");
			continue;
		}
		for (i = 1; i <= n; ++i) for (int j = i; j <= n; ++j) d[i][j] = -1;
		printf("%d\n",op(n,n));
	}
 
	return 0;
}