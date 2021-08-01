//string
#include <stdio.h>
#include <algorithm>
using namespace std;
char s[200001];
char pat[6]= {"abc"};
int dist[6][200001];
int main() {
	int i,j, n, m;
	int t = 0;
	scanf("%d%d %s",&n,&m,s+1);
	do {
		int *d = dist[t++];
		for (i = 1, j = 0; i <= n; ++i) {
			if (s[i] != pat[j]) d[i] = 1;
			j = (j + 1) % 3;
		}
		for (i = 1; i <= n; ++i) d[i] += d[i - 1];
	} while (next_permutation(pat,pat+3));
	while (m--) {
		int l, r; scanf("%d%d",&l,&r);
		int ans = dist[0][r] - dist[0][l-1];
		for (i = 1; i < 6; ++i) {
			int d = dist[i][r] - dist[i][l - 1];
			if (ans > d) ans = d;
		}
		printf("%d\n",ans);
	}
 
 
	return 0;
}