//category : graph, LCA, pst
//idea reference : https://lyzqm.blogspot.kr/2017/09/persistent-segment-tree-k.html
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 17;
int st[LEAF * 18], l[LEAF * 18], r[LEAF * 18];
int root[100001];
int p[18][100001];
int depth[100001];
int value[100001];
int decomp[100001];
int cnt;
vector<int> edge[100001];
int compress(int x, const vector<int> &v){
	return (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}
int make_tree(int pre, int s, int e, int pos){
	if (e < pos || pos < s) return pre;
	int ix = ++cnt;
	if (s == e)
		st[ix] = 1;
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos);
		r[ix] = make_tree(r[pre], 1 + ((s + e) >> 1), e, pos);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int query(int X, int Y, int lca, int plca, int s, int e, int k){
	if (s == e) return s;
	int len = st[l[X]] + st[l[Y]] - st[l[lca]] - st[l[plca]];
	if (len >= k) return query(l[X], l[Y], l[lca], l[plca], s, (s + e) >> 1, k);
	else return query(r[X], r[Y], r[lca], r[plca], 1 + ((s + e) >> 1), e, k - len);
}
int climb(int n, int d){
	int k = 0;
	while (d != 0){
		if (d & 1) n = p[k][n];
		k++;
		d >>= 1;
	}
	return n;
}
int get_lca(int a, int b){
	if (depth[a] < depth[b]) b = climb(b, depth[b] - depth[a]);
	if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
	if (a == b) return a;	//include root case

	int j = 17;
	for (; j >= 0; j--){
		if (p[j][a] != p[j][b]){
			a = p[j][a];
			b = p[j][b];
		}
	}
	return p[0][a];
}
void dfs(int ix, int from){
	int to;
	root[ix] = make_tree(root[from], 0, LEAF - 1, value[ix]); //O(lgN)
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to != from){
			depth[to] = depth[ix] + 1;
			p[0][to] = ix;
			dfs(to, ix);
		}
	}
}
int main(){
	int i, j, k;
	int N, M;
	int X, Y, K;
	int lca;
	vector<int> v;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; i++){
		scanf("%d", value + i);
		v.push_back(value[i]);
	}

	for (--i; --i;){
		scanf("%d%d", &X, &Y);
		edge[X].push_back(Y);
		edge[Y].push_back(X);
	}
	sort(v.begin(), v.end());
	for (i = 1; i <= N; i++){
		//compress to {1~N}
		X = compress(value[i], v);
		decomp[X] = value[i];
		value[i] = X;
	}
	dfs(1, 0);
	for (j = 1; j < 18; j++){
		for (i = 1; i <= N; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];
	}
	while (M--){
		scanf("%d%d%d", &X, &Y, &K);
		lca = get_lca(X, Y);
		i = query(root[X], root[Y], root[lca], root[p[0][lca]], 0, LEAF - 1, K);

		printf("%d\n",v[i-1]);
		
	}
	

	return 0;
}
