//dp
#include <stdio.h>
#include <algorithm>
using namespace std;
int r[201], g[201], b[201];
int d[201][201][201];
int main() {
	int i, R, G, B;
	for (scanf("%d%d%d", &R, &G, &B), i = 1; i <= R; ++i) scanf("%d",r+i);
	for (i = 1; i <= G; ++i) scanf("%d",g+i);
	for (i = 1; i <= B; ++i) scanf("%d",b+i);
	sort(r + 1, r + 1 + R); sort(g + 1, g + 1 + G); sort(b + 1, b + 1 + B);
	int ans = 0;
	for (i = 0; i <= R; ++i) {
		for (int j = 0; j <= G; ++j) {
			for (int k = 0; k <= B; ++k) {
				if (i + 1 <= R && j + 1 <= G)
					d[i + 1][j + 1][k] = max(d[i + 1][j + 1][k], d[i][j][k] + r[i+1] * g[j+1]);
				if(i+1<=R && k+1<=B)
					d[i + 1][j][k+1] = max(d[i + 1][j ][k+1], d[i][j][k] + r[i+1] * b[k+1]);
				if(j+1<=G && k+1<=B)
					d[i][j + 1][k+1] = max(d[i][j + 1][k+1], d[i][j][k] + b[k+1] * g[j+1]);
				ans = max(ans, d[i][j][k]);
				
			}
		}
	}
	printf("%d\n",ans);
 
	return 0;
}