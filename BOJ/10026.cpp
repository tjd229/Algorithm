//category : graph

#include <iostream>
#include <string>
using namespace std;
string grid[100];
char rgb[3] = { 'R', 'G', 'B' };
int N;
int visit[100][100];
int c2i(char c){
	if (c == 'R') return 0;
	if (c == 'G') return 1;
	return 2;
}
bool dfs(int x, int y, int ix){
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	if (rgb[ix] != grid[y][x]) return false;
	if (visit[y][x] != 0) return false;
	visit[y][x] = 1;
	dfs(x + 1, y, ix);
	dfs(x - 1, y, ix);
	dfs(x, y + 1, ix);
	dfs(x, y - 1, ix);
	return true;
}
bool dfs2(int x, int y, int ix){
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	if (rgb[ix] != grid[y][x]) return false;
	if (visit[y][x] != 1) return false;
	visit[y][x] = 2;
	dfs2(x + 1, y, ix);
	dfs2(x - 1, y, ix);
	dfs2(x, y + 1, ix);
	dfs2(x, y - 1, ix);
	if (ix != 2){
		dfs2(x + 1, y, ix^1);
		dfs2(x - 1, y, ix^1);
		dfs2(x, y + 1, ix^1);
		dfs2(x, y - 1, ix^1);
	}
	return true;
}
int main(){

	cin >> N;
	int i,j;
	int ans = 0;
	for (i = 0; i < N; i++) cin >> grid[i];
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (dfs(j, i, c2i(grid[i][j]))) ans++;
		}
	}
	cout << ans << " ";
	ans = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (dfs2(j, i, c2i(grid[i][j]))) ans++;
		}
	}
	cout << ans;
	return 0;
}

