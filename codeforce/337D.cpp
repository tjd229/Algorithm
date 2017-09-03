//category : graph



#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[100001];
vector<int> p;
int visit[100001];
int cm[2][100001];
bool attacked[100001];
int n, m, d;
int bfs(int s, int stamp){
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
				if (visit[edge[u][i]] != stamp&&attacked[edge[u][i]]){
					visit[edge[u][i]] = stamp;
					q.push_back(edge[u][i]);
				}
			}
		}
		end = q.size();
	}
	return res;
}
int dfs(int ix, int to, int stamp, int d){
	if (ix == to) return d;
	if (visit[ix] == stamp) return 0;
	visit[ix] = stamp;
	int e = 0;
	int res;
	for (int i = 0; i < edge[ix].size(); i++){
		res = dfs(edge[ix][i], to, stamp, d + 1);
		if (e < res) e = res;
	}
	return e;
}
void centemeter(int ix,int stamp,int depth,int xy){
	//if (depth > d) return;
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	cm[xy][ix] = depth;
	for (int i = 0; i < edge[ix].size(); i++){
		centemeter(edge[ix][i], stamp, depth + 1, xy);
	}
}
bool make_tree(int ix, int stamp){
	if (visit[ix] == stamp) return 0;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++){
		if (make_tree(edge[ix][i], stamp)) attacked[ix] = true;
	}
	return attacked[ix];
}
int main(){
	int a, b;
	int x, y;
	int ans = 0;
	int i,j;
	bool flag;
	scanf("%d%d%d",&n,&m,&d);
	for (i = 0; i < m; i++){
		scanf("%d",&a);
		p.push_back(a);
		attacked[a] = true;
	}
	for (i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	make_tree(p[0],1);
	if (p.size() == 1){
		centemeter(p[0],2,0,0);
		for (i = 1; i <= n; i++) if (d >= cm[0][i]) ans++;
		printf("%d",ans);
		return 0;
	}
	x = bfs(p[0],2);
	y = bfs(x, 3);
	if (dfs(x, y, 4, 0) > d + d){
		printf("0");
		return 0;
	}
	centemeter(x, 5, 0, 0);
	centemeter(y, 6, 0, 1);
	for (i = 1; i <= n; i++){
		if (cm[0][i] <= d&&cm[1][i] <= d) ans++;
	}
	printf("%d",ans);
	return 0;
}