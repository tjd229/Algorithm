//category : graph

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
//int ans[101];
bool visit[101];
vector<int> edge[101];
//int dist[101][101];
int bfs(int ix){
	memset(visit,false,sizeof(visit));
	visit[ix] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(ix,0));
	int res = 0;
	int u, v, depth;
	int i;
	while (!q.empty()){
		u = q.front().first;
		depth = q.front().second;
		q.pop();
		res += depth;
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i];
			if (!visit[v]){
				visit[v] = true;
				q.push(make_pair(v,depth+1));
			}
		}
	}
	return res;
}
int main(){
	int i;
	int N, M;
	int A, B;
	int cnt = 10000;
	scanf("%d%d",&N,&M);
	while (M--){
		scanf("%d%d",&A,&B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	for (i = 1; i <= N; i++){
		B = bfs(i);
		if (cnt > B){
			cnt = B;
			A = i;
		}
	}
	printf("%d",A);
	return 0;
}