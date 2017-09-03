//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int visit[101];
pair<int, int> bfs(int s, int stamp, vector<int> edge[101]){
	vector<int> q;
	int i;
	int u;
	int curr, end;
	int res;
	int turn = -1;
	q.push_back(s);
	visit[s] = stamp;
	curr = 0;
	end = q.size();
	while (curr < end){
		res = q[curr];
		for (; curr < end; curr++){
			u = q[curr];
			for (i = 0; i < edge[u].size(); i++){
				if (visit[edge[u][i]] != stamp){
					visit[edge[u][i]] = stamp;
					q.push_back(edge[u][i]);
				}
			}
		}
		end = q.size();
		turn++;
	}
	return make_pair(res, turn);
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	int beads;
	int u, v;
	int dist = 0;
	pair<int, int> p;
	scanf("%d", &n);
	while (n--){
		vector<int> edge[101];
		scanf("%d", &beads);
		while (--beads){
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		p = bfs(1, n + 1, edge);
		p = bfs(p.first, -n - 1, edge);
		dist += p.second;

	}
	printf("%d\n", dist);
	return 0;
}