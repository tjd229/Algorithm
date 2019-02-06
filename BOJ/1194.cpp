//graph
#include <string>
#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
struct Quad { int a,b,c,d; };//x,y,stat,t
int vis[50][50][1 << 7];
string maze[50];
int N, M;
int bfs(int sx,int sy) {
	queue<Quad> q;
	q.push({sx,sy,0,0});
	vis[sy][sx][0] = 1;
	while (q.size()) {
		int x = q.front().a;
		int y = q.front().b;
		int stat = q.front().c;
		int t = q.front().d;
		q.pop();
		if (maze[y][x] == '1') return t;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			char nxt = maze[ny][nx];
			int nstat = stat;
			if (nxt == '#') continue;
			else if (nxt >= 'A' && nxt <= 'F'
				&& 0 == (stat&(1 << (nxt - 'A')))) continue;
			else if (nxt >= 'a' && nxt <= 'f')
				nstat |= 1 << (nxt - 'a');
			if (vis[ny][nx][nstat]) continue;
			vis[ny][nx][nstat] = 1;
			q.push({nx,ny,nstat,t+1});
		}
	}
	return -1;
}
int main() {
	int i, j;
	int sx, sy;
	cin >> N >> M;
	for (i = 0; i < N; ++i) {
		cin >> maze[i];
		for (j = 0; j < M; ++j) {
			if (maze[i][j] == '0') {
				sx = j;
				sy = i;
			}
		}
	}
	cout << bfs(sx,sy);
	return 0;
}