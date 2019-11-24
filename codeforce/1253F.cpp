//graph, dijkstra, djs, pbs
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
struct Tuple {
	int u, v; ll w;
	bool operator<(Tuple t)const {
		return w < t.w;
	}
};
vector<pii > edge[100001];
ll d[100001];
int src[100001];
int p[100001];
 
int l[300001], r[300001];
int a[300001], b[300001];
ll ans[300001];
vector<Tuple> meta;
vector<int> qry[600001];
int find(int a) {
	if (p[a] != a) p[a] =find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, n, m, k, q;
	for (scanf("%d%d%d%d", &n, &m, &k, &q), i = 0; i < m; ++i) {
		int u, v, w; scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back({ v,w });
		edge[v].push_back({ u,w });
		d[u] = d[v] = -1;
	}
	priority_queue<pli > pq;
	for (i = 1; i <= k; ++i) {
		pq.push({0,i});
		src[i] = i;
		d[i] = 0;
	}
	while (pq.size()) {
		int u = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if (dist != d[u]) continue;
		for (auto p : edge[u]) {
			int v = p.first;
			int w = p.second;
			if (d[v]<0 ||d[v] > dist + w) {
				src[v] = src[u];
				d[v] = dist + w;
				pq.push({-d[v],v});
			}
		}
	}
 
	for (i = 1; i <= n; ++i) {
		for (auto p : edge[i]) {
			int w = p.second;
			int x = p.first;
			if (src[x] != src[i]) {
				meta.push_back({src[i],src[x],d[x]+d[i]+w});
				
			}
		}
	}
	sort(meta.begin(), meta.end());
	for (i = 0; i < q; ++i) {
		scanf("%d%d",a+i,b+i);
		l[i] = 0, r[i] = meta.size() - 1;
	}
	
	while (1) {
		bool stop = 1;
		for (i = 1; i <= k; ++i) p[i] = i;
		for (i = 0; i < q; ++i) {
			if (l[i] <= r[i]) {
				int mid = (l[i] + r[i]) >> 1;
				qry[mid].push_back(i);
				stop = 0;
			}
		}
		if (stop) break;
		for (i = 0; i < meta.size(); ++i) {
			int u = meta[i].u;
			int v = meta[i].v;
			ll w = meta[i].w;
			un(u, v);
			for (auto qix : qry[i]) {
				if (find(a[qix]) == find(b[qix])) {
					ans[qix] = w;
					r[qix] = i - 1;
				}
				else l[qix] = i + 1;
			}
			qry[i].clear();
		}
	}
	for (i = 0; i < q; ++i) printf("%I64d\n",ans[i]);
 
	return 0;
}
