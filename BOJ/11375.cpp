//category : graph, NF, dinic
//idea reference : http://blog.naver.com/kks227/220812858041
#include <stdio.h>
#include <vector>
#include <queue>
#define SRC 0
#define RIGHT 1000
#define SINK RIGHT+RIGHT+1
#define MIN(a,b) a<b? a:b
using namespace std;
struct Edge{
	int to;
	int cap;
	int r;
};
vector<Edge> edge[SINK+1];
int visit[SINK + 1];
int level[SINK + 1];
int iter[SINK + 1];
void add_edge(int u, int v, int cap){
	Edge e;
	edge[u].push_back(e);
	edge[v].push_back(e);
	Edge* fe = &edge[u][edge[u].size()-1];
	Edge* be = &edge[v][edge[v].size() - 1];
	fe->to = v;
	fe->cap = cap;
	fe->r = edge[v].size()-1;
	be->to = u;
	be->cap = 0;
	be->r = edge[u].size() - 1;
}
bool bfs(int stamp){
	visit[SRC] = stamp;
	queue<int> q;
	q.push(SRC);
	int ix;
	int i;
	Edge *next;
	while (!q.empty()){
		ix = q.front();
		q.pop();
		iter[ix] = 0;
		for (i = 0; i < edge[ix].size(); i++){
			next = &edge[ix][i];
			if (next->cap <= 0) continue;
			if (visit[next->to] != stamp){
				level[next->to] = level[ix] + 1;
				visit[next->to] = stamp;
				q.push(next->to);
			}
		}

	}
	return visit[SINK] == stamp;
}
int dfs(int ix, int f, int stamp){
	if (ix == SINK) return f;
	int res;
	Edge *next;
	for (int &i=iter[ix];i<edge[ix].size();i++){
		next = &edge[ix][i];
		if (next->cap <= 0) continue;
		if (level[ix] + 1 != level[next->to]) continue;
		res = dfs(next->to, MIN(f, next->cap), stamp);
		if (res){
			next->cap -= res;
			edge[next->to][next->r].cap += res;
			return res;
		}
	}
	return 0;
}
int flow(){
	int total = 0;
	int m = 0;
	int stamp = 1;
	while (bfs(stamp++)){
		
		do{
			m = dfs(SRC, 100, stamp++);
			total += m;
		} while (m != 0);
	}
	return total;
}
int main(){
	int i,j;
	int k;
	int job;
	int N, M;
	scanf("%d%d",&N,&M);
	for (i = 1; i <= N; i++){
		scanf("%d",&k);
		while (k--){
			scanf("%d",&job);
			add_edge(i,job+RIGHT,1);
		}
		add_edge(SRC, i, 1);
	}
	for (i = 1; i <= M; i++)
		add_edge(RIGHT+i,SINK,1);
	printf("%d",flow());

	return 0;
}