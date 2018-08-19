//graph, SCC

#include <stdio.h>
#include <vector>
using namespace std;
int a[200001];
int c[200001];
int ind[200001];
int visit[200001];
void mark(int x){
	if (visit[x] == 2) return;
	visit[x] = 2;
	mark(a[x]);
}
int dfs(int x){
	if (visit[a[x]] > 1) return -1;
	visit[x] = 1;
	if (visit[a[x]] == 1){
		//mark(a[x]);
		visit[x] = 2;
		return a[x];
	}
	//else if (visit[a[x]] > 1) return -1;
	int res= dfs(a[x]);
	visit[x] = 2;
	return res;
}
int cost(int x,int mn){
	visit[x] = 11;
	if (mn > c[x]) mn = c[x];
	if (visit[a[x]] == 11) return mn;
	return cost(a[x], mn);
}
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",c+i);
	}
	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
		ind[a[i]]++;
	}
	vector<int> v;
	for (i = 1; i <= n; i++){
		//if (ind[i] == 0){
			int sink = dfs(i);
			if (sink!=-1)
				v.push_back(sink);
		//}
	}
	long long tot = 0;
	for (auto x : v) tot += cost(x, 1e9);// , printf("!%d\n", x);
	printf("%I64d",tot);
	return 0;
}
