//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int mat[1001][1001];
int loop[1001];
vector<int> ans;
int N;
void dfs(int ix) {
	int &i = loop[ix];
	for (; i <= N;) {
		if (mat[ix][i] == 0) {
			++i;
			continue;
		}
		--mat[ix][i]; --mat[i][ix];
		dfs(i);
		//return;
	}
	ans.push_back(ix);
}
int main() {
	int i, j;
	int tot = 0;
	bool flag = false;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		int cnt = 0;
		for (j = 1; j <= N; ++j) {
			scanf("%d", mat[i] + j);
			cnt += mat[i][j];
		}
		flag |= (cnt & 1);
		tot += cnt;
	}
	tot >>= 1;
	dfs(1);

	if (flag||ans.size() != tot+1) 
		printf("-1");
	else 
		for (auto v : ans) printf("%d ", v);
	

	return 0;
}
