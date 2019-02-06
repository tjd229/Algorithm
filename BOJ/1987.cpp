//graph
#include <iostream>
#include <string>
using namespace std;
const int dx[4] = {-1,1,0,0};
const int dy[4] = { 0,0,-1,1 };
string board[20];
int R, C;
int ans=0;

void dfs(int x,int y,int stat,int d) {
	if (ans < d) ans = d;
	stat |= (1 << (board[y][x] - 'A'));
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if ((stat & (1 << (board[ny][nx] - 'A'))) == 0) dfs(nx, ny, stat,d+1);
	}
}
int main() {
	cin >> C >> R;
	for (int i = 0; i < C; ++i) cin >> board[i];
	dfs(0, 0, 0,1);
	cout << ans;
	return 0;
}