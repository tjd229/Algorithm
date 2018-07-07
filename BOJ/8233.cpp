//category : graph, math

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
#define ll long long
using namespace std;
vector<pii > edge[500001];
int p[500001];
int coef[500001];
ll k[500001];
ll lo, hi;
ll max(ll a, ll b){ return a < b ? b : a; }
ll min(ll a, ll b){ return a > b ? b : a; }
bool dfs(int ix){
	bool res = true;
	coef[0] += coef[ix];
	k[0] += k[ix];
	for (int i = 0; i < edge[ix].size() && res; i++){
		int to = edge[ix][i].first;
		int b = edge[ix][i].second;
		if (coef[to]){
			if (coef[to] == coef[ix]){
				int kk = coef[ix] * (b-k[ix]-k[to]);
				if (kk & 1) return false;
				kk >>= 1;
				if (lo > kk || hi < kk) return false;
				lo = hi = kk;
			}
			else if (b != k[ix] + k[to]) return false;
		}
		else{
			coef[to] = -coef[ix];
			k[to] = b - k[ix];
			if (coef[to] > 0){
				lo = max(lo,-k[to]);
				hi = min(hi, p[to] - k[to]);
			}
			else{
				lo = max(lo, k[to]-p[to]);
				hi = min(hi, k[to]);
			}
			res &= dfs(to);
		}
	}
	return res;
}
int main(){
	int i;
	int n, m;
	int u, v, b;
	ll tot = 0;
	ll mx, mn;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; i++) scanf("%d",p+i),tot+=p[i];
	while (m--){
		scanf("%d%d%d",&u,&v,&b);
		edge[u].push_back({ v, b });
		edge[v].push_back({ u, b });
	}
	mx = mn = 0;
	for (i = 1; i <= n; i++){
		if (coef[i]) continue;
		coef[i] = 1;
		lo = 0;
		hi = p[i];
		k[0] = coef[0] = 0;
		if (!dfs(i) || lo>hi){
			printf("NIE");
			return 0;
		}
		if (coef[0] < 0) lo ^= hi ^= lo ^= hi; //- or +
		mx += coef[0] * hi + k[0];
		mn += coef[0] * lo + k[0];
	}
	printf("%lld %lld",tot-mx,tot-mn);

	return 0;
}
