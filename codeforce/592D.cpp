//category : graph

#include <stdio.h>
#include <vector>
#define SEARCH 1
#define GO 2
using namespace std;

vector<int> edge[123457];
int visit[123457];
int defend[123457];
int bfs(int s,int stamp){
	vector<int> q;
	int i;
	int u;
	int curr, end;
	int res;
	q.push_back(s);
	visit[s] = stamp;
	curr = 0;
	end = q.size();
	while (curr != end){
		res = q[curr];
		for (; curr < end; curr++){
			u = q[curr];
			for (i = 0; i < edge[u].size(); i++){
				if (visit[edge[u][i]] != stamp&&defend[edge[u][i]] == SEARCH){
					visit[edge[u][i]] = stamp;
					q.push_back(edge[u][i]);
				}
			}
			if (res>q[curr]) res = q[curr];
		}
		end = q.size();
	}
	return res;
}
int dfs(int ix,int stamp){
	if (defend[ix] == GO) return 0;
	if (visit[ix] == stamp) return -1;
	visit[ix] = stamp;	
	int res;
	for (int i = 0; i < edge[ix].size(); i++){
		res = dfs(edge[ix][i], stamp);
		if (res>=0){
			defend[ix] = GO;
			return res + 1;
		}
	}
	return -1;
}
bool make_tree(int ix,int stamp){
	if (visit[ix] == stamp) return 0;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++){
		if (make_tree(edge[ix][i], stamp)) defend[ix] = SEARCH;
	}
	return defend[ix];
}
int main(){
	int n,m;
	int u, v;
	vector<int> attacked;
	int i;
	scanf("%d%d",&n,&m);
	while (--n){
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	while (m--){
		scanf("%d",&u);
		attacked.push_back(u);
		defend[u] = SEARCH;
	}
	make_tree(attacked[0],1);
	u = bfs(attacked[0], 2);
	v = bfs(u, 3);
	defend[v] = GO;
	m = dfs(u,4);
	for (i = 0; i < attacked.size(); i++){
		n = dfs(attacked[i],5+i);
		if (n>0)
			m += n + n;
	}
	printf("%d\n",u<v? u:v);
	printf("%d\n",m);
	return 0;
}