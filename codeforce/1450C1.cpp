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
char grid[301][301];
char c[304][304];
int pat[6][3] = { {0,1,2},{1,2,0},{2,0,1},{0,2,1},{2,1,0},{1,0,2} };
int n;
int sim(int pat[3]) {
	int op = 0;
	for (int i = 1; i <= n + 3; ++i) for (int j = 1; j <= n + 3; ++j) c[i][j] = grid[i][j];
	int tgt = pat[0];
	int tix = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1 + tgt; j <= n; j += 3) {
			if ((c[i][j] == 'X' && c[i][j + 1] == 'X' && c[i][j + 2] == 'X')
				|| (c[i][j - 1] == 'X' && c[i][j + 1] == 'X' && c[i][j] == 'X')
				|| (j > 1 && c[i][j] == 'X' && c[i][j - 1] == 'X' && c[i][j - 2] == 'X')) {
				c[i][j] = 'O';
				++op;
				//j += 3;
			}
			//else ++j;
		}
		tix = (tix + 1) % 3;
		tgt = pat[tix];
	}
	tgt = pat[0];
	tix = 0;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1 + tgt; i <= n; i += 3) {
			if ((c[i][j] == 'X' && c[i + 1][j] == 'X' && c[i + 2][j] == 'X')
				|| (c[i][j] == 'X' && c[i + 1][j] == 'X' && c[i - 1][j] == 'X')
				|| (i > 1 && c[i][j] == 'X' && c[i - 1][j] == 'X' && c[i - 2][j] == 'X')) {
				c[i][j] = 'O';
				++op;
				//i += 3;
			}
			//else ++i;
		}
		tix = (tix + 1) % 3;
		tgt = pat[tix];
	}
	return op;
}
int main() {
	int i, j;
	int t;
	for (scanf("%d", &t); t--;) {
 
		int k = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				scanf(" %c", grid[i] + j);
				if (grid[i][j] != '.') ++k;
			}
		}
		int bnd = k / 3;
		for (i = 0; i < 6; ++i) {
			int op = sim(pat[i]);
			//printf("%d,%d\n",i,op);
			if (op <= bnd) break;
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) printf("%c", c[i][j]);
			puts("");
		}
		for (i = 1; i <= n; ++i) for (j = 1; j <= n; ++j) grid[i][j] = 0;
	}
 
 
	return 0;
}