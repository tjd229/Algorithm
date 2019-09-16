//implementation
//https://programmers.co.kr/learn/courses/30/lessons/17679
#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;
int del[30][30];
int N, M;
int listing(vector<string> &board, int stamp) {
	int res = 0;
	vector<pii > black_list;
	for (int i = 0; i < M - 1; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (board[i][j] == 0) continue;
			if (board[i][j] == board[i][j + 1]
				&& board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
				res += (del[i][j] != stamp);
				res += (del[i + 1][j] != stamp);
				res += (del[i][j + 1] != stamp);
				res += (del[i + 1][j + 1] != stamp);
				del[i][j] = del[i][j + 1] = del[i + 1][j] = del[i + 1][j + 1] = stamp;
				black_list.push_back({ i,j });
			}
		}
	}
	for (auto p : black_list) {
		int y = p.first; int x = p.second;
		board[y][x] = 0; board[y][x+1] = 0;
		board[y+1][x] = 0; board[y+1][x+1] = 0;
	}
	for (int j = 0; j < N; ++j) {
		int btm = M - 1;
		while (btm >= 0 && board[btm][j]) --btm;		
		for (int i = btm - 1; i >= 0; --i) {
			if (board[i][j]) {
				board[btm--][j] = board[i][j];
				board[i][j] = 0;
			}
			
		}
	}
	return res;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	N = n, M = m;
	int turn = -1;
	int stamp = 1;
	while (turn) {
		turn = listing(board, stamp++);
		answer += turn;
		
	}
	return answer;

}