//https://programmers.co.kr/learn/courses/30/lessons/72415
//graph, implementation
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int x[2][7]; int y[2][7];
int inq[4][4];
int d[4][4];
vector<vector<int>> mp;
int R, C;
int stamp;
pii end(int x,int y,int dx,int dy) {
	int nx = x + dx, ny = y + dy;
	while (nx < 4 && nx >= 0 && ny < 4 && ny >= 0) {
		if (mp[ny][nx])
			return { nx,ny };
		nx += dx, ny += dy;
	}
	return { nx - dx,ny - dy };
}
int bfs(pii src, pii tgt) {
	queue<pii > q; q.push(src);
	inq[src.second][src.first] = ++stamp;
	d[src.second][src.first] = 0;
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		if (tgt.first == x && tgt.second == y) break;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 4 && nx >= 0 && ny < 4 && ny >= 0) {
				if (inq[ny][nx] != stamp) {
					inq[ny][nx] = stamp;
					d[ny][nx] = d[y][x] + 1;
					q.push({ nx,ny });
				}
			}
			auto coord = end(x, y, dx[i], dy[i]);
			nx = coord.first, ny = coord.second;
			if (inq[ny][nx] != stamp) {
				inq[ny][nx] = stamp;
				d[ny][nx] = d[y][x] + 1;
				q.push({ nx,ny });
				
			}
		}
	}
	return d[tgt.second][tgt.first];
}
int sim(vector<int> &perm, int dir[6]) {
	int cnt = 0;
	int cx = C, cy = R;
	for (auto num : perm) {
		if (x[0][num] < 0) continue;
		int s = 0, t = 1;
		if (dir[num - 1]) s = 1, t = 0;
		cnt += bfs({ cx,cy }, { x[s][num],y[s][num] });
		cnt += bfs({ x[s][num],y[s][num] }, { x[t][num],y[t][num] });
		cx = x[t][num], cy = y[t][num];
		cnt += 2;
		mp[y[s][num]][x[s][num]] = 0;
		mp[y[t][num]][x[t][num]] = 0;
	}
	return cnt;
}
int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	R = r, C = c;
	vector<int> perm(6);
	iota(perm.begin(), perm.end(), 1);
	for (int i = 1; i <= 6; ++i) x[0][i] = x[1][i] = y[0][i] = y[1][i] = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j]) {
				int num = board[i][j];
				int k = 0;
				if (x[k][num] >= 0) ++k;
				x[k][num] = j, y[k][num] = i;
			}
		}
	}
	do {
		int dir[6];
		for (int stat = 0; stat < 64; ++stat) {
			for (int k = 0; k < 6; ++k)
				dir[k] = stat & (1 << k);
			mp = board;
			int cnt = sim(perm, dir);
			if (answer == 0 || answer > cnt) answer = cnt;
		}
	} while (next_permutation(perm.begin(), perm.end()));

	return answer;
}

