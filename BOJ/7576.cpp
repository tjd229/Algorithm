//category : graph

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int tomato[1000][1000];
int N, M;
int main() {
	int i, j;
	int all = 0;
	int day = 0;
	vector<pii > q;
	for (scanf("%d%d", &M, &N), i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			scanf("%d", tomato[i]+j);
			if (tomato[i][j] == 1) 
				q.push_back({i*M+j,0});
			all += tomato[i][j] != -1;
		}
	}
	for (int k = 0; k < q.size();++k) {
		pii p = q[k];
		i = p.first / M;
		j = p.first%M;
		day = p.second;
		if (i > 0 && tomato[i - 1][j] == 0) {
			q.push_back({ p.first - M,1 + day });
			tomato[i - 1][j] = 1;
		}
		if (j > 0 && tomato[i][j - 1] == 0) {
			q.push_back({ p.first - 1,1 + day });
			tomato[i][j - 1] = 1;
		}
		if (i <N-1 && tomato[i + 1][j] == 0) {
			q.push_back({ p.first + M,1 + day });
			tomato[i + 1][j] = 1;
		}
		if (j <M-1 && tomato[i][j + 1] == 0) {
			q.push_back({ p.first + 1,1 + day });
			tomato[i][j + 1] = 1;
		}
	}
	printf("%d",all==q.size()? day:-1);
	return 0;
}
