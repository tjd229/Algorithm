//graph, bs

#include "chameleon.h"
#include <vector>
using namespace std;
namespace {

	vector<int> edge[1001];
	int vis[1001];
	int clr[1001];
	int p[1001];
}  // namespace
void dfs(int x, int c,int stamp) {
	if (vis[x] == stamp) return;
	vis[x] = stamp;
	clr[x] = c;
	for (auto nxt : edge[x]) dfs(nxt, 3 - c, stamp);
}
int qry(vector<int> p,int self) {
	if (p.empty()) return 1;
	p.push_back(self);
	return Query(p);
}

void Solve(int N) {
	int NN = N + N;
	vector<int> clr_set[3];
	for (int i = 2; i <= NN; ++i) {
		clr_set[2].clear(); clr_set[1].clear();
		for (int j = 1; j < i; ++j) {
			dfs(j, 1, i);
			clr_set[clr[j]].push_back(j);
		}
		for (int j = 1; j <= 2; ++j) {
			vector<int> &st = clr_set[j];
			if (st.empty()) continue;
			while (st.size() >= qry(st, i)) {
				int l = 0, r = st.size() - 1;
				int pick = 0;
				while (l < r) {
					int m = (l + r) >> 1;
					//
					vector<int> v(st.begin()+l, st.begin()+ m + 1);
					if (qry(v, i) <= v.size()) {
						//r = m - 1;
						r = m;
						//pick = m;
					}
					else 
						l = m + 1;
					
				}
				pick = l;
				edge[st[pick]].push_back(i); edge[i].push_back(st[pick]);
				st.assign(st.begin() + pick + 1, st.end());
			}
		}
	}
	for (int i = 1; i <= NN; ++i) {
		for (auto x : edge[i]) p[i] += x;
	}
	for (int i = 1; i <= NN; ++i) {
		if (edge[i].size() == 1) continue;
		int to = -1;
		for (int j = 0; j < edge[i].size() && to<0; ++j) { //pick
			vector<int> v;
			for (auto x : edge[i]) {
				if (edge[i][j] == x) continue;
				v.push_back(x);
			}
			if (qry(v, i) == 1) to = edge[i][j];
		}
		p[i] -= to;
		p[to] -= i;
	}
	for (int i = 1; i <= NN; ++i) if (i < p[i]) Answer(i, p[i]);
}
