//graph

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[200001];
int depth[200001];
int from[200001];
int a[200001];
bool check[200001];
void dfs(int ix, int d){
	depth[ix] = d;
	for (auto v : edge[ix]){
		if (depth[v] == 0){
			from[v] = ix;
			dfs(v, d + 1);
		}
	}
}
int main(){
	int i,j,k;
	int n;
	int x, y;
	bool ans = true;
	for (scanf("%d", &n), i = 1; i < n; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 1);
	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
		if (depth[a[i]] < depth[a[i - 1]]) ans = false;
	}
	if (ans){
		int ix = 1;
		for (i = 2; i <= n; i++){
			int p = from[a[i]];
			if (check[p]) continue; //second q visit
			check[p] = true;
			while (ix>1 && a[ix]!=0 && edge[a[ix]].size() == 1) ix++;
			for (j = k=0; j < edge[p].size(); j++){
				if (edge[p][j] == from[p]){
					continue;
				}
				if (from[a[i + k]] != p || from[a[i + k]] != a[ix]) ans = false;
				++k;
			}
			++ix; //second q
			
		}
	}
	
	printf("%s",ans? "Yes":"No");
	return 0;
}
