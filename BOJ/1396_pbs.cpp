//category : graph, pbs, djs


#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge{
	int a, b, c;
	bool operator<(Edge e) const{
		return c < e.c;
	}
}edge[100000];
pair<int, int> q[100000];
int l[100000], r[100000], mid[100000];
int p[100001];
int sz[100001];
int v[100000];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void joint(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int main(){
	int i,j;
	int n, m;
	int x, y;
	int Q;
	scanf("%d%d",&n,&m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].c);
	}
	sort(edge, edge + m);
	scanf("%d",&Q);
	for (i = 0; i < Q; i++){
		scanf("%d%d",&x,&y);
		q[i] = make_pair(x, y);
			
	}
	for (i = 0; i < Q; i++){
		l[i] = 0;
		r[i] = m-1;
	}
	bool still;
	while (true){
		for (i = 1; i <= n; i++) p[i] = i,sz[i]=1;
		vector<vector<int> > pbs_q(m);
		still = false;
		for (i = 0; i < Q; i++){
			if (l[i] <= r[i]){
				mid[i] = (l[i] + r[i]) >> 1;
				pbs_q[mid[i]].push_back(i);
				still = true;
			}
		}
		if (!still) break;
		for (i = 0; i < m; i++){
			joint(edge[i].a, edge[i].b);
			for (j = 0; j < pbs_q[i].size(); j++){
				x = q[pbs_q[i][j]].first;
				y = q[pbs_q[i][j]].second;
				if (find(x) == find(y)){
					r[pbs_q[i][j]] = mid[pbs_q[i][j]] - 1;
					v[pbs_q[i][j]] = sz[find(x)];
				}
				else l[pbs_q[i][j]] = mid[pbs_q[i][j]] + 1;
			}
		}
	}
	for (i = 0; i < Q; i++)
		r[i] == m - 1 ? printf("-1\n"):printf("%d %d\n", edge[r[i] + 1].c, v[i]);
	

	return 0;
}

//idea reference : http://jason9319.tistory.com/284