//category : graph, SPFA

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int d[41];
int visit[41];
int right[41];
bool in[41];
vector<pii > edge[41];
int main(){
	int i;
	int K, N;
	int x, y, r;
	queue<int> q;
	for (scanf("%d%d", &K, &N); N--;){
		scanf("%d%d%d",&x,&y,&r);
		edge[x - 1].push_back({ y, r });
		edge[y].push_back({ x-1, -r });
	}
	for (i = 1; i <= K; i++){
		edge[i - 1].push_back({ i, 1 });
		edge[i].push_back({ i-1, 0 });
	}
	//for (i = 0; i <= N; i++) q.push(i);
	for (i = 1; i <= K; i++) d[i] = 1e9;
	q.push(0);
	visit[0]++;
	while (q.size()){
		x = q.front();
		q.pop();
		in[x] = false;
		for (i = 0; i < edge[x].size(); i++){
			y = edge[x][i].first;
			r = edge[x][i].second;
			if (d[y] > d[x] + r){

				d[y] = d[x] + r;
				if (!in[y]){
					visit[y]++;
					q.push(y);
					in[y] = true;
				}
				if (visit[y] >= K){
					printf("NONE");
					return 0;
				}
			}
		}
	}
	for (i = 1; i <= K; i++) printf("%c",d[i]-d[i-1]? '#':'-');
	
	return 0;
}
