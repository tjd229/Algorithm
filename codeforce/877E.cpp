//categoty : graph, st, lazy propagation

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int LEAF = 1 << 18;
int cnt;
int sw[LEAF+LEAF],lazy[LEAF+LEAF];
int st[LEAF + LEAF],cover[LEAF+LEAF];
int pre[200001], post[200001];
vector<int> edge[200001];

void init(int ix,int val){
	st[ix] = val;
	cover[ix] = 1;
	ix >>= 1;
	while (ix != 0){
		st[ix] = st[ix + ix] + st[ix + ix + 1];
		cover[ix] = cover[ix + ix] + cover[ix + ix + 1];
		ix >>= 1;
	}
}
void propagate(int ix){
	if (lazy[ix] == 0) return;
	sw[ix] ^= lazy[ix];
	st[ix] = cover[ix] - st[ix];
	if (ix < LEAF){
		lazy[ix + ix] ^= lazy[ix];
		lazy[1 + ix + ix] ^= lazy[ix];
	}
	lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to, int val){
	propagate(ix);
	if (e < from || to < s) return;
	if (s >= from&&to >= e){
		sw[ix] ^= val;
		st[ix] = cover[ix] - st[ix];
		if (ix < LEAF){
			lazy[ix + ix] ^= val;
			lazy[1+ix + ix] ^= val;
		}
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, val);
		update(ix + ix+1, 1+((s + e) >> 1),e, from, to, val);
		st[ix] = st[ix + ix] + st[ix + ix + 1];
	}
}
int get(int ix, int s, int e, int from, int to){
	propagate(ix);
	if (e < from || to < s) return 0;
	if (s >= from&&to >= e) return st[ix];
	return get(ix + ix, s, (s + e) >> 1, from, to) + get(ix + ix+1, 1+((s + e) >> 1),e, from, to);
}
void dfs(int ix){
	pre[ix] = ++cnt;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i]);
	post[ix] = cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string task;
	int i;
	int n;
	int p,t,q,v;
	cin >> n;
	for (i = 2; i <= n; i++){
		cin >> p;
		edge[p].push_back(i);
	}
	dfs(1);
	for (i = 1; i <= n; i++){
		cin >> t;
		init(LEAF+pre[i],t);
	}
	cin >> q;
	while (q--){
		cin >> task>>v;
		if (task[0] == 'g'){
			cout << get(1, 0, LEAF - 1, pre[v], post[v]) << "\n";
		}
		else
			update(1,0,LEAF-1,pre[v],post[v],1);
	}

	return 0;
}
