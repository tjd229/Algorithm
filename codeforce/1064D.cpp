//graph

#include <stdio.h>
#include <deque>
#define pii pair<int,int>
using namespace std;

char lyb[2002][2002];
int rx[2002][2002], ry[2002][2002];
bool vis[2002][2002];
int n, m;
int r, c;
int bfs() {
	int res = 0;
	deque<pii > q;
	q.push_back({ r,c });
	vis[r][c] = 1;

	while (q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();
		++res;
		int curr = i + 1;
		//printf("%d,%d\n",i,j);
		while (curr <= n && lyb[curr][j] == '.' && !vis[curr][j]) {
			q.push_front({ curr,j });
			vis[curr][j] = 1;
			rx[curr][j] = rx[i][j];
			ry[curr][j] = ry[i][j];
			++curr;
		}
		curr = i - 1;
		while (curr > 0 && lyb[curr][j] == '.' && !vis[curr][j]) {
			q.push_front({ curr, j });
			vis[curr][j] = 1;
			rx[curr][j] = rx[i][j];
			ry[curr][j] = ry[i][j];
			--curr;
		}
		if (j - 1 > 0 && lyb[i][j - 1] == '.' && !vis[i][j - 1] && rx[i][j] >= 1) {
			q.push_back({ i, j - 1 });
			vis[i][j - 1] = 1;
			rx[i][j - 1] = rx[i][j] - 1;
			ry[i][j - 1] = ry[i][j];
		}
		if (j + 1 <= m && lyb[i][j + 1] == '.' && !vis[i][j + 1] && ry[i][j] >= 1) {
			//printf("!%d,%d,%c\n",i,j+1,lyb[i][j+1]);
			q.push_back({ i,j + 1 });
			vis[i][j + 1] = 1;
			rx[i][j + 1] = rx[i][j];
			ry[i][j + 1] = ry[i][j] - 1;
		}
	}
	return res;
}
int main() {
	int i, j;
	int x, y;
	for (scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y), i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			scanf(" %c", &lyb[i][j]);
		}
	}
	rx[r][c] = x;
	ry[r][c] = y;
	printf("%d", bfs());
	//puts("");
	//for (i = 1; i <= n; ++i) {
	//	for (j = 1; j <= m; ++j) {
	//		//printf("%2d ",vis[i][j]);
	//		printf("%2d ", order[i][j]);
	//	}puts("");
	//}
	return 0;
}
