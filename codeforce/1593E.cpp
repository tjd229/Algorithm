//graph, greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define pii pair<int,int>
using namespace std; 
vector<int> edge[400001];
int deg[400001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i,n,k;
		set<pii > st;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
			edge[i].clear(); deg[i] = 0;
		}
		for (i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
			++deg[u]; ++deg[v];
		}
		for (i = 1; i <= n; ++i) {
			st.insert({deg[i],i});
		}
		int v = n;
		while (k && st.size()) {
			auto it = st.begin();
			vector<int> vec;
			while (it!=st.end() && it->first <= 1) {
				--v;
				vec.push_back(it->second);
				++it;
			}
			for (auto x : vec) {
				st.erase({ deg[x],x });
				--deg[x];
			}
			for (auto x : vec) {
				for (auto p : edge[x]) {
					if (deg[p] <= 0) continue;
					st.erase({deg[p],p});
					st.insert({--deg[p],p});
				}
			}
			--k;
		}
		printf("%d\n",v);
		
 
 
	}
 
	return 0;
}