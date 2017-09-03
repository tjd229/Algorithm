//category : graph

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int N;
int NN;
bool visit[125 * 125];
int d[125 * 125];
int cave[125 * 125];
vector<pair<int, int> > edge[125 * 125];
int to1D(int x, int y){
	return x + y*N;
}
void dijkstra(int s){
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0,s));
	d[s] = 0;
	int i;
	int u, v, w;
	while (!q.empty()){
		u = q.top().second;
		q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i].first;
			w = edge[u][i].second;
			if (d[v]>d[u] + w){
				d[v] = d[u] + w;
				q.push(make_pair(-d[v], v));
			}
		}
	}
}
int main(){
	int tc = 1;
	int i, j;
	scanf("%d",&N);
	while (N != 0){
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				scanf("%d",&cave[to1D(j,i)]);
				edge[to1D(j, i)].clear();
				d[to1D(j, i)] = 125 * 125 * 100;
				visit[to1D(j, i)] = false;
			}
		}
		int u, v;
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				u = to1D(j, i);
				v = to1D(j + 1, i);
				if (j < N - 1)
					edge[u].push_back(make_pair(v, cave[v]));
				v = to1D(j - 1, i);
				if (j >0)
					edge[u].push_back(make_pair(v, cave[v]));
				v = to1D(j, i + 1);
				if (i<N - 1)
					edge[u].push_back(make_pair(v, cave[v]));
				v = to1D(j, i - 1);
				if (i>0)
					edge[u].push_back(make_pair(v, cave[v]));
			}
		}
		dijkstra(0);
		printf("Problem %d: %d\n",tc++,d[N*N-1]+cave[0]);
		scanf("%d", &N);
	}
	
	return 0;
}

