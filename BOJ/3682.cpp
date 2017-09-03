//category : graph, SCC, 2-SAT

#include <stdio.h>
#include <vector>
using namespace std;
int visit[20001];
bool dfs(int n,int stamp,vector<vector<int> > &edges){
	if (visit[n] == stamp) return false;
	visit[n] = stamp;
	for (int i = 0; i < edges[n].size(); i++)
		dfs(edges[n][i], stamp, edges);
	edges[0].push_back(n);
	return true;
}
int main(){
	int T;
	int n, m;
	int s1, s2;
	int num_scc;
	int i,j;
	for (scanf("%d", &T); T--;){
		scanf("%d%d",&n,&m);
		vector<vector<int> >edges(n + 1);
		vector<vector<int> >back(n + 1);
		vector<vector<int> >scc(n + 1);
		num_scc = 0;
		for (i = 0; i < m; i++){
			scanf("%d%d", &s1, &s2);
			edges[s1].push_back(s2);
			back[s2].push_back(s1);
		}
		for (i = 1; i <= n; i++) dfs(i, T + 1, edges);		
		for (i = edges[0].size() - 1; i >= 0; i--){
			if (dfs(edges[0][i], -(T + 1), back)){
				for (j = 0; j < back[0].size(); j++)
					scc[num_scc].push_back(back[0][j]);
				back[0].clear();
				num_scc++;
			}
		}
		if (num_scc == 1){
			printf("0\n");
			continue;
		}
		for (i = 0; i < num_scc; i++){
			for (j = 0; j < scc[i].size(); j++)
				visit[scc[i][j]] = 200 + i;
		}
		int in[20001] = { 0 };
		int out[20001] = { 0 };
		
		for (i = 1; i <= n; i++){
			for (j = 0; j < edges[i].size(); j++){
				if (visit[i] != visit[edges[i][j]]){
					out[visit[i] - 200]++;
					in[visit[edges[i][j]] - 200]++;
				}
			}
		}
		for (i = 0; i < num_scc; i++){
			if (in[i] == 0) in[20000]++;
			if (out[i] == 0) out[20000]++;
		}
		printf("%d\n", in[20000]<out[20000] ? out[20000] : in[20000]);
	}

	return 0;
}
