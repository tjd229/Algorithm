//graph
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <set>
#include <queue>
#define pii pair<int,int>
using namespace std;
int surv[200001];
int up[200001], dn[200001];
pii edge[400001];
vector<int> frs[200001];
inline int to(int src,int eix) {
	if (edge[eix].first == src) return edge[eix].second;
	else edge[eix].first;
}
int main() {
	int i, n, m; 	
	int eix = 0;
	set<tuple<int, int, int> > st; //u,v,edge_ix
	for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		if (u > v) u ^= v ^= u ^= v;
		edge[eix] = { u,v };
		st.insert({u,v,eix});
		frs[u].push_back(eix);
		frs[v].push_back(eix); ++eix;
		if (u < v) {
			++up[u]; ++dn[v];
		}
		else {
			++up[v]; ++dn[u];
		}
	}
	
	int remain = 0;
	for (i = 1; i <= n; ++i) {
		if (up[i] == 0 ) {
			surv[i] = 1;
			++remain;
		}
	}
	
	int q;
	for (scanf("%d", &q); q--;) {
		int cmd; scanf("%d",&cmd);
		if (cmd == 1) {
			int u, v; scanf("%d%d",&u,&v);
			if (u > v) u ^= v ^= u ^= v;
			edge[eix] = { u,v };
			st.insert({ u,v,eix });
			frs[u].push_back(eix);
			frs[v].push_back(eix); ++eix;
			if (u < v) {
				++up[u]; ++dn[v];
			}
			else {
				++up[v]; ++dn[u];
			}
			if (surv[u] && up[u] > 0) {
				surv[u] = 0;
				--remain;
			}
			if (surv[v] && up[v] > 0) {
				surv[v] = 0;
				--remain;
			}
		}
		else if (cmd == 2) {
			int u, v; scanf("%d%d", &u, &v);
			if (u > v) u ^= v ^= u ^= v;
			auto it=st.lower_bound({u,v,-1});
			int rm; tie(ignore, ignore, rm) = *it;
			st.erase(it);
			edge[rm] = { 0,0 };
			if (u < v) {
				--up[u]; --dn[v];
			}
			else {
				--up[v]; --dn[u];
			}
			if (surv[u]==0 && up[u] ==0) {
				surv[u] = 1;
				++remain;
			}
			if (surv[v] == 0 && up[v] == 0) {
				surv[v] = 1;
				++remain;
			}
		}
		else {
			
			printf("%d\n",remain);
		}
	}
 
	return 0;
}