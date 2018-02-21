//category : st, lazy propagation, graph

#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int LEAF = 1 << 19;
int cnt;
int pre[400001], post[400001];
int c[400001];
int lazy[LEAF + LEAF];
ll st[LEAF + LEAF];
vector<int> edge[400001];
void propagete(int ix){
	st[ix] = 1LL << lazy[ix];
	if (ix < LEAF)
		lazy[ix + ix] = lazy[ix + ix + 1] = lazy[ix];
	lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to, int c){
	if(lazy[ix]) propagete(ix);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		lazy[ix] = c;
		propagete(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, c);
		update(ix + ix+1, 1+((s + e) >> 1), e,from, to, c);
		st[ix] = st[ix + ix] | st[ix + ix + 1];
	}
}
ll query(int ix, int s, int e, int from, int to){
	if (lazy[ix]) propagete(ix);
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return st[ix];
	return query(ix + ix, s, (s + e) >> 1, from, to) | query(ix + ix+1, 1+((s + e) >> 1),e, from, to);
}

void dfs(int ix){
	pre[ix] = ++cnt;
	for (int i = 0; i < edge[ix].size(); i++){
		if (pre[edge[ix][i]]==0)
			dfs(edge[ix][i]);
	}
	post[ix] = cnt;
}
int main(){
	int i;
	int n, m;
	int x, y;
	int t, v;

	for (scanf("%d%d", &n, &m), i = 1; i <= n; i++) scanf("%d",c+i);
	for (i = 1; i < n; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1);
	for (i = 1; i <= n; i++){
		x = LEAF + pre[i];
		st[x] = 1LL << c[i];
		x >>= 1;
		while (x){
			st[x] = st[x + x] | st[x + x + 1];
			x >>= 1;
		}
	}
	while (m--){
		scanf("%d%d",&t,&v);
		if (t == 1){
			scanf("%d",&y);
			update(1, 0, LEAF - 1, pre[v], post[v], y);
		}
		else{
			ll stat = query(1, 0, LEAF - 1,pre[v], post[v]);
			for (x=0,i=1; i <= 60; i++)
				x += ((stat&(1LL << i))!=0);
			printf("%d\n", x);
		}
	}
	return 0;
}

