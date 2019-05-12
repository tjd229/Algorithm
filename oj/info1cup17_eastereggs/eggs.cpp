//graph, bs
#include <bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include <set>
#include "grader.h"
#define pii pair<int,int>
using namespace std;
int p[513],d[513];
vector<int> order;
void dfs(int x,int from,vector<int> *edge) {
	order.push_back(x);
	p[x] = from;
	for (auto nxt : edge[x]) {
		if (nxt != from) {
			d[nxt] = d[x] + 1;
			dfs(nxt, x, edge);
		}
	}
}
void make_beauty(vector<int> &tree) {
	set<pii > st;//depth,x
	for (auto x : tree) {
		st.insert({-d[x],x});
	}
	while (st.size() > 1) {
		int depth = st.begin()->first;
		while (st.begin()->first ==depth) {
			int par = p[st.begin()->second];
			if (st.find({ -d[par],par }) == st.end()) {
				tree.push_back(par);
				st.insert({ -d[par],par });
			}
			st.erase(st.begin());
		}
	}
}
int ask(int l,int r) {
	vector<int> v;
	for (int i = l; i <= r; ++i) v.push_back(order[i]);
	//
	make_beauty(v);
	return query(v);
}
int findEgg (int N, vector < pair < int, int > > bridges)
{
	vector<int> edge[513]; order.clear();
	for (auto p : bridges) {
		int u = p.first, v = p.second;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	d[1] = 0;
	dfs(1, -1, edge);
	int l = 0, r = N-1;
	int k = -1;
	while (l <= r) {
		if (l == r && l == N - 1) {
			k = N - 1;
			break;
		}
		int m = (l + r)>>1;
		if (ask(l, m)) k=m,r = m-1;
		else l = m + 1;
	}
    return order[k];
}