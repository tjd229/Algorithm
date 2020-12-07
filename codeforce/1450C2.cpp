//math
#include <stdio.h>
#include <vector>
#define pii pair<int,int> 
using namespace std;
char grid[301][301];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n,k=0;
		vector<pii > X[3], O[3];
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				scanf(" %c", grid[i] + j);
				if (grid[i][j] == 'X')
					X[(i + j) % 3].push_back({ i,j }),++k;
				else if (grid[i][j] == 'O')
					O[(i + j) % 3].push_back({i,j}),++k;
			}
		}
		int bnd = k / 3;
		int clr_X = -1, clr_O = -1;
		for (i = 0; i < 3 && clr_X<0; ++i) {
			for (j = 0; j < 3 && clr_O<0; ++j) {
				if (i == j) continue;
				if (X[i].size() + O[j].size() <= bnd) {
					clr_X = i; clr_O = j;
				}
			}
		}
		if (clr_X >= 0) {
			for (auto p : X[clr_X]) {
				int y = p.first, x = p.second;
				grid[y][x] = 'O';
			}
		}
		if (clr_O >= 0) {
			for (auto p : O[clr_O]) {
				int y = p.first, x = p.second;
				grid[y][x] = 'X';
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) printf("%c",grid[i][j]);
			puts("");
		}
	}
 
	return 0;
}