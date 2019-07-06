//graph
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
struct Tuple { int x, y, z; };
vector<Tuple> ans;
vector<pii > edge[1001];
vector<int > leaf[1001];
int root = 1;
void dfs(int x,int from) {
	for (auto p : edge[x]) {
		int to = p.first;
		if (to == from) continue;
		dfs(to,x);
		leaf[x].push_back(leaf[to][0]);
	}
 
	if (edge[x].size() == 1 && root!=x) leaf[x].push_back(x);//+root 
	else {
		for (auto p : edge[x]) {
			int to = p.first;
			int val = p.second;
			if (to == from) continue;
			if (val == 0) continue;
			if (edge[to].size() == 1) 
				ans.push_back({root,to,val});
			else {
				ans.push_back({ root,leaf[to][0],val >> 1 });
				ans.push_back({ root,leaf[to][1],val >> 1 });
				ans.push_back({ leaf[to][0],leaf[to][1],-(val >> 1) });
			}
			if (x != root) {
				val = -val;
				ans.push_back({ root,leaf[x][0],val >> 1 });
				ans.push_back({ root,leaf[x][1],val >> 1 });
				ans.push_back({ leaf[x][0],leaf[x][1],-(val >> 1) });
			}
		}
	}
 
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v,val; scanf("%d%d%d",&u,&v,&val);
		edge[u].push_back({v,val});
		edge[v].push_back({ u,val });
	}
	for (i = 1; i <= n; ++i) {
		if (edge[i].size() == 2) {
			printf("NO");
			return 0;
		}
		else if (edge[i].size() == 1) root = i;
	}
	dfs(root, 0);
	for (printf("YES\n%d\n", ans.size()), i = 0; i < ans.size(); ++i)
		printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
 
	return 0;
}