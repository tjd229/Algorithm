//graph, greedy
#include <stdio.h>
#include <vector>
#include <set>
#define pii pair<int,int>
using namespace std;
vector<int> edge[100001];
int d[100001];//deg
int depth[100001];//vis
int from[100001];
bool removed[100001];
set<pii > st;
void discon(int x) {
	if (removed[x]) return;
	removed[x] = 1;
	auto it = st.lower_bound({ d[x],x });
	st.erase(it);
	for (auto y : edge[x]) {
		if (removed[y]) continue;
		auto it = st.lower_bound({d[y],y});
		st.erase(it);
		st.insert({--d[y],y});
	}
}
int dfs(int x) {
	int nxt = -1;
	for (auto y : edge[x]) {
		if (removed[y]) continue;
		if (depth[y] == 0) {
			depth[y] = depth[x] + 1;
			from[y] = x;
			return dfs(y);
		}
		else if (nxt<0 || depth[nxt] > depth[y])
			nxt = y;
	}
	from[nxt] = x;
	return nxt;
}
int main() {
	int i, n, m;
	vector<int> indp;
	for (scanf("%d%d", &n, &m), i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		++d[u]; ++d[v];
	}
	int sq = 0;
	while (sq*sq < n) ++sq;
	for (i = 1; i <= n; ++i) st.insert({ d[i],i });
 
	while (st.size() && indp.size()<sq) {
		auto it = st.begin();
		if (it->first >= sq - 1) {
			int root = it->second;
			depth[root] = 1;
			int head=dfs(root);
			int tail = from[head];
			printf("2\n%d\n%d ", depth[tail] - depth[head] + 1,head);
			while (tail != head) {
				printf("%d ",tail);
				tail = from[tail];
			}
			return 0;
			
		}
 
		int x = it->second;
		indp.push_back(x);
		discon(x);
		for (auto y : edge[x])
			discon(y);
	}
 
	for (printf("1\n"), i = 0; i < indp.size(); ++i)
		printf("%d ",indp[i]);
 
	return 0;
}