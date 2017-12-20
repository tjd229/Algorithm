//category : graph, tp sort, dijkstra

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
struct Edge{
	int v;
	int cost;
	int ix;
};
int ld[50001], sd[50001];
int ind[50001];
int p[50001];
int visit[50001];
vector<Edge> edge[50001];
vector<pii > ans;
int N, R;
void dijkstra(int stamp){
	priority_queue<pii > pq;
	sd[1] = 0;
	pq.push({0,1});
	int i;
	int curr,to,cost;
	while (!pq.empty()){
		curr = pq.top().second;
		pq.pop();
		if (visit[curr] == stamp) continue;
		visit[curr] = stamp;
		for (i = 0; i < edge[curr].size(); i++){
			to = edge[curr][i].v;
			cost = edge[curr][i].cost;
			if (sd[to]>sd[curr] + cost){
				sd[to] = sd[curr] + cost;
				pq.push({-sd[to],to});
			}
		}
	}
}
void dfs(int ix,int stamp){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	int to;
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i].v;
		dfs(to, stamp);
		if (ix!=1){
			int t = ld[to] > sd[to] + p[to] ? ld[to] : sd[to] + p[to];
			int offset = t - sd[ix]-edge[ix][i].cost;
			if (p[ix] < offset) p[ix] = offset;
		}

	}
}
bool tp_sort(){
	
	vector<int> q;
	q.push_back(1);
	ld[1] = 0;
	int curr, to,cost;
	int i,j;
	for (i = 0; i < q.size(); i++){
		curr = q[i];
		for (j = 0; j < edge[curr].size(); j++){
			to = edge[curr][j].v;
			cost = edge[curr][j].cost;
			if (ld[to] < ld[curr] + cost)
				ld[to] = ld[curr] + cost;
			if (--ind[to] == 0)
				q.push_back(to);
		}
	}
	dfs(1,-1);
	for (i = 0; i < q.size(); i++){
		curr = q[i];
		if (sd[curr] != ld[curr]) sd[curr] += p[curr];
		for (j = 0; j < edge[curr].size(); j++){
			to = edge[curr][j].v;
			cost = edge[curr][j].cost;
			if (ld[to] != sd[to]){
				int t = ld[to] > sd[to] + p[to] ? ld[to] : sd[to] + p[to];
				int offset = t - sd[curr] - edge[curr][j].cost;
				if (offset < 0) return false;
				if (offset>0)
					ans.push_back({edge[curr][j].ix,offset});

			}
		}

	}
	return true;
}
int main(){
	int i,j;
	int x, y, c;
	int tc=0;
	while (scanf("%d%d", &N, &R)){
		if (N == 0 && R == 0) break;
		ans.clear();
		printf("Case %d: ",++tc);
		for (i = 1; i <= N; i++){
			edge[i].clear();
			ld[i] = 0;
			sd[i] = 1e9;
			ind[i] = 0;
			p[i] = 0;
		}
		ld[1] = sd[1] = 0;//
		for (i = 1; i <= R; i++){
			scanf("%d%d%d",&x,&y,&c);
			edge[x].push_back({y,c,i});
			ind[y]++;
		}
		dijkstra(tc);
		if (!tp_sort()){
			printf("No solution\n");
			continue;
		}
		
		printf("%d %d\n",ans.size(),ld[N]);
		for (i = 0; i < ans.size(); i++)
			printf("%d %d\n",ans[i].first,ans[i].second);

		
	}


	return 0;
}