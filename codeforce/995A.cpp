//implementation

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int dx[3] = {1,-1,0};
const int dy[3] = { 0,0,1 };
int n, k, r;
int mp[6][52];
int vis[6][52];
pii from[6][52];
pii dst[101],pos[101];//x,y
struct Log {
	int i, r, c;
};
vector<Log> ans;
void bfs(queue<pii> &q,int dst, int stamp) {
	int x, y;
	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		if (mp[y][x] == dst) break;
		q.pop();
		for (int i = 0; i < 3; ++i) {
			int nx = x + dx[i];
			int ny = y ^ dy[i];
			if (nx > n || nx < 1) continue;
			if (mp[ny][nx] == dst) {
				while (q.size()) q.pop();
				q.push({ nx,ny });
				from[ny][nx] = { x,y };
				break;
			}
			if (mp[ny][nx] == 0 && vis[ny][nx] != stamp)
			{
				vis[ny][nx] = stamp;
				q.push({ nx,ny });
				from[ny][nx] = { x,y };
			}
		}		
	}
	if (mp[y][x] == dst) {	
		int car = mp[y][x];
		while (y==2 || y==3) {
			mp[y][x] = 0;
			pii *nxt = &from[y][x];
			ans.push_back({car,nxt->second,nxt->first});
			x = nxt->first;
			y = nxt->second;
		}
		mp[y][x] = 0;
		--r;
	}
}
int main() {
	int i,j;
	int stamp = 0;
	for (scanf("%d%d", &n, &k), i = 1; i <= 4; ++i) {
		for (j = 1; j <= n; ++j) scanf("%d",mp[i]+j);
	}
	for (i = 1; i <= n; ++i) {
		if (mp[1][i]) dst[mp[1][i]] = { i,1 };
		if (mp[4][i]) dst[mp[4][i]] = { i,4 };
		if (mp[2][i]) pos[mp[2][i]] = { i,2 };
		if (mp[3][i]) pos[mp[3][i]] = { i,3 };
	}r = k;
	while (r) {
		int _r = r;
		for (i = 1; i <= k; ++i) {			
			queue<pii > q;
			int x = dst[i].first;
			int y = dst[i].second;
			if (x + y == 0) continue;
			from[y][x] = { -1,-1 };
			y = y == 1 ? ++y : --y;
			if (mp[y][x] == 0 || mp[y][x] == i) {
				q.push({ x,y });
				from[y][x] = { x,dst[i].second };
				vis[y][x] = ++stamp;
				bfs(q, i, stamp);
			}
		}
		if (_r == r) break;
	}
	if (r == n+n) {
		printf("-1");
		return 0;
	}
	while (r && r!=n+n) {
		if (mp[3][1] == 0 && mp[2][1]) {
			ans.push_back({ mp[2][1],3,1 });
			mp[3][1] = mp[2][1];
			mp[2][1] = 0;
		}
		for (i = 1; i < n; ++i) {
			if (mp[2][i] == 0 && mp[2][i+1]) {
				ans.push_back({mp[2][i+1],2,i});
				mp[2][i] = mp[2][i + 1];
				mp[2][i + 1] = 0;
			}
		}
		if (mp[2][i] == 0 && mp[3][i]) {
			ans.push_back({ mp[3][i],2,i });
			mp[2][i] = mp[3][i];
			mp[3][i] = 0;
		}
		for (; i; --i) {
			if (mp[3][i] == 0 && mp[3][i - 1]) {
				ans.push_back({ mp[3][i - 1],3,i });
				mp[3][i] = mp[3][i - 1];
				mp[3][i - 1] = 0;
			}
		}
		for (i = 1; i <= k; ++i) {
			queue<pii > q;
			int x = dst[i].first;
			int y = dst[i].second;
			if (x + y == 0) continue;
			from[y][x] = { -1,-1 };
			y = y == 1 ? ++y : --y;
			if (mp[y][x] == 0 || mp[y][x] == i) {
				q.push({ x,y });
				from[y][x] = { x,dst[i].second };
				vis[y][x] = ++stamp;
				bfs(q, i, stamp);
			}
		}
	}
	printf("%d\n",ans.size());
	for (auto lg : ans) {
		printf("%d %d %d\n",lg.i,lg.r,lg.c);
	}
	return 0;
}
