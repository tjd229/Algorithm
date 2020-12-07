//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int board[2001][2001];
vector<int> row[2001][10];
vector<int> col[2001][10];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j,n;
		int d[10] = { 0 };
		int cnt[10] = { 0 };
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) scanf("%1d",board[i]+j),++cnt[board[i][j]];
		}
		for (i = 1; i <= n; ++i) {
			for (j = 0; j < 10; ++j) row[i][j].clear();
		}
		for (i = 1; i <= n; ++i) for (j = 0; j < 10; ++j) col[i][j].clear();
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				row[i][board[i][j]].push_back(j);
				col[j][board[i][j]].push_back(i);
			}
		}
		for (int k = 0; k < 10; ++k) {
			if (cnt[k] < 2) continue;
			int top = 10000, btm = 0;			
			for ( j = 1; j <= n; ++j) {
				if (col[j][k].empty()) continue;
				if (top > col[j][k][0]) top = col[j][k][0];
				if (btm < col[j][k].back()) btm = col[j][k].back();
			}
			int left = 10000, right = 0;
			for ( i = 1; i <= n; ++i) {
				if (row[i][k].empty()) continue;
				if (left > row[i][k][0]) left = row[i][k][0];
				if (right< row[i][k].back()) right = row[i][k].back();
				if (row[i][k].back() != 1) {
					int dx = row[i][k].back() - 1;
					int dy = btm - i < i - top ? i - top : btm - i;
					int area = dx * dy;
					if (area > d[k]) d[k] = area;
				}
				if (row[i][k][0] != n) {
					int dx = n - row[i][k][0];
					int dy = btm - i < i - top ? i - top : btm - i;
					int area = dx * dy;
					if (area > d[k]) d[k] = area;
				}
			}
			for (j = 1; j <= n; ++j) {
				if (col[j][k].empty()) continue;
				if (col[j][k].back() != 1) {
					int dy = col[j][k].back() - 1;
					int dx = right - j < j - left ? j - left : right - j;
					int area = dx * dy;
					if (area > d[k]) d[k] = area;
				}
				if (col[j][k][0] != n) {
					int dy = n-col[j][k][0];
					int dx = right - j < j - left ? j - left : right - j;
					int area = dx * dy;
					if (area > d[k]) d[k] = area;
				}
			}
		}
		for (int i = 0; i < 10; ++i) printf("%d ",d[i]);
		printf("\n");
	}
 
	return 0;
}