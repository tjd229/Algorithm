//graph, LCA, pst

#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int lg = 20;
const int leaf = 1 << 20;
int depth[100001],pre[100001],post[100001];
int p[100001][lg+1];
int root[100001];
int st[2100001], l[2100001], r[2100001];
int cnt;
vector<int> edge[100001];
void dfs(int x){
	pre[x] = ++cnt;
	for (auto to : edge[x]){
		if (pre[to] == 0){
			depth[to] = depth[x] + 1;
			p[to][0] = x;
			dfs(to);
		}
	}
	post[x] = cnt;
}
int make_tree(int pre,int s,int e,int pos){
	if (e < pos || pos < s) return pre;
	int ix = ++cnt;
	if (s == e) st[ix] = st[pre] + 1;
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos);
		r[ix] = make_tree(r[pre], 1 + ((s + e) >> 1), e, pos);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int sum(int ix, int s, int e, int from, int to){
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(l[ix], s, (s + e) >> 1, from, to) + sum(r[ix], 1 + ((s + e) >> 1), e, from, to);
}
int climb(int x, int d){
	int k = 0;
	while (d){
		if (d & 1) x = p[x][k];
		++k;
		d >>= 1;
	}
	return x;
}
int get_lca(int a, int b){
	if (depth[a] < depth[b]) b = climb(b, depth[b] - depth[a]);
	else if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
	if (a == b) return a;

	for (int k = lg; k >= 0; k--){
		if (p[a][k] != p[b][k]){
			a = p[a][k];
			b = p[b][k];
		}
	}
	return p[a][0];
}
int main(){
	int i,j;
	int n, m, q;
	int a, b;
	vector<pii > way; //from,to(visit time)
	for (scanf("%d", &n), i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	for (i = 1; i <= lg; ++i){
		for (j = 1; j <= n; j++){
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}
	for (scanf("%d", &m); m--;){
		scanf("%d%d",&a,&b);
		if (pre[a] > pre[b]) a ^= b ^= a ^= b;
		way.push_back({pre[a],pre[b]});
	}
	sort(way.begin(), way.end());
	cnt = m = 0;
	for (auto evt : way){
		m = root[evt.first] = make_tree(m, 0, leaf - 1, evt.second);
	}
	for (i = 1; i <= n; i++){
		if (root[i] == 0) root[i] = root[i - 1];
	}
	for (scanf("%d", &q); q--;){
		scanf("%d%d",&a,&b);
		if (pre[a] > pre[b]) a ^= b ^= a ^= b; //a->b
		int lca = get_lca(a, b);
		if (a != lca && b != lca){
			printf("%d\n",1+sum(root[post[a]],0,leaf-1,pre[b],post[b])
				-sum(root[pre[a]-1],0,leaf-1,pre[b],post[b]));
		}
		else{
			int c = climb(b,depth[b]-depth[a]-1);
			int ans = sum(root[pre[c]-1],0,leaf-1,pre[b],post[b]);
			ans += sum(root[post[b]],0,leaf-1,post[c]+1,n)
				-sum(root[pre[b]-1],0,leaf-1,post[c]+1,n);
			printf("%d\n",1+ans);
		}
	}
	return 0;
}
