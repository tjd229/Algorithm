//category : graph, dijkstra

#include <stdio.h>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
struct Edge{
	int a,b,s;
	bool strike;
	vector<int> impact;
	int to(int ix){
		return a == ix ? b : a;
	}
}path[1000];
int visit[101];
int n, m, L;
ll c[101];
ll dijkstra(int ix, int stamp, pair<int,int> *from,const vector<int> *edge){
	ll d[101] = { 0 };
	priority_queue<pair<ll, int> > q;
	q.push({0,ix});
	//from[0] = { -1, -1 };
	int curr, to,cost;
	int i;
	while (!q.empty()){
		curr = q.top().second;
		q.pop();
		if (visit[curr] == stamp) continue;
		visit[curr] = stamp;
		for (i = 0; i < edge[curr].size(); i++){
			if (path[edge[curr][i]].strike) continue;
			to = path[edge[curr][i]].to(curr);
			cost = path[edge[curr][i]].s;
			if ((visit[to] != stamp&&d[to] == 0)
				|| d[to]>d[curr] + cost){
				d[to] = d[curr] + cost;
				q.push({-d[to],to});
				if (from!=NULL)
					from[to] = { curr, i };
			}
		}
	}
	ll res = 0;
	for (i = 1; i <= n; i++) res += stamp == visit[i] ? d[i] : L;
	return res;
}
int main(){
	int i,j;
	int stamp=0;
	ll ans1,ans2, c_;
	while (scanf("%d%d%d", &n, &m, &L) == 3){
		vector<int> edge[101];
		ans1 =ans2= 0;
		for (i = 0; i < m; i++){
			scanf("%d%d%d", &path[i].a, &path[i].b, &path[i].s);
			path[i].strike = false;
			path[i].impact.clear();
			edge[path[i].a].push_back(i);
			edge[path[i].b].push_back(i);
		}
		for (i = 1; i <= n; i++){
			pair<int, int> from[101];
			c[i] = dijkstra(i,++stamp,from,edge);
			for (j = 1; j <= n; j++){
				if (j == i) continue;
				if (stamp != visit[j]) continue;
				path[edge[from[j].first][from[j].second]].impact.push_back(i);
			}
			ans1 += c[i];
		}
		for (i = 0; i < m; i++){
			c_ = ans1; 
			auto pt = &path[i].impact;
			path[i].strike = true;
			for (j = 0; j < pt->size(); j++){
				c_ -= c[pt->at(j)];
				c_ += dijkstra(pt->at(j),++stamp,NULL,edge);
			}
			path[i].strike = false;
			if (ans2 < c_) ans2 = c_;
		}
		printf("%lld %lld\n",ans1,ans2);
	}

	return 0;
}
