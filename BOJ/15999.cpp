//graph

#include <stdio.h>
#include <queue>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int dx[4] = {1,-1,0,0};
int dy[4] = { 0, 0, 1, -1 };
int grid[2002][2002];
bool visit[2001][2001];
int p2[2000 * 2000+1];
int pow2(int e){
	if (e == 0) p2[0]=1;
	if (p2[e]) return p2[e];
	if (e & 1){
		p2[e] = (pow2(e - 1)<<1);
		p2[e] %= mod;
	}
	else{
		ll half = pow2(e >> 1);
		p2[e] = half*half % mod;
	}
	return p2[e];
}
int bfs(int x,int y){
	if (visit[y][x]) return 0;
	queue<pair<int, int> >q;
	int clr = grid[y][x];
	int cnt = 0;
	q.push({x,y});
	visit[y][x] = true;
	while (q.size()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int adj = clr;
		for (int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (grid[ny][nx] == clr && visit[ny][nx] == 0) q.push({nx,ny}),visit[ny][nx]=true;
			adj |= grid[ny][nx];
		}
		cnt += (adj==clr);
	}
	return cnt;
}
int main(){
	int i, j;
	int N, M;
	ll ans = 1;
	char color;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i){
		for (j = 1; j <= M; ++j){
			scanf(" %c",&color);
			grid[i][j] = (color == 'B') + 1;
		}
	}
	for (i = 1; i <= N; ++i){
		for (j = 1; j <= M; ++j){
			int cnt = bfs(j,i);
			ans = ans*pow2(cnt) % mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
