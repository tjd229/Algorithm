//https://programmers.co.kr/learn/courses/30/lessons/60061
//implementation

#include <string>
#include <vector>
#define BEAM 1
#define COL 0
using namespace std;
int beam[111][111];
int col[111][111];
bool verify(int x,int y,int a) {
	if (a) {
		//y>0
		if (col[y - 1][x] || col[y - 1][x + 1]) return 1;
		else if (x && beam[y][x - 1] && beam[y][x + 1]) return 1;
	}
	else {
		if (!y) return 1;
		if (col[y - 1][x]) return 1;
		else if (beam[y][x]) return 1;
		else if (x && beam[y][x - 1]) return 1;
	}
	return 0;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (int i = 0; i < build_frame.size(); ++i) {
		int x, y, a, b;
		x = build_frame[i][0]; y = build_frame[i][1];
		a = build_frame[i][2]; b = build_frame[i][3];
		if (a) {//beam
			if (b) {//y>0
				beam[y][x] = verify(x, y, a);
			}
			else {
				beam[y][x] = 0;
				if (col[y][x] && !verify(x,y, COL)) beam[y][x] = 1;
				if (col[y][x + 1] && !verify(x + 1, y,COL)) beam[y][x] = 1;
				if (x &&beam[y][x-1] && !verify(x - 1,y, BEAM)) beam[y][x] = 1;
				if (beam[y][x + 1] && !verify( x + 1,y, BEAM)) beam[y][x] = 1;
			}
		}
		else {//col
			if (b) {
				col[y][x] = verify(x, y, a);
			}
			else {
				col[y][x] = 0;
				if (col[y + 1][x] && !verify(x, y + 1, COL)) col[y][x] = 1;
				if (beam[y + 1][x] && !verify(x, y + 1, BEAM)) col[y][x] = 1;
				if (x && beam[y + 1][x - 1] && !verify(x - 1, y + 1, BEAM)) col[y][x] = 1;
			}
		}
	}
	for (int j = 0; j <= n; ++j) {
		for (int i = 0; i <= n; ++i) {
			if (col[i][j]) answer.push_back({ j,i,COL });
			if (beam[i][j]) answer.push_back({ j,i,BEAM });
		}
	}
	return answer;
}