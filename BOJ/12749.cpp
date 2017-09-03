//category : graph

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int visit[5001];
vector<int> edge[5001];
int n;
int min(int a, int b){
	if (a < 0) return b;
	if (b < 0) return a;
	return a > b ? b : a;
}
int bfs(int ix,int stamp){
	queue<pair<int, int> > q;
	q.push(make_pair(ix,1));
	int cnt = 1;
	int dist;
	int curr;
	int i;
	int res = 0;
	visit[ix] = stamp;
	while (!q.empty()){
		curr = q.front().first;
		dist = q.front().second;
		res += dist;
		q.pop();
		for (i = 0; i < edge[curr].size(); i++){
			if (visit[edge[curr][i]] != stamp){
				visit[edge[curr][i]] = stamp;
				q.push(make_pair(edge[curr][i], dist + 1));
				cnt++;
			}
		}
	}
	return cnt == n ? res : -1;
}
int main(){
	int i,j,k;
	int v;
	int ans = -1;
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d",&k);
		while (k--){
			scanf("%d",&v);
			edge[v].push_back(i);
		}
	}
	for (i = 1; i <= n; i++){
		ans = min(ans, bfs(i, i));
	}
	printf("%d",ans);
	return 0;
}