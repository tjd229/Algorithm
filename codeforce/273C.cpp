//graph

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
bool inq[300001];
int party[300001];
vector<int> edge[300001];

int main(){
	int i;
	int n, m;
	int a, b;
	queue<int> q;
	for (scanf("%d%d", &n, &m); m--; ){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= n; i++){
		int same = 0;
		for (int to : edge[i]) same += party[i] == party[to];
		if (same > 1) q.push(i),inq[i]=true;
	}
	while (q.size()){
		int ix = q.front();
		q.pop();
		inq[ix] = false;
		int same = 0;
		for (int to : edge[ix]) same += party[ix] == party[to];
		if (same>1)
			party[ix] ^= 1;
		for (int u : edge[ix]){
			if (inq[u]) continue;
			same = 0;
			for (int v : edge[u]){
				same += party[u] == party[v];
			}
			if (same > 1) q.push(u),inq[u]=true;
		}
		
	}
	for (i = 1; i <= n; i++) printf("%d",party[i]);
	

}
