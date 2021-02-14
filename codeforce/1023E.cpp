//graph
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int dx[2] = { 0,1 };
const int dy[2] = { 1,0 };
const char mv[2] = { 'D','R' };
string S;
int n;
int grid[501][501];
int qry(int r1, int c1, int r2, int c2) {
	cout << "? " << r1 <<" "<< c1 << " " << r2 << " " << c2 << endl;
	string resp; cin >> resp;
	if (resp == "BAD")
		exit(-2);
	return resp[0] == 'Y';
}
inline int md(int r1, int c1, int r2, int c2) {
	int dy = r1 - r2;
	int dx = c1 - c2;
	if (dy < 0) dy = -dy;
	if (dx < 0) dx = -dx;
	return dx + dy;
}
int chk(int r, int c) {
	if (r > n || c > n || r<1 || c<1) return -1;
	if (grid[r][c]) return grid[r][c];
	int resp;
	if (md(1, 1, r, c) >= n - 1)
		resp = qry(1, 1, r, c);
	else
		resp = qry(r, c, n, n);
	if (resp==1) grid[r][c] = 1;
	else 
		grid[r][c] = -1;
	
	return grid[r][c];
}
int dfs(int x, int y) {
	if (grid[y][x] != 1) return 0;
	if (x == n && y == n)return 1;
	for (int i = 0; i < 2; ++i) {
		int nx = dx[i] + x, ny = y + dy[i];
		if (dfs(nx, ny)) {
			S.push_back(mv[i]);
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	grid[1][1] = grid[n][n] = 1;
	int x = 1, y = 1;
	while (md(y,x,n,n)>=n-1) {
		for (int i = 0; i < 2; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (chk(ny, nx) == 1) {
				x = nx, y = ny;
				break;
			}
			if (i == 1) 
				y = x = n;//break			
		}
	}
	y = x = n;
	while (md(1,1,y,x) >= n - 1) {
		for (int i = 1; i >=0; --i) {
			int nx = x - dx[i], ny = y - dy[i];
			if (chk(ny, nx) == 1) {
				x = nx, y = ny;
				break;
			}
			if (i == 0)
				y = x = 1;//break			
		}
	}
	dfs(1, 1); reverse(S.begin(), S.end());
	cout <<"! "<< S << endl;

	return 0;
}