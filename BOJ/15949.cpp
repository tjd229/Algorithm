//implementation, djs
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int dx[4] = {0,-1,0,1};
const int dy[4] = { 1,0,-1,0 };
int N, M;
int DP, CC;
int p[10000];
int x[10000][4][2], y[10000][4][2];
string codel[100];
inline int to1d(int x, int y) { return x + y * M; }
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (a > b) a ^= b ^= a ^= b;
	p[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j; cin >> N >> M;
	int ix = 0;
	for (i = 0; i < N; ++i) {
		cin >> codel[i];
		for (j = 0; j < M; ++j, ++ix) {
			p[ix] = ix;
			if (codel[i][j] != 'X') {
				if (j > 0 && codel[i][j - 1] == codel[i][j])
					dsu(to1d(j - 1, i), ix);
				if (i > 0 && codel[i - 1][j] == codel[i][j]) 
					dsu(to1d(j, i - 1), ix);
			}			
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			if (codel[i][j] != 'X') {
				ix = to1d(j, i);
				int par = find(ix);
				if (par == ix) {
					for (int k = 0; k < 4; ++k) {
						x[par][k][0] = x[par][k][1] = j;
						y[par][k][0] = y[par][k][1] = i;
					}
				}
				if (y[par][0][0] < i) {
					y[par][0][0] = y[par][0][1] = i;
					x[par][0][0] = x[par][0][1] = j;
				}
				else if (y[par][0][0] == i)
					x[par][0][1] = j;
				if (y[par][2][0] == i) x[par][2][1] = j;
				if (x[par][1][0] > j) {
					y[par][1][0] = y[par][1][1] = i;
					x[par][1][0] = x[par][1][1] = j;
				}
				else if (x[par][1][0] == j)
					y[par][1][1] = i;
				if (x[par][3][0] < j) {
					y[par][3][0] = y[par][3][1] = i;
					x[par][3][0] = x[par][3][1] = j;
				}
				else if (x[par][3][0] == j)
					y[par][3][1] = i;
			}
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			if (codel[i][j] != 'X') {
				int par = find(to1d(j, i));
				if (x[par][2][0] < x[par][2][1])
					swap(x[par][2][0], x[par][2][1]);
				if (y[par][3][0] < y[par][3][1])
					swap(y[par][3][0], y[par][3][1]);
			}
		}
	}
	int cx = 0, cy = 0;
	DP = 3; CC = 1;
	string res;

	while (1) {
		res += codel[cy][cx];
		int coin = 8;
		int par = find(to1d(cx, cy));
		while (coin>0) {
			int nx = x[par][DP][CC], ny = y[par][DP][CC];
			nx += dx[DP], ny += dy[DP];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && codel[ny][nx] != 'X') {
				cx = nx, cy = ny;
				break;
			}
			CC = 1 - CC;
			nx = x[par][DP][CC], ny = y[par][DP][CC];
			nx += dx[DP], ny += dy[DP];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && codel[ny][nx] != 'X') {
				cx = nx, cy = ny;
				break;
			}
			DP = (1 + DP) & 3;
			coin -= 2;
		}
		if (coin == 0) break;
	}
	cout << res;

	return 0;
}