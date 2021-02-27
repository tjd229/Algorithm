//line sweeping
#include <stdio.h>
char s[200001], t[200001];
int p[200001],l[200001];
int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf(" %c",s+i);
	for (i = 1; i <= m; ++i) scanf(" %c",t+i);
	int j = m; i = n;
	while (j > 0) {
		while (t[j] != s[i]) --i;
		p[j--] = i--;
	}
	i = 1;
	for (int j = 1; j <= m; ++j) {
		while (t[j] != s[i]) ++i;
		l[j] = i++;
	}
	int ans = 0;
	for (i = 2; i <= m; ++i) {
		if (ans < p[i] - l[i - 1])
			ans = p[i] - l[i - 1];
	}
	printf("%d\n",ans);
 
	return 0;
}