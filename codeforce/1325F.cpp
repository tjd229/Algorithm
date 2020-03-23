//graph, greedy
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> indp;
vector<int> edge[100001];
bool ban[100001];
int depth[100001];
int from[100001];
int sq;
int head, tail;
void dfs(int x) {
	bool leaf = 1;
	for (auto y : edge[x]) {
		if (from[x] == y) continue;
		if (depth[y] == 0) {
			depth[y] = depth[x] + 1;
			from[y] = x;
			dfs(y);
			leaf = 0;
		}
		else if(depth[x]-depth[y]+1>=sq){//bk_edge
			tail = x;
			head = y;
		}
	}
	if (leaf) 
		indp.push_back(x);
 
}
int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 0; i < m; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	while (sq*sq < n) ++sq;
	depth[1] = 1;
	dfs(1);
	if (tail + head) {
		printf("2\n%d\n%d ",depth[tail]-depth[head]+1,head);
		while (tail != head) {
			printf("%d ",tail);
			tail = from[tail];
		}
	}
	else {
		for (auto x : indp) {
			ban[x] = 1;
			for (auto y : edge[x]) ban[y] = 1;
		}
		for (i = 0; i < indp.size() && indp.size() < sq; ++i) {
			int x = indp[i];
			while (x) {
				if (ban[x] == 0) {
					ban[x] = 1;
					indp.push_back(x);
					for (auto y : edge[x]) ban[y] = 1;
				}
				int p = from[x];
				from[x] = 0;
				x = p;
			}
		}
		
		for (printf("1\n"), i = 0; i < sq; ++i) printf("%d ",indp[i]);
		//for (auto x : indp) printf("%d ",x);
	}
	return 0;
}