//dp
#include <stdio.h>
char s[300001];
int sum[2][300001];
int last[2];
int main() {
	int i, n;
	long long ans = 0;
	for (scanf("%d %s", &n, s + 1), i = 1; i <= n;++i) {
		sum[0][i] = sum[0][i - 1] + (s[i] == 'A');
		sum[1][i] = sum[1][i - 1] + (s[i] == 'B');
	}
	last[s[1] - 'A'] = 1;
	for (i = 2; i <= n; ++i) {
		int c = s[i] - 'A';
		if (s[i] == s[i - 1]) {
			int same = sum[c][i - 1];
			int diff = sum[1-c][i - 1]-1;
			ans += same;
			if (diff > 0) ans += diff;
		}
		else {
			ans += sum[c][last[c]];
			ans+= sum[1-c][last[c]];
		}
		last[c] = i;
		//printf("%I64d\n", ans);
	}
	printf("%I64d",ans);
	
	return 0;
}