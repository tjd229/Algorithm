//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int indgree=0;
	vector<int> edges;
	int time=0;
	int rTime=0;
	void propagate(int t){
		if (rTime < t) rTime = t;
	}
};
Node graph[10001];
int main(){

	int N;
	queue<int> q;
	int i, j,k;
	int buff;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d%d", &j, &k);
		graph[i].time = j;
		graph[i].indgree= k;
		for (j = 0; j < k; j++){
			scanf("%d",&buff);
			graph[buff].edges.push_back(i);
		}
		if (graph[i].indgree == 0) q.push(i);
	}
	buff = 0;
	while (!q.empty()){
		k = q.front();
		q.pop();
		for (i = 0; i < graph[k].edges.size(); i++){
			j = graph[k].edges[i];
			graph[j].indgree--;
			graph[j].propagate(graph[k].rTime+graph[k].time);
			if (graph[j].indgree == 0) q.push(j);
		}
		if (graph[k].edges.size() == 0 && buff < graph[k].rTime + graph[k].time)
			buff = graph[k].rTime + graph[k].time;

	}
	printf("%d",buff);

	return 0;
}

