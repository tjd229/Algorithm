//graph, djs, MST, greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll ans[200001];
int p[200001];
int sz[200001];
int q[200000];
struct Tuple {
	int x, y, z;
	bool operator< (Tuple &t)const {
		return z < t.z;
	}
}edge[200000];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
ll un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	ll res = (ll)sz[a] * sz[b];
	sz[a] += sz[b];
	return res;
}
int main() {
	int i, j,n, m;
	int mxq = 0;
	for (scanf("%d%d", &n, &m), i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d",&u,&v,&w);
		edge[i] = {u,v,w};
		p[i] = i; 
		sz[i] = 1;
	}
	sz[n] = 1; p[n] = n;
	sort(edge + 1, edge + n);//[1,n)
	for (i = 0; i < m; ++i) {
		scanf("%d",q+i);
		if (mxq < q[i]) mxq = q[i];
	}
	for (i =j=1; i <= mxq; ++i) {
		ans[i] = ans[i - 1];
		while (j < n && edge[j].z <= i) {
			ans[i] += un(edge[j].x,edge[j].y);
			++j;
		}
	}
	for (i = 0; i < m; ++i)
		printf("%I64d ",ans[q[i]]);
	return 0;
}