//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int n;
int s, t;
int m;
vector<int> c[101];
bool visit[101];
int ans = -1;
void dfs(int n,int level){
	int res = 0;
	
	if (visit[n]) return;
	visit[n] = true;
	if (n == t){
		ans = level;
		return;
	}
	for (int i = 0; i < c[n].size(); i++){
		dfs(c[n][i], level + 1);
	}
	
}
int main(){
	int i;
	int x, y;
	scanf("%d", &n);
	scanf("%d%d", &s,&t);
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		c[x].push_back(y);
		c[y].push_back(x);
	}
	dfs(s, 0);
	printf("%d",ans);
	return 0;
}

