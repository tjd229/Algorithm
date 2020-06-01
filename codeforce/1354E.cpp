//graph, dp
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<int> edge[5001];
int nc[5001][2];
int clr[5001];
bool d[5001][5001];
pii dfs(int x,int from,int c) {
	clr[x] = c;
	pii cnt = { 0,0 };
	if (c == 1) ++cnt.first;
	else ++cnt.second;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (clr[nxt]==c) return { -10000,-10000 };
		else if (clr[nxt]) continue;
		pii nxtp = dfs(nxt, x,3-c);
		
		cnt.first += nxtp.first;
		cnt.second += nxtp.second;
	}
	return cnt;
}
int main() {
	int i, n, m, n1, n2, n3;
	for (scanf("%d%d%d%d%d", &n, &m, &n1, &n2, &n3), i = 0; i < m; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int num = 0;
	bool flag = 1;
	vector<int> head;
	for (i = 1; i <= n &&flag; ++i) {
		if (clr[i] == 0) {
			pii cnt = dfs(i, 0, 1);
			nc[num][0] = cnt.first;
			nc[num][1] = cnt.second;
			if (cnt.first < 0 || cnt.second < 0)
				flag = 0;
			++num;
			head.push_back(i);
		}
	}
	if (flag == 0) {
		printf("NO\n");
		return 0;
	}
	for (i = 0,d[0][0]=1; i < num; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i + 1][j + nc[i][0]] |= d[i][j];
			d[i + 1][j + nc[i][1]] |= d[i][j];
		}
	}
	if (!d[num][n2]) {
		printf("NO\n");
		return 0;
	}
	
	for (i = num - 1; i >= 0; --i) {
		if (n2 - nc[i][0] >= 0 && d[i][n2 - nc[i][0]]) {
			n2 -= nc[i][0];
			head[i] = -head[i];
		}
		else
			n2 -= nc[i][1];		
	}
	for (i = 1; i <= n; ++i) clr[i] = 0;
	for (auto x : head) {
		if (x < 0) dfs(-x, 0, 2);
		else dfs(x, 0, 1);
	}
	for (printf("YES\n"), i = 1; i <= n; ++i) {
		if (clr[i] == 1) {
			if (n1 == 0) clr[i] = 3;
			else --n1;
		}
		printf("%d",clr[i]);
	}
	return 0;
}