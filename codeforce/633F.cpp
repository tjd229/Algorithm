//category : graph, tdp

#include <stdio.h>
#include <vector>
#define ll long long
#define mp make_pair
using namespace std;
vector<int> edge[100001];
int a[100001];
ll d[6][100001];
ll ans;
ll max(ll a, ll b){ return a < b ? b : a; }

void dfs(int ix,int from){
	int i, j;
	int to;
	pair<ll, int> f, s, t;
	ll fr = 0;
	ll se = 0;
	int fo = -1;
	f = s = t = mp(0, 0);
	//d[1][to] = a[ix];
	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (from == to) continue;
		dfs(to,ix);

		if (f.first < d[1][to]){
			t = s;
			s = f;
			f = mp(d[1][to], i);
		}
		else if (s.first < d[1][to]){
			t = s;
			s = mp(d[1][to], i);
		}
		else if (t.first < d[1][to])
			t = mp(d[1][to], i);

		if (d[0][ix] < d[0][to]){
			d[0][ix] = d[0][to];
			fo = i;
		}
		if (d[0][ix] < d[1][to]){
			d[0][ix] = d[1][to];
			fo = i;
		}
		if (d[0][ix] < d[2][to]){
			d[0][ix] = d[2][to];
			fo = i;
		}
		

		d[3][ix] = max(d[3][ix], d[3][to]);
		d[3][ix] = max(d[3][ix], d[4][to]);

		d[4][ix] = max(d[4][ix], d[4][to] + a[ix]);
	}

	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (from == to) continue;
		fr = f.first;
		se = s.first;
		if (f.second == i)
			fr = s.first;
		d[4][ix] = max(d[4][ix], fr + a[ix] + d[0][to]);
		d[4][ix] = max(d[4][ix], fr + a[ix] + d[1][to]);
		d[4][ix] = max(d[4][ix], fr + a[ix] + d[2][to]);
		d[5][ix] = max(d[5][ix], fr + a[ix] + d[4][to]);
		if (f.second == i)
			fr = t.first;
		if (s.second == i)
			se = t.first;
		d[5][ix] = max(d[5][ix], fr + se + a[ix] + d[0][to]);
		d[5][ix] = max(d[5][ix], fr + se + a[ix] + d[1][to]);
		d[5][ix] = max(d[5][ix], fr + se + a[ix] + d[2][to]);
		if (fo != i){
			d[5][ix] = max(d[5][ix], d[0][ix] + d[0][to]);
			d[5][ix] = max(d[5][ix], d[0][ix] + d[1][to]);
			d[5][ix] = max(d[5][ix], d[0][ix] + d[2][to]);
		}
	}


	d[1][ix] = f.first + a[ix];
	d[2][ix] = f.first + s.first + a[ix];


	for (i = 0; i < 6; i++) ans = max(d[i][ix], ans);
	
}
int main(){
	int i;
	int n;
	int u, v;

	for (scanf("%d", &n), i = 1; i <= n; i++)
		scanf("%d", a + i);
	while (--n){
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	printf("%I64d", ans);

	return 0;
}