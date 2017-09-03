//category : graph

#include <stdio.h>
#include <queue>
using namespace std;
int N;
int map[100][100];
int visit[100][100];
int bfs(int i, int j, int stamp){
	if (i < 0 || j < 0 || i >= N || j >= N) return 0;
	if (map[i][j] == stamp) return 0;
	if (map[i][j] != 0) return 2;
	map[i][j] = stamp;
	return 1;
}
bool dfs(int i, int j, int stamp){
	if (i < 0 || j < 0 || i >= N || j >= N) return false;
	if (map[i][j] != 1) return false;
	map[i][j] = stamp;
	dfs(i, j + 1, stamp);
	dfs(i, j - 1, stamp);
	dfs(i + 1, j, stamp);
	dfs(i - 1, j, stamp);
	return true;
}
int to1D(int i, int j, int n){
	return i*n+j;
}
int main(){
	int i, j;
	int res;
	int curr, level;
	int ans = 300;
	queue<pair<int, int> >q;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) visit[i][j] = -1;
			else q.push(make_pair(to1D(i,j,N), 1));
		}
	}
	res = 2;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (dfs(i, j, res)) res++;
		}
	}
	res = 0;
	curr = level = 1;
	while (!q.empty()){
		
		i = q.front().first/N;
		j = q.front().first % N;
		level = q.front().second;
		if (level != curr){
			if (ans != 300) break;
		}
		curr = level;
		//if (ans <= visit[i][j] + visit[i][j]) break;
		res = bfs(i, j + 1, map[i][j]);
		if (res == 1) q.push(make_pair(to1D(i,j+1,N),level+1)), visit[i][j + 1] = visit[i][j] + 1;
		if (res == 2){
			res = visit[i][j] + visit[i][j + 1];
			if (ans > res) ans = res;
			//break;
		}
		res = bfs(i, j - 1, map[i][j]);
		if (res == 1) q.push(make_pair(to1D(i, j - 1, N), level + 1)), visit[i][j - 1] = visit[i][j] + 1;
		if (res == 2){
			res = visit[i][j] + visit[i][j - 1];
			if (ans > res) ans = res;
			//break;
		}
		res = bfs(i + 1, j, map[i][j]);
		if (res == 1) q.push(make_pair(to1D(i+1, j, N), level + 1)), visit[i + 1][j] = visit[i][j] + 1;
		if (res == 2){
			res = visit[i][j] + visit[i + 1][j];
			if (ans > res) ans = res;
			//break;
		}
		res = bfs(i - 1, j, map[i][j]);
		if (res == 1) q.push(make_pair(to1D(i-1, j, N), level + 1)), visit[i - 1][j] = visit[i][j] + 1;
		if (res == 2){
			res = visit[i][j] + visit[i - 1][j];
			if (ans > res) ans = res;
			//break;
		}
		q.pop();
		res = 0;
	}
	if (ans == 300) ans = 0;
	printf("%d", ans);


	return 0;
}


