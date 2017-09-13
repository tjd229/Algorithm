//Water supply
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4393
//category : graph, SCC

#include <stdio.h>
#include <vector>
using namespace std;
int visit[1001];
int water[1001];
void supply(int ix, vector<int> edge[1001], int stamp){
	if (visit[ix] == stamp) return;
	visit[ix] = water[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		supply(edge[ix][i], edge, stamp);

}
void dfs(int ix, int stamp, vector<int> edge[1001], vector<int> &hist){
	if (water[ix] == stamp || water[ix] == -stamp) return;
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], stamp, edge, hist);
	hist.push_back(ix);
}
int main(){
	int i, j, k;
	int turn = 0;
	int ans;
	int N, M;
	int a, b;
	while (scanf("%d%d", &N, &M) == 2){
		turn++;
		ans = 0;
		vector<int> edge[1001];
		vector<int> back[1001];
		vector<int> v, scc,scc_ix;
		int clan[1001] = { 0 };
		int indegree[1001] = { 0 };
		for (i = 0; i < M; i++){
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			back[b].push_back(a);
		}
		supply(0, edge, turn);
		for (i = 1; i <= N; i++) dfs(i, turn, edge, v);
		for (i = v.size() - 1; i >= 0; i--){
			dfs(v[i], -turn, back, scc);
			if (scc.size() == 0) continue;
			scc_ix.push_back(i);
			for (j = 0; j < scc.size(); j++){
				clan[scc[j]] = i;
			}
			for (j = 0; j < scc.size(); j++){
				a = scc[j];
				for (k = 0; k < edge[a].size(); k++){
					b = edge[a][k];
					if (water[b] == turn || clan[b] == i) continue;
					indegree[b]++;
				}
			}
			scc.clear();
			v[i] = 0;

		}
		for (i = 1; i <= N; i++){
			if (water[i] == turn) continue;
			v[clan[i]] += indegree[i];
		}
		for (i = 0; i < scc_ix.size(); i++){
			if (v[scc_ix[i]] == 0) ans++;
		}

		printf("%d\n", ans);
	}

	return 0;

}
