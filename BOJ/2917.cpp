//category : graph, bs



#include <iostream>
#include <string>
#include <queue>
using namespace std;
string forest[500];
struct Grid{
	int x, y;
};
queue < pair<Grid, int> >q;
int s_x, s_y, e_x, e_y;
int dist[500][500];
int visit[500][500];
int N, M;
int l, r;
void update(int x, int y, int d, int stamp){
	if (x < 0 || y < 0 || x >= M || y >= N) return;
	if (visit[y][x] != stamp){
		visit[y][x] = stamp;
		dist[y][x] = d;
		Grid g;
		g.x = x;
		g.y = y;
		q.push(make_pair(g, d));
	}
}
void bfs(int stamp){
	int to;
	int x,y;
	int d;
	while (!q.empty()){
		x = q.front().first.x;
		y = q.front().first.y;
		d = q.front().second;
		if (r < d) r = d;
		q.pop();
		update(x + 1, y, d+1, stamp);
		update(x - 1, y, d+1, stamp);
		update(x, y + 1, d+1, stamp);
		update(x, y - 1, d+1, stamp);
	}
}
bool dfs(int x,int y,int mid,int stamp){
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	if (visit[y][x] == stamp) return false;
	if (dist[y][x] < mid) return false;
	visit[y][x] = stamp;
	if (e_x==x&&e_y==y) return true;
	
	if (dfs(x + 1, y, mid, stamp)) return true;
	if (dfs(x - 1, y, mid, stamp)) return true;
	if (dfs(x, y + 1, mid, stamp)) return true;
	if (dfs(x, y - 1, mid, stamp)) return true;
	return false;
}
int main(){
	int i, j;
	int mid;
	int ans = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++){
		cin >> forest[i];
		for (j = 0; j < M; j++){
			if (forest[i][j] == '+'){
				Grid g;
				g.x = j;
				g.y = i;
				q.push(make_pair(g,0));
				visit[i][j] = 1;
			}
			if (forest[i][j] == 'V') s_x = j, s_y = i;
			if (forest[i][j] == 'J') e_x = j, e_y = i;
		}
	}
	bfs(1);
	i = 1;
	while (l<=r){
		mid = (l + r) >> 1;
		if (dfs(s_x, s_y, mid, ++i)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	/*for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			cout << dist[i][j]<<" ";
		}cout << endl;
	}*/

	return 0;
}