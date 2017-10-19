//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
int cnt;
int num[100001];
int ind[100001];
vector<int> edge[100001];
bool bfs(queue<int> &q){
	int i;
	int curr,to;
	while (!q.empty()){
		curr = q.front();
		q.pop();
		for (i = 0; i < edge[curr].size(); i++){
			to = edge[curr][i];
			ind[to]--;
			if (ind[to] == 0){
				num[to] = ++cnt;
				q.push(to);
			}
		}

	}
}
int main(){
	bool possible = true;
	int N, M1, M2;
	int A, B;
	int i;
	queue<int> q;


	for (scanf("%d%d%d", &N, &M1, &M2), i = 0; i < M1; i++){
		scanf("%d%d",&A,&B);
		edge[A].pb(B);
		ind[B]++;
	}
	for (i = 1; i <= N; i++) if (ind[i] == 0) q.push(i), num[i]=++cnt;
	bfs(q);
	possible = (N == cnt);
	while (M2--){
		scanf("%d%d",&A,&B);
		if (possible){
			if (num[A] < num[B]) printf("%d %d\n", A, B);
			else printf("%d %d\n", B,A);
		}
	}
	if (!possible) printf("-1");
	return 0;
}