//https://www.welcomekakao.com/learn/courses/30/lessons/42894
//implementation
#include <string>
#include <vector>

using namespace std;
int top[55];
int N;
bool v(int x, int y, vector<vector<int>>& map) {
	int piv = map[y][x];
    if(piv==0) return false;
	int stat = 0;
	if (x > 0 && map[y][x - 1] == piv) stat += 1;
	if (x < N - 1 && map[y][x + 1] == piv) stat += 2;
	if (stat == 1) {
		bool res = map[y - 1][x - 1] == piv && map[y - 2][x - 1] == piv;
		if (res) {
			map[y - 1][x - 1] = map[y - 2][x - 1] = 0;
			map[y][x - 1] = map[y][x] = 0;
		}
		return res;
	}
	else if (stat == 2) {
		bool res = map[y - 1][x + 1] == piv && map[y - 2][x + 1] == piv;
		if (res) {
			map[y - 1][x + 1] = map[y - 2][x + 1] = 0;
			map[y][x + 1] = map[y][x] = 0;
		}
		return res;
	}
	return false;
}
bool h(int x, int y, vector<vector<int>>& map) {
	int ex = x + 2;
	int ey = y + 1;
	int piv = map[y + 1][x];
	int same = 0;
	for (int i = y; i <= ey; ++i) {
		for (int j = x; j <= ex; ++j) {
			if (map[i][j] == 0) continue;
			else if (map[i][j] != piv) return false;
			++same;
		}
	}
	if (same == 4) {
		for (int i = y; i <= ey; ++i) {
			for (int j = x; j <= ex; ++j) {
				map[i][j] = 0;
			}
		}
		return true;
	}
	return false;
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	int i, j;

	N = board.size();
	top[N] = top[N + 1] = -1;
	bool upd = 1;
	while (upd) {
		upd = 0;
		for (j = 0; j < N; ++j) {
			top[j] = -1;
			for (i = 0; i < N&&board[i][j] == 0; ++i) ++top[j];
		}
		for (j = 0; j < N; ++j) {
			if (top[j] > 0 && top[j] < N - 1) {
				bool res = v(j, top[j] + 1, board);
				answer += res;
				upd |= res;
			}
			else if (top[j] < 0 || top[j] == N - 1) continue;
			if (top[j] == top[j + 1]) {
				bool res = h(j, top[j], board);
				answer += res;
				upd |= res;
				if (j > 0) {
					res = h(j - 1, top[j], board);
					answer += res;
					upd |= res;
				}
			}
			if (top[j] == top[j + 2]) {
				bool res = h(j, top[j], board);
				answer += res;
				upd |= res;
			}
		}
	}
	return answer;
}