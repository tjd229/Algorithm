//category : graph, LCA

#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> > edge[100001];
int edge_ix[100001];
int depth[100001];
int p[100001][18];
int ans[100001];
void make_tree(int ix){
	for (int i = 0; i < edge[ix].size(); i++){
		if (depth[edge[ix][i].first] == 0){
			edge_ix[edge[ix][i].first] = edge[ix][i].second;
			p[edge[ix][i].first][0] = ix;
			depth[edge[ix][i].first] = depth[ix] + 1;
			make_tree(edge[ix][i].first);
		}
		else edge[ix][i].first = -1;
	}
}
int climb(int ix,int d){
	int k = 0;
	while (d != 0){
		if (d & 1) ix = p[ix][k];
		k++;
		d >>= 1;
	}
	return ix;
}
int search(int a,int b){
	if (a == b) return a;
	for (int i = 17; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}
int dfs(int ix){
	for (int i = 0; i < edge[ix].size(); i++){
		if (edge[ix][i].first>0){
			ans[edge_ix[ix]] += dfs(edge[ix][i].first);
		}
	}
	return ans[edge_ix[ix]];
}
int main(){
	int i,j;
	int k;
	int n;
	int u, v;
	int a, b;
	scanf("%d",&n);
	for (i = 1; i <= n - 1; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(make_pair(v, i));
		edge[v].push_back(make_pair(u, i));
	}
	depth[1] = 1;
	make_tree(1);
	for (i = 1; i < 18; i++){
		for (j = 1; j <= n; j++){
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}
	for (scanf("%d", &k); k--;){
		scanf("%d%d",&a,&b);
		ans[edge_ix[a]]++;
		ans[edge_ix[b]]++;
		if (depth[a] < depth[b]) b = climb(b, depth[b] - depth[a]);
		if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
		ans[edge_ix[search(a, b)]] -= 2;
	}
	dfs(1);
	for (i = 1; i <= n - 1; i++) printf("%d ",ans[i]);


	return 0;
}