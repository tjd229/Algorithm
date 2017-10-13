//category : graph
#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define MIN(a,b) a<b? a:b
using namespace std;
int n, m;
int s;
int k1, k2;
int bit[100];
vector<pii > edge[100];
int d1[1<<8], d2[1<<8];

void bfs(int ix,int *d){
	int in[100][1 << 8] = { 0 };
	int dist[100][1 << 8];
	int stat,next;
	int u, v, w;
	int i,j;
	queue<pii > q;
	q.push(mp(ix, bit[ix]));
	in[ix][bit[ix]]++;
	dist[ix][bit[ix]] = 0;
	while (!q.empty()){
		stat = q.front().second;
		u = q.front().first;
		q.pop();
		in[u][stat]++;
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i].second;
			w = edge[u][i].first;
			next = (stat | bit[v]);
			if (in[v][next] == 0 || dist[v][next]>dist[u][stat] + w){
				dist[v][next] = dist[u][stat] + w;
				if (in[v][next] != 1){
					q.push(mp(v, next));
					in[v][next] = 1;
				}
			}
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0, stat = 1 << s; j < stat; j++){
			if (i == 0) d[j] = s * 1001 * 2;
			if (in[i][j] == 0) continue;
			d[j] = MIN(d[j], dist[i][j]);
		}
	}
}


int main(){
	int i,j;
	int a, b, c;
	int all = 0;
	int ans = 0;
	for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
		scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(mp(c, b));
		edge[b].pb(mp(c, a));
	}
	for (scanf("%d", &s), i = 0; i < s; i++){
		scanf("%d",&a);
		bit[a] = 1 << i;
		all |= bit[a];
	}
	scanf("%d%d",&k1,&k2);
	ans = s * 1001 * 2;
	bfs(k1, d1);
	bfs(k2, d2);
	for (i = 0; i <= all; i++){
		for (j = 0; j <= all; j++){
			if ((i | j) == all)
				ans = MIN(ans, d1[i] + d2[j]);
		}
	}printf("%d",ans);

	return 0;
}
