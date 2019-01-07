//graph

#include <stdio.h>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n, m;
char mp[101][101];
int from[101][101];
const char dir[4] = {'U','D','L','R'};
const int dx[4] = {0,0,-1,1};
const int dy[4] = { -1,1,0,0 };
void bfs() {
	queue<pii > q;
	q.push({1,1});
	from[1][1] = -2;
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>m || ny>n) continue;
			if (mp[ny][nx] == '*') continue;
			if (from[ny][nx] != -1) continue;
			from[ny][nx] = i;
			q.push({nx,ny});
			if (mp[ny][nx] == 'F') return;
		}
	}
}
int main() {
	int i, j;
	int x, y;
	int swapkey[2] = { -1,-1 };
	vector<int> cmd;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			scanf(" %c", mp[i] + j);
			from[i][j] = -1;
			if (mp[i][j] == 'F') x = j, y = i;
		}
	}
	bfs();
	while (x + y != 2) {
		int cix = from[y][x];
		cmd.push_back(cix);
		x -= dx[cix];
		y -= dy[cix];

	}
	while (cmd.size()) {
		int key = cmd.back();
		if (swapkey[key >> 1] < 0) {
			int _x = x;
			int _y = y;
			printf("%c\n", dir[key]); fflush(stdout);
			scanf("%d%d",&y,&x);
			
			swapkey[key >> 1] = (x == _x) && (y == _y);
			if (swapkey[key >> 1] == 0) cmd.pop_back();
			
		}
		else {
			printf("%c\n", dir[key^swapkey[key>>1]]); fflush(stdout);
			scanf("%d%d", &y, &x);
			cmd.pop_back();
		}
	}
	return 0;
}
