//category : graph, djs


#include <stdio.h>
#include <vector>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
vector<pii > edge;
int p[100001];
int family[100001];
int trail[100001];
const int mod = 1e9 + 7;
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool join(int a, int b){
	a = find(a);
	b = find(b);
	trail[a]++;
	if (a == b) return false;
	p[b] = a;
	family[a] += family[b];
	trail[a] += trail[b];
	return true;
}
int main(){
	
	int i;
	int N, M;
	int u, v;
	long long ans = 1;
	scanf("%d%d",&N,&M);
	for (i = 0; i < M; i++){
		scanf("%d%d",&u,&v);
		edge.pb(mp(u, v));
		p[u] = u;
		p[v] = v;
		family[u] = family[v] = 1;
	}
	for (i = 0; i < M; i++){
		join(edge[i].first, edge[i].second);
	}
	for (i = 1; i <= N; i++){
		if (i != p[i]) continue;
		if (trail[i] > family[i]) return printf("0");
		else if (trail[i] < family[i]) ans *= family[i];
		else ans *= 2;
		if (ans >= mod) ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}