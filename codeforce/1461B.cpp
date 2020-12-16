//implementation
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
char mat[502][502];
int s[502][502];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) scanf(" %c",mat[i]+j);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) s[i][j] = s[i][j - 1] + (mat[i][j] == '*');
		}
		int cnt = 0;
		for (i = 1; i <= n; ++i) {
			for ( j = 1; j <= m; ++j) {
				if (mat[i][j] == '*') {
					//printf("%d,%d\n",i,j);
					for (int k = 0; i+k <= n; ++k) {
						if (j - (k+1) + 1 < 1 || j + (k+1) - 1 > m) break;
						//printf("%d~%d : %d? -> %d\n",j-k,j+k-1,2*(k-1)+1, s[k][j + k - 1] - s[k][j - k]);
						if (s[i+k][j + k +1- 1] - s[i+k][j - (k+1)] == 2 * k + 1) ++cnt;
						else break;
					}
					//printf("%d\n", cnt);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}