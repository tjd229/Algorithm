//dp
#include <stdio.h>
char s[5002], t[5002];
int d[5001][5002];
int main() {
	int i,j, T;
	
	for (scanf("%d", &T); T--;) {
		int n, m; scanf("%d%d %s %s",&n,&m,s+1,t+1);
		for (i = 1; i <= n; ++i) for (j = 1; j <= m+1; ++j) d[i][j] = -1;
		int suf = 0;
		for (i = n; i > 0; --i) {
			if (t[m] == s[i]) {
				d[i][m] = n - i;
				suf = 1;
			}
			else {
				if (suf)
					d[i][m] = n - i + 1;
			}
		}
		for (j = m - 1; j > 0; --j) {
			int last[26] = { 0 };
			last[s[n] - 'a'] = n;
			for (i = n - 1; i > 0; --i) {
				if (s[i] == t[j]) {
					int r = last[t[j + 1] - 'a'];
					if (r > 0) {
						if (d[r][j + 1] != -1) {
							if (r == i + 1 && s[r] == t[j + 1])
								d[i][j] = d[r][j + 1];
							else {
								int len = n - i;
								d[i][j] = len;
							}
						}
					}
				}
				else {
					if (d[i + 1][j] == -1) d[i][j] = -1;
					else
						d[i][j] = n-i+1;
				}
				
				last[s[i] - 'a'] = i;
			}
		}
		/*for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) printf("%02d ",d[i][j]);
			puts("");
		}*/
		int ans = d[1][1];
		//printf("%d\n",ans);
		for (i = 1; i < n; ++i) {
			int cost = i + i + 1;
			if (d[i + 1][1] != -1) {
				cost += d[i + 1][1];
				if (ans<0 || ans>cost) ans = cost;
			}
		}
		for (i = 1; i <=m;++i) {
			int p = 1;
			int ed = 0;
			int w = 0;
			for (j = 1; j < n; ++j) {
				if (p <= i && s[j] == t[p]) {
					int cost, suffix;
					if (ed == 0) cost = 0;
					else cost = ed + 1 + w;
					++p;
					if(p<=m )suffix = d[j + 1][p];
					else 
						suffix = n - (j + 1) + 1;
					
					if (suffix != -1) {
						if (ans<0 || ans>cost + suffix)
							ans = cost + suffix;
					}
				}
				else {
					ed = j; ++w;
					int cost, suffix;
					cost = ed + 1 + w;
					if (p <= m )suffix = d[j + 1][p];
					else
						suffix = n - (j + 1) + 1;
					if (suffix != -1) {
						if (ans<0 || ans>cost + suffix)
							ans = cost + suffix;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
