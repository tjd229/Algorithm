//implementation

#include <stdio.h>
#include <set>
#define pii pair<int,int>
using namespace std;
const int dx[4] = {0,-1,1,0};
const int dy[4] = { -1,0,0,1 };
int N;
int mp[21][21];
int vis[21][21];
int lev[21][21];
int cx, cy;
int sz = 2;
int ex = 0;
int search(int stamp) {
	set<pii > q[2];
	int t = 0;
	q[0].insert({cy,cx});
	vis[cy][cx] = stamp;
	lev[cy][cx] = 0;
	mp[cy][cx] = 0;
	while (q[t].size()) {
		for (auto coord : q[t]) {
			int x = coord.second;
			int y = coord.first;
			if (mp[y][x] && mp[y][x] < sz) {
				mp[y][x] = 9;
				cy = y;
				cx = x;
				return lev[y][x];
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx == 0 || ny == 0 || nx > N || ny > N) continue;
				if (mp[ny][nx] <= sz && vis[ny][nx] != stamp) {
					q[1 - t].insert({ny,nx});
					lev[ny][nx] = 1 + lev[y][x];
					vis[ny][nx] = stamp;
				}
			}
		}
		q[t].clear();
		t = 1 - t;
	}
	return 0;
}
int main() {
	int i, j;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			scanf("%d",mp[i]+j);
			if (mp[i][j] == 9) cx = j, cy = i;
		}
	}
	int ans = 0;
	int stamp = 0;
	while (1) {
		int res = search(++stamp);
		if (res == 0) break;
		ans+=res;
		if ((++ex) == sz) ++sz, ex = 0;
	}
	printf("%d",ans);
	return 0;
}
