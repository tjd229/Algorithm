//category : graph, LCA

#include <stdio.h>
#include <vector>
#include <algorithm>
#define MIN(a,b) a<b? a:b
using namespace std;
vector<int> edge[100001];
vector<int> people[100001];
vector<int> candidate[100001][18];
int p[100001][18];
int depth[100001];
bool visit[100001];

vector<int> merge(vector<int> &v1,vector<int> &v2){
	vector<int> v(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());	
	v.erase(unique(v.begin(),v.end()),v.end());
	while (v.size() > 10) v.pop_back();
	return v;
}
void dfs(int ix){
	visit[ix] = true;
	for (int i = 0; i < edge[ix].size(); i++){
		if (!visit[edge[ix][i]]){

			depth[edge[ix][i]] = depth[ix]+1;

			p[edge[ix][i]][0] = ix;
			candidate[edge[ix][i]][0] = merge(people[ix],people[edge[ix][i]]);
			dfs(edge[ix][i]);
		}
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
	for (int i = 17; i >=0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}
int main(){
	int i,j,k;
	int n, m, q;
	int u, v;
	int c,a;
	int diff;
	int lca;
	vector<int> ans;
	scanf("%d%d%d",&n,&m,&q);
	for (i = 0; i < n - 1; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (i = 1; i <= m; i++){
		scanf("%d",&c);
		if (people[c].size()<10)
			people[c].push_back(i);
	}
	dfs(1);
	for (j = 1,k=2; j < 18; j++,k<<=1){
		for (i = 1; i <= n; i++){
			p[i][j] = p[p[i][j - 1]][j - 1];
			if (depth[i] >= k)
				candidate[i][j] = merge(candidate[p[i][j - 1]][j - 1], candidate[i][j-1]);
		}
	}

	while (q--){
		scanf("%d%d%d",&u,&v,&a);
		i = u;
		j = v;
		if (depth[i] > depth[j]) i = climb(i, depth[i] - depth[j]);
		if (depth[i] < depth[j]) j = climb(j, depth[j] - depth[i]);
		lca = search(i, j);
		i = u;
		j = v;
		ans = people[lca];
		k = 0;
		diff = depth[u] - depth[lca];
		while (diff != 0){
			if (diff & 1){
				ans = merge(ans, candidate[i][k]);
				i = p[i][k];
			}
			k++;
			diff >>= 1;
		}
		k = 0;
		diff = depth[v] - depth[lca];
		while (diff != 0){
			if (diff & 1){
				ans = merge(ans, candidate[j][k]);
				j = p[j][k];
			}
			k++;
			diff >>= 1;
		}
		k = MIN(a, ans.size());
		printf("%d ",k);
		for (i = 0; i < k; i++) printf("%d ",ans[i]);
		printf("\n");
	}

	return 0;
}