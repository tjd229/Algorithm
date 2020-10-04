//implementation
//https://programmers.co.kr/learn/courses/30/lessons/68645?language=cpp
#include <string>
#include <vector>

using namespace std;
const int dx[3] = { 0,1,-1 };
const int dy[3] = {1,0,-1};
vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int> > snail;
	for (int i = 1; i <= n; ++i) {
		vector<int> v(i);
		snail.push_back(v);
	}
	int end = (n * (n + 1)) >> 1;
	int x = 0, y = 0;
	int dir = 0;
	for (int i = 1; i <= end; ++i) {
		snail[y][x] = i;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (ny >= n || nx >= snail[ny].size() || snail[ny][nx] != 0) {
			dir = (dir + 1) % 3;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx, y = ny;
	}
	for (int i = 0; i < n; ++i) {
		for (auto x : snail[i]) answer.push_back(x);
	}
	return answer;
}