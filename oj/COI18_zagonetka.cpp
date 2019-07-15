//graph, floyd, tp_sort
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int s[101], l[101];
int p[101];
int mat[101][101];
int pos[101];
int n;
int tp_sort(queue<int> &q, int s, int *vt, int *ind, vector<int> edge[101]) {
	int vis = 0;
	while (q.size()) {
		int u = q.front(); q.pop();		
		vt[u] = s++;
		++vis;
		for (auto v : edge[u]) {
			if (--ind[v] == 0)
				q.push(v);
		}
	}
	return vis;
}

int dfs(int x, int dst, vector<int> edge[101]) {
	if (dst == x) return 1;
	for (auto nxt : edge[x]) {
		if (dfs(nxt, dst, edge)) return 1;
	}
	return 0;
}
void perm(int x, int &num, int *vt) {
	if (vt[x]) return;
	for (int i = 1; i <= n; ++i) {
		if (mat[x][i]) perm(i, num, vt);
	}
	vt[x] = num++;
}
void qry(int x, int y) {//chk pos[x]->pos[y]
	//inv edge ok -> no condition
	//inv edge no -> there is condition 
	//cycle -> there is cond.(inclusive indirect)

	vector<int> edge[101];
	vector<int> loc;
	int ind[101] = { 0 };
	int myp[101] = { 0 };
	for (int i = 1; i <= n; ++i) myp[i] = p[i];
	for (int i = x; i <= y; ++i) loc.push_back(pos[i]);
	for (int i = 0; i < loc.size(); ++i) {
		for (int j = 0; j < loc.size(); ++j) {
			if (mat[loc[i]][loc[j]]) {
				edge[loc[i]].push_back(loc[j]);
				++ind[loc[j]];
			}
		}
	}
	//dfs chk
	if (dfs(pos[x], pos[y], edge)) 
		return;
	

	edge[pos[y]].push_back(pos[x]);//inv edge
	++ind[pos[x]];
	queue<int> q;
	for (auto v : loc) {
		if (ind[v] == 0) q.push(v);
	}
	if (y - x + 1 == tp_sort(q, x, myp, ind, edge)) {
		int i;
		i = 1;
		for (printf("query"), i = 1; i <= n; ++i) printf(" %d", myp[i]);
		printf("\n"); fflush(stdout);
		scanf("%d", &i);
		if (i) return;
	}

	//cycle chk
	mat[pos[x]][pos[y]] = 1;
}
int main() {
	int i;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		pos[p[i]] = i;
	}
	for (int range = 1; range < n; ++range) {
		for (i = 1; i + range <= n; ++i) qry(i, i + range);
	}

	for (i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k)
				mat[j][k] |= mat[j][i] & mat[i][k];
		}
	}
	int src = 1;
	for (i = 1; i <= n; ++i) perm(i, src, l);
	for (i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			mat[i][j] ^= mat[j][i] ^= mat[i][j] ^= mat[j][i];
		}
	}
	src = 1;
	for (i = 1; i <= n; ++i) perm(i, src, s);
	for (i = 1; i <= n; ++i) l[i] = n - l[i] + 1;

	for (printf("end\n"), i = 1; i <= n; ++i) printf("%d ", s[i]);
	for (printf("\n"), i = 1; i <= n; ++i) printf("%d ", l[i]);
	fflush(stdout);

	return 0;
}