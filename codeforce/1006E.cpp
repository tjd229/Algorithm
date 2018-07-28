//graph

#include <stdio.h>
#include <vector>

using namespace std;
vector<int> edge[200001];
vector<int> order;
int pre[200001],post[200001];
int cnt;
void dfs(int ix){
	order.push_back(ix);
	pre[ix] = ++cnt;
	for (int to:edge[ix]) dfs(to);
	post[ix] = cnt;
}
int main(){
	int i;
	int n, q;
	int u, k;
	int p;
	for (scanf("%d%d", &n, &q), i = 2; i <= n; i++){
		scanf("%d",&p);
		edge[p].push_back(i);
	}
	order.push_back(-1);
	dfs(1);

	while (q--){
		scanf("%d%d",&u,&k);
		int kth = pre[u] + k - 1;
		if (kth <= n){
			int knode = order[kth];
			if (pre[knode] <= post[u]) printf("%d\n",knode);
			else printf("-1\n");
		}
		else printf("-1\n");
	}
	return 0;
}
