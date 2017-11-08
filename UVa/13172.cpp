//category : graph, dijkstra

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define mp make_pair
using namespace std;
int rural;
int visit[1001];
int village[1001];
ll d[1001][1001];
int nr, nv;

void dijkstra(int s, int stamp, vector<pii > edge[1001]){
	priority_queue<pli > q;
	int i;
	int u, v, w;
	q.push(mp(0,s));
	d[s][s] = 0;
	while (!q.empty()){
		u = q.top().second;
		q.pop();
		if (visit[u] == stamp) continue;
		visit[u] = stamp;
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i].first;
			w = edge[u][i].second;
			if (d[s][v]<0||d[s][v] > d[s][u] + w){
				d[s][v] = d[s][u] + w;
				q.push(mp(-d[s][v],v));
			}
		}
	}
}
int main(){
	int i;
	int u, v, w;
	int c;
	int stamp = 1;
	pli ans, p;
	ll dist;
	while (scanf("%d%d", &nv, &nr) == 2){
		vector<pii > edge[1001];
		memset(d,-1,sizeof(d));
		for (i = 0; i < nr; i++){
			scanf("%d%d%d",&u,&v,&w);
			edge[u].push_back(mp(v, w));
			edge[v].push_back(mp(u, w));
			
		}
		for (i = 1; i <= nv; i++)
			dijkstra(i,stamp++,edge);

		for (scanf("%d", &c); c--;){
			vector<int> assign;
			dist = 0;
			for (scanf("%d", &rural), i = 0; i < rural; i++){
				scanf("%d",&w);	
				assign.push_back(w);
				village[w]=stamp;
			}
			ans = mp(-1, 1001);
			sort(assign.begin(), assign.end());
			do{
				dist = 0;
				for (i = 1; i < assign.size(); i++)
					dist += d[assign[i - 1]][assign[i]];
				for (i = 1; i <= nv; i++){
					if (village[i] == stamp) continue;
					if (d[i][assign[0]] < 0) continue;
					if (d[assign.back()][i] < 0) continue;
					p = mp(dist+d[i][assign[0]]+d[assign.back()][i],i);
					if (ans.first<0 || ans>p) ans = p;
				}
			} while (next_permutation(assign.begin(), assign.end()));
			
			printf("%d %lld\n",ans.second,ans.first);
			stamp++;
		}
		printf("---\n");
	}

	return 0;
}