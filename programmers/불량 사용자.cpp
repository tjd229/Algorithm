//implementation
//https://programmers.co.kr/learn/courses/30/lessons/64064
#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;
int mat[16][16];//0~7, 8~15
int b[1<<8];
bool matching(string &a, string &b) {
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < a.size(); ++i) {
		if (b[i] == '*') continue;
		if (b[i] != a[i]) return 0;
	}
	return 1;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	int N = user_id.size();
	int M = banned_id.size();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			mat[i][j + 8] =mat[j+8][i]= matching(user_id[i], banned_id[j]);
		}
	}
	int pick[8] = { 0 };
	while (pick[M - 1] < N) {
		/*for (int i = 0; i < M; ++i)
			printf("%d ",pick[i]);
		puts("");*/

		bool matching[8] = { 0 };
		
		bool flag = 1;
		int now = 0;
		for (int i = 0; i < M && flag; ++i) {
			if (matching[pick[i]]) flag = 0;
			if (mat[pick[i]][i + 8]==0) flag = 0;
			matching[pick[i]] = 1;
			now |= (1 << pick[i]);
		}
		if (b[now] == 1) flag = 0;
		else if (flag) b[now] = 1;
		answer += flag;
		
		for (int i = 0; i < M; ++i) {
			++pick[i];
			if (pick[i] == N && i<M-1) {
				pick[i] = 0;
			}
			else break;
		}
		
	}
	return answer;
}