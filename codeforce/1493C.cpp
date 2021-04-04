//string, greedy
#include <stdio.h>
char s[100001];
char ans[100002];
int rs[26][100001];
int n, k;
void make_beautiful(int s,int buck[26]) {
	int j = 0;
	for (int i = s; i <= n; ++i) {
		while (buck[j] == 0) ++j;
		ans[i] = j + 'a';
		--buck[j];
	}
}
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		int i;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
			scanf(" %c", s + i); ans[i] = s[i];
			for (int j = 0; j < 26; ++j) rs[j][i] = 0;
		}
		if (n%k) {
			printf("-1\n");
			continue;
		}
		ans[n + 1] = '\0';
		for (i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j) rs[j][i] += rs[j][i - 1];
			++rs[s[i] - 'a'][i];
		}
		bool flag = 1;
		for (int i = 0; flag &&i < 26; ++i) {
			int r = rs[i][n] % k;
			if (r) flag = 0;
		}
		if (flag) {
			printf("%s\n",ans+1);
			continue;
		}
		flag = 0;
		for (i = n; i >= 0 && flag==0; --i) {
			int buck[26] = { 0 };
			for (int j = 0; j < 26; ++j) {
				int r = rs[j][i - 1] % k;
				if (r) {
					buck[j] = k - r;
				}
			}
			for (int tgt = s[i] - 'a' + 1; tgt < 26; ++tgt) {
				int suf = n - i;
				int r = (rs[tgt][i - 1]+1) % k;
				if (r) buck[tgt] = k - r;
				else buck[tgt] = 0;
 
				for (int j = 0; j < 26; ++j) suf -= buck[j];
				if (suf < 0 || suf % k) {
					int r= rs[tgt][i - 1] % k; //buck init
					if (r) buck[tgt] = k - r;
					else buck[tgt] = 0;
					continue;
				}
				buck[0] += suf;
				ans[i] = tgt + 'a';
				make_beautiful(i + 1, buck);
				flag = 1;
				break;
			}
 
		}
		printf("%s\n", ans + 1);
	}
 
	return 0;
}