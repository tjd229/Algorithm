//graph, djs
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
struct Tuple {
	int x, y, z;
	bool operator<(Tuple &t) const{
		if (t.x == x) return y < t.y;
		return x < t.x;
	}
}acq[500000];
int g[500001];
int clr[1000001],vis[1000001],p[1000001];
int a[500001],b[500001],c[500001];
vector<int> edge[500001];
bool inv[500001];
int cnt;
void bfs(int src,int stamp) {
	int G = c[src];
	if (inv[G]) return;
	if (vis[src] == stamp) return;
	int l = cnt++, r = cnt++;
	vector<int> q = { src }; int i = 0;
	g[src] = l; vis[src] = stamp;
	while (i < q.size() && inv[G]==0) {
		int ited = q.size();
		for (; i < ited&& inv[G] == 0; ++i) {
			int x = q[i];
			for (auto nxt : edge[x]) {
				if (vis[nxt] != stamp) {
					vis[nxt] = stamp;
					g[nxt] = g[x] ^ 1;
					q.push_back(nxt);
				}
				else if(g[nxt]!=(g[x]^1)){
					inv[G] = 1;
				}
			}
		}
		i = ited;
	}

}
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool dsu(int a,int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	return 1;
}
int main() {
	int i, n, m, k;
	int q = 0;
	for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i) scanf("%d",c+i);
	for (i = 0; i < m; ++i) {
		scanf("%d%d",a+i,b+i);
		if (c[a[i]] == c[b[i]]) {
			edge[a[i]].push_back(b[i]);
			edge[b[i]].push_back(a[i]);
		}
		else {
			if (c[a[i]] > c[b[i]]) a[i] ^= b[i] ^= a[i] ^= b[i];
			acq[q++] = { c[a[i]],c[b[i]],i };
		}
	}sort(acq, acq + q);
	int stamp = 1;
	int f = 0;
	for (i = 1; i <= n; ++i) bfs(i, stamp);
	for (i = 1; i <= k; ++i) f += inv[i];
	k -= f;
	ll ans = ((ll)k * (k-1)) >> 1;
	for (i = 0;i<q;) {
		int j = i;
		int A = acq[i].x, B = acq[i].y;
		++stamp;
		bool x = 0;
		while (j < q && acq[j].x == A && acq[j].y == B) {
			int eix = acq[j].z;
			int ga = g[a[eix]], gb = g[b[eix]];
			p[ga] = ga, p[gb] = gb;
			p[ga ^ 1] = ga ^ 1, p[gb ^ 1] = gb ^ 1;
			++j;
		}
		for (; i < j;++i) {
			int eix = acq[i].z;
			int ga = g[a[eix]], gb = g[b[eix]];
			int pa = find(ga), pb = find(gb);
			if (pa==pb) x = 1;
			pa = find(ga^1), pb = find(gb^1);
			if (pa == pb) x = 1;
			
			
			dsu(ga, gb ^ 1); dsu(ga ^ 1, gb);
						
		}
		if (inv[A] == 0 && inv[B] == 0) ans -= x;
		
		//printf("%d,%d,%d\n", A, B, x);
	}
	printf("%I64d\n",ans);
	return 0;
}