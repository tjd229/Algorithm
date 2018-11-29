//graph

#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#define pii pair<int,int>
using namespace std;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
const int NM = 2000 * 2000;
vector<int> edge[NM];
int dange[NM];
int num[NM], low[NM], out[NM],from[NM];
char map[2002][2002];
int node[2002][2002];
bool vis[2002][2002];
int cnt, stk;
void ff(int x, int y){
	if (node[y][x]) return;
	node[y][x] = ++cnt;
	char src = map[y][x];
	queue<pii > q;
	q.push({ x, y });
	while (q.size()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i){
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (src == map[ny][nx] && !node[ny][nx]){
				q.push({ nx, ny });
				node[ny][nx] = cnt;
			}
		}
	}
}
void bfs(int x, int y){
	if (vis[y][x]) return;
	vis[y][x] = true;	
	int src = node[y][x];
	queue<pii > q;
	set<int> st;
	q.push({ x, y });
	while (q.size()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i){
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (src == node[ny][nx] && !vis[ny][nx]){
				q.push({ nx, ny });
				vis[ny][nx] = true;
			}
			else if (src != node[ny][nx]) st.insert(node[ny][nx]);
		}
	}
	for (auto it = st.begin(); it != st.end(); ++it) edge[src].push_back(*it);
}
void dfs(int x, bool is){
	//if (num[x] != 0) return 0;
	num[x] = low[x] = ++stk;
	bool ap = false;
	for (auto to : edge[x]){
		if (to == from[x]) continue;
		if (num[to] != 0){
			if (low[x]>num[to]) low[x] = num[to];
		}
		else{
			from[to] = x;
			dfs(to, is ^ 1);
			//++n;
			if (low[x] > low[to]) low[x] = low[to];
			if (from[x] != 0){
				if (num[x] <= low[to]) ap = true;
			}
		}
	}
	out[x] = stk;
	if (ap && is){
		for (auto to : edge[x]){
			//if (to == from) continue;
			if (num[x] <= low[to] && from[to]==x){
				dange[num[to]]++;
				dange[out[to] + 1]--;
			}
		}
	}
	//if (from == 0 && n > 1) ap[x] = true;
}


int main(){
	int i, j, k;
	int N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i){
		for (j = 1; j <= M; ++j) scanf(" %c", &map[i][j]);
	}
	for (i = 1; i <= N; ++i) for (j = 1; j <= M; ++j) ff(j, i);
	for (i = 1; i <= N; ++i) for (j = 1; j <= M; ++j) bfs(j, i);
	
	dfs(1, 0);
	for (i = 1; i <= cnt; ++i) dange[i] +=dange[i-1];
	for (i = 1; i <= N; ++i){
		for (j = 1; j <= M; ++j){
			if (map[i][j] == '#') printf("%c", dange[num[node[i][j]]] ? 'X' : 'O');
			else printf(".");
		}puts("");
	}
	return 0;
}
