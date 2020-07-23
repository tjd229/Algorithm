//graph, tp sort
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> d[200001],ud[200001];
int tp[200001],ind[200001];
bool tree[200001],inq[200001],stk[100001];
int t[200001], x[200001], y[200001];
int n, m;
int to(int self, int eix) {
	return x[eix] == self ? y[eix] : x[eix];
}
bool dfs(int x) {
	
	if (stk[x]) return 0; //cyc
	if (tree[x]) return 1;
	stk[x] = 1;
	tree[x] = 1;
	for (auto nxt : d[x]) {
		if (!dfs(nxt)) return 0;
	}
	stk[x] = 0;
	return 1;
}
void bfs(queue<int> &q) {
	while (q.size()) {
		int cur = q.front(); q.pop();
		tree[cur] = 1;//forest case
		for (auto ix : ud[cur]) {
			int nxt = to(cur, ix);
			if (tree[nxt]) continue;
			//tree[nxt] = 1;
			if (nxt != x[ix]) x[ix] ^= y[ix] ^= x[ix] ^= y[ix]; //nxt->cur
			if (!inq[nxt]) {
				//printf("%d->%d\n",cur,nxt);
				q.push(nxt);
				inq[nxt] = 1;
			}
		}
	}
}
void tp_sort(int cnt = 0) {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (tree[i] && ind[i] == 0) q.push(i);
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		tp[x] = ++cnt;
		for (auto nxt : d[x]) {
			if (--ind[nxt] == 0) {
				q.push(nxt);
				//tp[nxt] = tp[x] + 1;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		int u = x[i], v = y[i];
		if (t[i]==0 && tree[u] && tree[v] && tp[u] > tp[v])
			x[i] ^= y[i] ^= x[i] ^= y[i];
	}
}
int main() {
	int i, tc;
	for (scanf("%d", &tc); tc--;) {
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			stk[i] = 0, tree[i] = 0;
			inq[i] = 0;
			tp[i] = 0; ind[i] = 0;
			d[i].clear(); ud[i].clear();
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d", t + i, x + i, y + i);
			if (t[i]) d[x[i]].push_back(y[i]),++ind[y[i]];
			else {
				ud[x[i]].push_back(i);
				ud[y[i]].push_back(i);
			}
		}
		bool flag = 1;
		queue<int> q;
		for (i = 1; i <= n && flag; ++i) {
			//printf("%d,%d\n",i,d[i].size());
			if (d[i].size()) 
				flag &= dfs(i);
		}
		if (!flag) {
			printf("NO\n");
			continue;
		}
		for (i = 1; i <= n; ++i) {
			if (tree[i]) {
				q.push(i);
				inq[i]=1;
			}
		}
		tp_sort();
		bfs(q);
		for (i = 1; i <= n; ++i) {//forest case
			if (!tree[i]) {
				for (auto ix : ud[i]) 
					if(x[ix]>y[ix])  x[ix] ^= y[ix] ^= x[ix] ^= y[ix];
			}
		}
		for (printf("YES\n"),i = 1; i <= m; ++i)
			printf("%d %d\n",x[i],y[i]);
		
 
	}
	return 0;
}
