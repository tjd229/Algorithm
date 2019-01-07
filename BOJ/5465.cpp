//bs

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
#define reg register
using namespace std;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
char mp[802][802];
int visH[802][802];
int visM[802][802];
int N, S;
int Mx, My;
bool bfs(int s,int stamp, vector<pii > bee) {
	vector<pii > baer;
	baer.push_back({Mx,My});
	reg int iH = 0;
	reg int iM = 0;
	int end;
	for (reg int t = 0;; ++t) {
		
		if (t >= s) {
			for (reg int stride = 0; stride < S; ++stride) {
				end = baer.size();
				for (; iM < end; ++iM) {
					int x = baer[iM].first;
					int y = baer[iM].second;
					if (visH[y][x] == stamp) continue;
					for (int i = 0; i < 4; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx<1 || ny<1 || nx>N || ny>N) continue;
						if ( visM[ny][nx]==stamp || visH[ny][nx]==stamp) continue;
						if (mp[ny][nx] == 'D') return true;
						if (mp[ny][nx] != 'G') continue;
						visM[ny][nx] = stamp;
						baer.push_back({nx,ny});
					}
				}
			}
			if (iM == baer.size()) return false;
		}
		end = bee.size();
		for (; iH < end; ++iH) {
			int x = bee[iH].first;
			int y = bee[iH].second;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>N || ny>N) continue;
				if (visH[ny][nx] == stamp) continue;
				if (mp[ny][nx] == 'G' || mp[ny][nx] == 'M') {
					visH[ny][nx] = stamp;
					bee.push_back({ nx,ny });
				}
			}
		}
	}
	return false;
}
int main() {
	int i, j;
	vector<pii > bee;
	for (scanf("%d%d", &N, &S), i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			scanf(" %c",mp[i]+j);
			if (mp[i][j] == 'M') Mx = j, My = i;
			else if (mp[i][j] == 'H') bee.push_back({j,i});
		}
	}
	int l = 0;
	int r = N * N;
	int stamp = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		//printf("%d,%d:%d\n", l, r, m);
		if (bfs(m, ++stamp, bee)) l = m + 1;
		else r = m - 1;
	}
	printf("%d",l-1);
	return 0;
}
