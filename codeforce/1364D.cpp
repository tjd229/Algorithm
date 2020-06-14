//graph, greedy
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
vector<int> edge[100001];
int from[100001];
int depth[100001];
bool ban[100001];
vector<int> indp;
int n, m, k;
int tail,head;
void dfs(int x) {
	bool leaf = 1;
	//printf("%d\n",x);
	for (auto nxt : edge[x]) {
		if (from[x] == nxt) continue;
		if (depth[nxt] == 0) {
			depth[nxt] = depth[x] + 1;
			from[nxt] = x;
			dfs(nxt);
			leaf = 0;
		}
		else if (depth[x]>depth[nxt]&&depth[x] - depth[nxt] + 1 <= k) {
			//printf("%d,%d\n",x,nxt);
			//cout << depth[x] - depth[nxt] + 1 << endl;
			tail = x;
			head = nxt;
		}
	}
	if (leaf)
		indp.push_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	depth[1] = 1;
	dfs(1);
	if (tail + head) {
		vector<int> ans;
		ans.push_back(head);
		while (tail != head) {
			//cout << tail << endl;
			ans.push_back(tail);
			tail = from[tail];
		}
		cout << "2\n" << ans.size() << "\n";
		for (auto x : ans)
			cout << x << " ";
	}
	else {
		int sz = (k&1)+(k >> 1);
		for (auto x : indp) {
			ban[x] = 1;
			for (auto y : edge[x]) ban[y] = 1;
		}
		for (int i = 0; i < indp.size() && indp.size() < sz; ++i) {
			int x = indp[i];
			while (x) {
				if (ban[x] == 0) {
					ban[x] = 1;
					indp.push_back(x);
					for (auto y : edge[x]) ban[y] = 1;
				}
				int p = from[x];
				from[x] = 0;
				x = p;
			}
		}
		cout << "1\n";
		for (int i = 0; i < sz; ++i) cout << indp[i] << " ";
	}
	return 0;
}