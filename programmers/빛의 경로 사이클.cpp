//https://programmers.co.kr/learn/courses/30/lessons/86052
//graph
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> mp;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };
int mat[500][500][4][2];//...[0] int, [1] out
int n, m;
int sim(int x,int y,int d) {
	int t = 0;
	while (mat[y][x][d][1] == 0) {
		++t;
		mat[y][x][d][1] = 1;
		y += dy[d]; x += dx[d];
		if (y < 0) y += n;
		if (x < 0) x += m;
		if (y == n) y = 0;
		if (x == m) x = 0;
		if (mp[y][x] == 'L') d = (d-1+4) % 4;
		else if(mp[y][x]=='R') d = (1 + d) % 4;
	}

	return t;
}
vector<int> solution(vector<string> grid) {
	vector<int> answer; mp = grid;
	n = grid.size(); m = grid[0].size();
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			for (int d = 0; d < 4; ++d) {
				if (mat[i][j][d][1] == 0) {
					answer.push_back(sim(j, i, d));
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}