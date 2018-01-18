//category : pst, graph
//reference : http://codeforces.com/contest/893/submission/32647362

#include <stdio.h>
#include <vector>
using namespace std;
const int e6 = 1e6;
const int LEAF = 1 << 20;
int cnt;
int root[e6 + 1];
int st[e6 *21], l[e6 *21], r[e6*21];
int a[e6+1],depth[e6+1],deep[e6+1];
int pre[e6 + 1], post[e6 + 1];
int mark[e6 + 1];
vector<int> edge[e6+1];
int min(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? a : b;
}
int dfs(int ix, int from, int d){
	pre[ix] = ++cnt;
	depth[ix] = d;
	deep[ix] = d;
	for (int i = 0; i < edge[ix].size(); i++){
		if (edge[ix][i] != from){
			int res=dfs(edge[ix][i],ix,d+1);
			if (res > deep[ix]) deep[ix] = res;
		}
	}
	post[ix] = cnt;
	return deep[ix];
}
int make_tree(int pre, int s, int e, int pos, int val){
	if (pos > e || pos < s) return pre;
	int ix = ++cnt;
	if (s == e){
		st[ix] = val;
	}
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos, val);
		r[ix] = make_tree(r[pre], 1+((s + e) >> 1),e, pos, val);
		st[ix] = min(st[l[ix]], st[r[ix]]);
	}
	return ix;
}
int query(int ix,int s,int e,int from,int to){
	if (e < from || to < s) return 0;
	if (s >= from&&to >= e) return st[ix];
	return min(query(l[ix], s, (s + e) >> 1, from, to), query(r[ix], 1+((s + e) >> 1),e, from, to));
}
int main(){
	int i,j;
	int n, r;
	int x, y, k;
	int m, p, q;
	int ans=0;
	for (scanf("%d%d", &n, &r), i = 1; i <= n;i++){
		scanf("%d",a+i);
	}
	for (i = 1; i < n; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(r, 0, 0);
	vector<int> que;
	que.push_back(r);
	for (i = 0; que.size()!=n; i++){
		x = que[i];
		for (j = 0; j < edge[x].size(); j++){
			y = edge[x][j];
			if (depth[x] < depth[y]) que.push_back(y);
		}
	}
	cnt = 0;
	y = 0;
	k=0;
	for (i = 0; que.size()>i; i++){
		x = que[i];
		if (depth[x] != depth[y]) mark[k++] = i-1;
		root[x]=make_tree(root[y],0,LEAF-1,pre[x],a[x]);
		y = x;
	}
	mark[k++] = i - 1;
	for (scanf("%d", &m); m--;){
		scanf("%d%d",&p,&q);
		x = ((p + ans) % n) + 1;
		k = (q + ans) % n;
		y = depth[x] + k;
		y = y < deep[x] ? y : deep[x];
		ans = query(root[que[mark[y]]],0,LEAF-1,pre[x],post[x]);
		printf("%d\n",ans);
	}

	return 0;
}
