//implementation
//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> stk;
	stack<int> board_stk[30];
	int N = board.size();
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j]) board_stk[j].push(board[i][j]);
		}
	}

	for (auto x : moves) {
		--x;
		if (board_stk[x].size()) {
			int pick = board_stk[x].top();
			board_stk[x].pop();
			if (stk.size() && stk.top() == pick)
				stk.pop(), answer+=2;
			else stk.push(pick);
		}
	}


	return answer;
}