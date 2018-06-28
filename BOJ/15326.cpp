//category : graph, LCA, djs

#include <stdio.h>
#include <vector>
using namespace std;
const int lg = 20;
const int bnd = 3e5;
const int mod = 1e9 + 7;
int clan[bnd+bnd + 1];
int sz[bnd+bnd + 1];
int clr[bnd + 1];
int jump[bnd + 1];
int depth[bnd+1];
int p[bnd + 1][lg];
vector<int> edge[bnd + 1];
void dfs(int ix, int from){
	for (int i = 0; i < edge[ix].size(); i++){
		int to = edge[ix][i];
		if (from == to) continue;
		if (depth[to] == 0){
			depth[to] = depth[ix] + 1;
			p[to][0] = ix;
			dfs(to, ix);
		}
	}
}
int find(int a){
	if (clan[a] != a) clan[a] = find(clan[a]);
	return clan[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (b < a) a ^= b ^= a ^= b;
	sz[a] += sz[b];
	clan[b] = a;
}
int back(int ix,int dst,int c){
	int b = p[ix][0];
	c = find(c);
	//printf("-%d\n",ix);
	if (jump[ix]){ //colred

		if(jump[ix]!=ix) b = jump[ix];
		int cc = find(clr[ix]);
		if (c != cc && (c >> 1) == (cc >> 1)) return -1;
		join(c, cc);
		join(c^1, cc^1);
		c = find(c);
		if (depth[b]>depth[dst]) jump[ix] = back(b, dst, c);
	}
	else{
		//printf("-%d\n", ix);
		sz[c]++;
		if (b == dst) jump[ix] = ix;
		else jump[ix] = back(b,dst,c);
	}
	clr[ix] = find(c);
		
	return jump[ix];

}
int climb(int ix, int d){
	int k = 0;
	while (d != 0){
		if (d & 1) ix = p[ix][k];
		k++;
		d >>= 1;
	}
	return ix;
}
int get_lca(int a, int b){
	if (a == b) return a;
	int k = 1 << (lg-1);
	int j = lg-1;
	for (; j >= 0; j--, k >>= 1){
		if (p[a][j] != p[b][j]){
			a = p[a][j];
			b = p[b][j];
		}
	}
	a = p[a][0];
	return a;
}
int main(){
	int i,j;
	int N, M;
	int a, b;
	for (scanf("%d%d", &N, &M), i = 1; i < N; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	for (j = 1; j < lg; j++){
		for (i = 1; i <= N; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];
	}
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		
		int pa = a;
		int pb = b;
		if (depth[pa] < depth[pb]) pb = climb(pb, depth[pb] - depth[pa]);
		if (depth[pa] > depth[pb]) pa = climb(pa, depth[pa] - depth[pb]);
		int lca = get_lca(pa, pb);
		clan[i << 1] = i << 1;
		clan[(i << 1)+1] = (i << 1)+1;
		if (a != lca){
			if (back(a, lca, (i << 1)) < 0){
				printf("0");
				return 0;
			}
		}
		if (b != lca){
			if (back(b, lca, (i << 1)+1) < 0){
				printf("0");
				return 0;
			}
		}
		if (lca!=a && lca!=b && find(clr[b]) == find(clr[a])){
			printf("0");
			return 0;
		}
	}
	long long ans = 1;
	for (i = 0; i <M; i++){
		a = (i << 1);
		b = a+ 1;
		if (a == clan[a]){
			N -= sz[a];
			ans <<= 1;
			ans %= mod;
		}
		if (b == clan[b]) N -= sz[b];
	}
	long long bi = 2;

	N--;
	while (N){
		if (N & 1)
			ans = ans*bi%mod;
		N >>= 1;
		bi = bi*bi%mod;		
	}
	printf("%lld",ans);

	return 0;
}
