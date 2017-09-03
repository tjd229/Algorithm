//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int t = 0;
	int rt = 0;
	vector<int> edges;
	int indegree = 0;
	void construct(int currT){
		if (rt < currT) rt = currT;
	}
};
Node nodes[501];
int ans[501];
int main(){
	int N;
	int i;
	int u,v;
	queue<int> q;
	scanf("%d",&N);
	for (i = 1; i <= N; i++){
		scanf("%d",&v);
		nodes[i].t = v;
		while (true){
			scanf("%d", &u);
			if (u < 0) break;
			nodes[u].edges.push_back(i);
			nodes[i].indegree++;
		}
		if (nodes[i].indegree == 0) q.push(i);
	}

	while (!q.empty()){
		u = q.front();
		q.pop();
		ans[u] = nodes[u].t + nodes[u].rt;
		for (i = 0; i < nodes[u].edges.size(); i++){
			v = nodes[u].edges[i];
			nodes[v].indegree--;
			nodes[v].construct(ans[u]);
			if (nodes[v].indegree == 0) q.push(v);
		}
	}
	for (i = 1; i <= N; i++) printf("%d\n",ans[i]);



	return 0;
}