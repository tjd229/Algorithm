//category : graph, dijkstra



#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int> > edge[100001];
long long d[100001];
bool train[100001];
int cnt_train[100001];
//vector<int> train[100001];
void dijkstra(){
	int i;
	int curr;
	int to;
	long long pre_d;
	bool on_train;
	priority_queue<pair<long long, int> > q;
	q.push(make_pair(0, 1));
	while (!q.empty()){
		curr = q.top().second;
		pre_d = -q.top().first;
		q.pop();
		if (d[curr] != pre_d) continue;
		for (i = 0; i < edge[curr].size(); i++){
			to = edge[curr][i].second;
			on_train= false;
			if (to == 1) continue;
			if (to<0){
				to = -to;
				on_train = true;
			}
			if (train[to] && d[to] == d[curr] + edge[curr][i].first&&!on_train)
				train[to] = on_train;
			if (d[to] == 0 || d[to] > d[curr] + edge[curr][i].first){
				d[to] = d[curr] + edge[curr][i].first;
				q.push(make_pair(-d[to], to));
				train[to] = on_train;
			}
		}
	}
}
int main(){
	int i,j;
	int n, m, k;
	int u, v, x;
	int s, y;
	int closed = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &x);
		edge[u].push_back(make_pair(x, v));
		edge[v].push_back(make_pair(x, u));
	}
	//dijkstra();
	for (i = 0; i < k; i++){
		scanf("%d%d", &s, &y);
		edge[1].push_back(make_pair(y, -s));

		cnt_train[s]++;
	}
	dijkstra();
	for (i = 2; i <= n; i++){
		k -= train[i];
	}
	printf("%d", k);

	return 0;
}