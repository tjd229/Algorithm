//category : graph, SCC

#include <stdio.h>
#include <vector>
#define MAX_N 200001
#define MODULO 1000000007
using namespace std;
bool visit[MAX_N];
int power2[MAX_N];
long long pow2(int e){
	if (e == 0) return 1;
	if (e == 1) return 2;
	if (power2[e] != 0) return power2[e];

	if (e & 1) power2[e] = (pow2(e - 1) * 2) % MODULO;
	else power2[e] = (pow2(e / 2) * pow2(e / 2)) % MODULO;
	return power2[e];
}
void dfs(int ix, bool stamp, vector<int> edge[MAX_N]){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++) dfs(edge[ix][i], stamp, edge);
	edge[0].push_back(ix);
}
vector<int> edge[MAX_N];
vector<int> back[MAX_N];
int main(){
	int i;
	int n;
	int a;
	long long ans = 1;
	int non_scc = 0;
	
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d",&a);
		edge[i].push_back(a);
		back[a].push_back(i);
	}
	for (i = 1; i <= n; i++) dfs(i, true, edge);
	for (i = edge[0].size() - 1; i >= 0; i--){
		dfs(edge[0][i], false, back);
		if (back[0].size() > 1){
			ans *= pow2(back[0].size())-2;
			ans %= MODULO;
		}
		if (back[0].size() == 1){
			non_scc++;
		}
		back[0].clear();
	}
	ans *= pow2(non_scc);
	ans %= MODULO;
	printf("%I64d",ans);
	return 0;
}