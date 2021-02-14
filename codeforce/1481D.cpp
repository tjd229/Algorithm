//graph
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
char mat[1001][1001];
vector<int> to[1001][2];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			to[i][0].clear(); to[i][1].clear();
			for(int j=1;j<=n;++j)
				scanf(" %c", mat[i] + j);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (i == j) continue;
				to[i][mat[i][j] - 'a'].push_back(j);
			}
		}
		int u = -1, v = -1;
		for (i = 1; i <= n && u<0; ++i) {
			for (int j = i + 1; j <= n && u<0; ++j) {
				if (mat[i][j] == mat[j][i])
					u = i, v = j;
			}
		}
		if (u > 0) {
			++m;
			for (printf("YES\n"); m;) {
				printf("%d ",u); --m;
				if (m) printf("%d ",v), --m;
			}
		}
		else if (m & 1) {
			++m;
			for (printf("YES\n"); m;) {
				printf("1 "); --m;
				if (m) printf("2 "),--m;
			}
		}
		else {//m is even
			int z;
			if (m & 2) {
				for (i = 1; i <= n && u<0; ++i) {
					for (int j = 0; j < 2 && u < 0; ++j) {
						for (auto x : to[i][j]) {
							for (auto y : to[x][j]) {
								if (y != i) {
									u = i; v = x; z = y;
									break;
								}
							}
							if (u > 0) break;
						}
					}
				}
				if (u > 0 && v > 0) {
					printf("YES\n%d ",u);
					int half = m >> 1;
					while(half) {//odd
						printf("%d ",v); --half;
						if (half) printf("%d ",u), --half;
					}
					half = m >> 1;
					while (half) {
						printf("%d ", z); --half;
						if (half) printf("%d ", v), --half;
					}
				}
				else printf("NO");
			}
			else {//4n
				for (i = 1; i <= n && u < 0; ++i) {
					for (int j = 0; j < 2 && u < 0; ++j) {
						for (auto x : to[i][j]) {
							for (auto y : to[x][j]) {
								if (y != i) {
									u = i; v = x; z = y;
									break;
								}
							}
							if (u > 0) break;
						}
					}
				}
				if (u > 0 && v > 0) {
					printf("YES\n%d ",v);
					while (m) {
						printf("%d %d %d %d ",z,v,u,v);
						m -= 4;
					}
				}
				else printf("NO");
			}
		}
		puts("");
	}
 
 
	return 0;
}
