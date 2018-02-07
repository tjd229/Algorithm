//category : graph, SCC, st, lazy propagation

#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int LEAF = 1 << 19;
const int bnd = 3e5;
int p[bnd + 1], lb[bnd + 1],visit[bnd+1];
ll st[LEAF + LEAF], lazy[LEAF + LEAF];
ll ans[bnd];
vector<int> edge[bnd + 1];
struct Query{
	int l, r, ix;
}qry[bnd];
void propagate(int ix){
	st[ix] += lazy[ix];
	lazy[ix] >>= 1;
	if (ix < LEAF){
		lazy[ix + ix] += lazy[ix];
		lazy[ix + ix + 1] += lazy[ix];
	}
	lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to){
	if (lazy[ix] != 0) propagate(ix);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		lazy[ix] += e - s + 1;
		propagate(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to);
		update(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to);
		st[ix] = st[ix + ix] + st[ix + ix + 1];
	}
}
ll sum(int ix, int s, int e, int ub){
	if (lazy[ix] != 0) propagate(ix);
	if (s> ub) return 0;
	if (e <= ub) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, ub) + sum(ix + ix + 1, 1 + ((s + e) >> 1), e, ub);
}
void dfs(int ix){
	visit[ix]++;
	int to, curr;
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to == p[ix]) continue;
		if (visit[to] == 0){
			p[to] = ix;
			dfs(to);
		}
		else if (visit[to] == 1){
			int l, r;
			l = r = curr = ix;
			visit[curr]++;
			while (curr != to){
				curr = p[curr];
				visit[curr]++;
				if (l > curr) l = curr;
				if (r < curr) r = curr;
			}
			lb[r] = l;
		}
	}
}
int main(){
	int i, j;
	int n, m;
	int a, b;
	int q, l, r;
	ll tot = 0;
	for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (scanf("%d", &q), i = 0; i < q; i++){
		scanf("%d%d", &l, &r);
		qry[i] = { l, r, i };
	}
	sort(qry, qry + q, [](const Query &q1,const Query &q2){
		return q1.r < q2.r;
	});
	if (n > qry[q - 1].r) n = qry[q - 1].r;

	for (i = 1; i <= n; i++){
		if (!visit[i]) dfs(i);
	}
	l = 0;
	for (i = 1,j=0; i <= n; i++){
		if (l < lb[i]) l = lb[i];
		update(1,0,LEAF-1,l+1,i);
		tot += i - l;
		while (j < q&&qry[j].r == i){
			ans[qry[j].ix] = tot - sum(1,0,LEAF-1,qry[j].l-1);
			j++;
		}
	}
	for (i = 0; i < q; i++) printf("%I64d\n",ans[i]);
	return 0;
}
