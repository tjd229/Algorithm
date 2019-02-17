//graph
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
vector<int> edge[123457];
ll a[123457];
int vis[123457];
void dfs(int x) {
	vis[x] = 1;
	for (auto v : edge[x]) {
		if (vis[v] == 0) {
			dfs(v);
			a[x] += a[v];
		}
	}
	if (a[x] < 0) a[x] = 0;
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 2; i <= N; ++i) {
		char t;
		int p;
		scanf(" %c%lld%d",&t,a+i,&p);
		if (t == 'W') a[i] = -a[i];
		edge[p].push_back(i);
		edge[i].push_back(p);
	}
	dfs(1);
	printf("%lld",a[1]);
	return 0;
}