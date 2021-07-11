//graph
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
vector<int> edge[400001];
int path[400001],depth[400001];
int st[400001], ed[400001];
int cnt;
bool in(int s1, int e1, int s2, int e2) {
	if (s1 <= s2 && e2 <= e1) return 1;
	if (s2 <= s1 && e1 <= e2) return 1;
	return 0;
}
void dfs(int x) {
	st[x] = ++cnt;
	//printf("d:%d,%d\n",x,depth[x]);
	for (auto nxt : edge[x]) {
		if (st[nxt] == 0) {
			depth[nxt] = depth[x] + 1;
			dfs(nxt);
		}
	}
	ed[x] = cnt;
}
void mk_path(int x) {
	path[x] = 1;
	for (auto nxt : edge[x]) {
		if (path[nxt] == 0) {
			mk_path(nxt);
		}
		else if(path[nxt]!=-1){
			//printf("%d,%d,%d,%d\n", st[x], ed[x], st[nxt], ed[nxt]);
			if (in(st[x], ed[x], st[nxt], ed[nxt])) {
				//printf("%d,%d\n", depth[x], depth[nxt]);
				if (depth[x] == depth[nxt]) path[nxt] = -1;
				else if (depth[x] < depth[nxt]) path[nxt] = 2;
				else path[nxt] = -1;//bk edge
			}
			else path[nxt] = 2;
		}
	}
}
void bfs(queue<int> &q,int val) {
	//printf("--%d--\n",val);
	while (q.size()) {
		int x = q.front(); q.pop();
		path[x] = val;
		//printf("%d\n",x);
		for (auto nxt : edge[x]) {
			if (path[nxt] != val) {
				path[nxt] = val;
				q.push(nxt);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,n, m; cin >> n >> m;
		cnt = 0;
		for (i = 1; i <= n; ++i) {
			edge[i].clear();
			path[i] = 0;
			depth[i] = 0;
			st[i] = ed[i] = 0;
		}
		for (i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			edge[a].push_back(b);
		}
		dfs(1); mk_path(1);
		queue<int> q2,q_inf;
		for (i = 1; i <= n; ++i) {
			if (path[i] == -1) q_inf.push(i);
			if (path[i] == 2) q2.push(i);
		}
		bfs(q2, 2); bfs(q_inf, -1);
		for (i = 1; i <= n; ++i) cout << path[i] << " ";
		cout << "\n";
	}
 
	return 0;
}