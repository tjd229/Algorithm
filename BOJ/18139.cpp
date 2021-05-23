//implementation, graph
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <tuple>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int dx[4] = {1,0,-1,0};
const int dy[4] = { 0,1,0,-1 };
int dir[11];
struct Stat {
	int mat[6][6];
	int lev;
}init;
set<pll> vis;
pll st2hash(int mat[6][6]){
	ll h1 = 0, h2 = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			h1 = h1 * 11 + mat[i][j];
			h2 = h2 * 11 + mat[i][j];
			h1 %= mod1; h2 %= mod2;
		}
	}
	return { h1,h2 };
}
Stat mv(Stat src,int px,int py,int dx,int dy) {
	vector<pair<int, int> > v= { {px,py} };
	int car = src.mat[py][px];
	int x = px + dx, y = py + dy;
	while (x < 6 && x >= 0 && y < 6 && y >= 0) {
		if (src.mat[y][x] == car) v.push_back({x,y});
		x += dx; y += dy;
	}
	x = px - dx; y = py - dy;
	while (x < 6 && x >= 0 && y < 6 && y >= 0) {
		if (src.mat[y][x] == car) v.push_back({ x,y });
		x -= dx; y -= dy;
	}
	for (auto p : v) {
		tie(x, y) = p;
		src.mat[y][x] = 0;
	}
	for (auto p : v) {
		tie(x, y) = p;
		x += dx; y += dy;
		if (x > 5 || x < 0 || y>5 || y < 0) {
			src.lev = -1;
			return src;
		}
		if (src.mat[y][x] != 0) {
			src.lev = -1;
			return src;
		}
	}
	for (auto p : v) {
		tie(x, y) = p;
		x += dx; y += dy;
		src.mat[y][x] = car;
	}
	src.lev++;
	return src;
}
int bfs() {
	int cnt = 0;
	for (int j = 0; j < 6; ++j) {
		if (init.mat[2][j] == 1) ++cnt;
	}
	if (cnt != 2) return -1;
	queue < Stat > q; q.push(init);
	vis.insert(st2hash(init.mat));
	while (q.size()) {
		Stat st = q.front(); q.pop();
		if (st.mat[2][4] == 1 && st.mat[2][5] == 1)
			return st.lev + 2;
		if (st.lev < 8) {
			int px[11], py[11];
			for (int i = 0; i < 6; ++i) {
				for (int j = 0; j < 6; ++j) {
					int car = st.mat[i][j];
					px[car] = j, py[car] = i;
				}
			}
			for (int i = 1; i <= 10; ++i) {
				if (dir[i] >= 0) {
					Stat nxt = mv(st, px[i], py[i], dx[dir[i]], dy[dir[i]]);
					if (nxt.lev >= 0) {
						auto h = st2hash(nxt.mat);
						if (vis.find(h) == vis.end()) {
							vis.insert(h);
							q.push(nxt);
						}
					}
					nxt = mv(st, px[i], py[i], dx[2+dir[i]], dy[2+dir[i]]);
					if (nxt.lev >= 0) {
						auto h = st2hash(nxt.mat);
						if (vis.find(h) == vis.end()) {
							vis.insert(h);
							q.push(nxt);
						}
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	int i, j;
	for (i = 1; i <= 10; ++i) dir[i] = -1;
	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 6; ++j) {
			scanf("%d", init.mat[i] + j);
		}
	}
	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 6; ++j) {
			int car = init.mat[i][j];
			if (car > 0 & dir[car] < 0) {
				if (j < 5 && init.mat[i][j + 1] == car) dir[car] = 0;
				else dir[car] = 1;
			}
		}
	}
	printf("%d",bfs());
	return 0;
}