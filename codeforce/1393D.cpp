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
int n, m;
char mp[2002][2002];
int l[2002][2002];
int r[2002][2002];
int c[2002][2002];
int u[2002][2002];
int d[2002][2002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) scanf(" %c",mp[i]+j);
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (mp[i][j - 1] == mp[i][j]) l[i][j] = l[i][j-1] + 1;
			else l[i][j] = 0;
		}
		for (j = m; j >= 1; --j) {
			if (mp[i][j + 1] == mp[i][j]) r[i][j] = r[i][j + 1] + 1;
			else r[i][j] = 0;
		}
		for (j = 1; j <= m; ++j) c[i][j] = 1+(min(l[i][j], r[i][j])<<1);
	}
	for (j = 1; j <= m; ++j) {
		for (i = 1; i <= n; ++i) {
			if (mp[i - 1][j] == mp[i][j]) u[i][j] = min(u[i-1][j] + 2, c[i][j]);
			else u[i][j] = 1;
		}
		for (i = n; i >= 1; --i) {
			if (mp[i + 1][j] == mp[i][j]) d[i][j] = min(d[i+1][j] + 2, c[i][j]);
			else d[i][j] = 1;
		}
	}
	ll ans = 0;
	/*for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
 
			printf("%d ", c[i][j]);
		}
		puts("");
	}
	puts("");
	
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
 
			printf("%d ", u[i][j]);
		}
		puts("");
	}
	puts("");
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
 
			printf("%d ", d[i][j]);
		}
		puts("");
	}*/
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			int cnt = min(u[i][j], d[i][j]);
			ans += (cnt >> 1)+ 1;
			//printf("%d ",cnt);
		}
		//puts("");
	}
	printf("%I64d",ans);
	return 0;
}