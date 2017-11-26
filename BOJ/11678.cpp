//category : graph, SCC, 2-SAT

#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int N;
int visit[105];
struct Invest{
	int c1, c2;
	int player;
	int rep;
}inv[50];
void add_edge(int u, int v, vector<int> edge[105]){
	if (u < 0) u = 52 - u;
	if (v < 0) v = 52 - v;
	edge[u].push_back(v);
}
void dfs(int ix, int stamp, vector<int> edge[105]){
	//printf("!%d\n",ix);
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], stamp, edge);
	edge[0].push_back(ix);
}
bool check(vector<int> &v){
	if (v.size() == 0) return true;
	int cnt[53] = { 0 };
	int x;
	for (int i = 0; i < v.size(); i++){
		x = v[i];
		if (x > 52) x -= 52;
		cnt[x]++;
		if (cnt[x] > 1) return false;
	}
	return true;
}
bool sat(int s1, int s2, int s3, int &stamp){
	int i, j;
	int u, v;
	vector<int> edge[105];
	vector<int> back[105];
	for (i = 0; i < N; i++){
		u = 26 * (inv[i].player - 1) + inv[i].c1;
		v = 26 * (inv[i].player - 1) + inv[i].c2;
		if (inv[i].rep == 1){
			add_edge(-u, v, edge);
			add_edge(-v, u, edge);
			add_edge(v, -u, back);
			add_edge(u, -v, back);
			add_edge(-u, v, back);
			add_edge(-v, u, back);
			add_edge(v, -u, edge);
			add_edge(u, -v, edge);
		}
		else if (inv[i].rep == 2){
			add_edge(-u, u, edge);
			add_edge(-v, v, edge);
			add_edge(u, -u, back);
			add_edge(v, -v, back);
			u = 26 * ((inv[i].player^3) - 1) + inv[i].c1;
			v = 26 * ((inv[i].player^3) - 1) + inv[i].c2;
			add_edge(-u, u, back);
			add_edge(-v, v, back);
			add_edge(u, -u, edge);
			add_edge(v, -v, edge);
		}
		else{
			add_edge(-u, u, back);
			add_edge(-v, v, back);
			add_edge(u, -u, edge);
			add_edge(v, -v, edge);
		}
	}
	for (i = 1; i <= 26; i++){
		if (i == s1 || i == s2 || i == s3){
			add_edge(i, -i, edge);
			add_edge(i + 26, -i - 26, edge);
			add_edge(-i,i, back);
			add_edge(-i - 26, i+26,back);
		}
		else{
			add_edge(-i, i + 26, edge);
			add_edge(-i - 26, i, edge);
			add_edge(i + 26, -i, back);
			add_edge(i, -i - 26, back);
			add_edge(-i, i + 26, back);
			add_edge(-i - 26, i, back);
			add_edge(i + 26, -i, edge);
			add_edge(i, -i - 26, edge);
		}
	}
	for (i = 1; i <105; i++) dfs(i, stamp, edge);
	stamp++;
	for (i = edge[0].size() - 1; i >= 0; i--){
		//printf("%d ",edge[0][i]);
		dfs(edge[0][i], stamp, back);
		if (!check(back[0])) return false;
		back[0].clear();
	}


	return true;

}
int main(){
	int i, j, k;
	int ans = 0;
	char c1, c2;
	int player, reply;
	int stamp = 0;
	
	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf(" %c%c%d%d", &c1, &c2, &player, &reply);
		inv[i] = { c1 - 'A' + 1, c2 - 'A' + 1, player, reply };
	}
	for (i = 1; i <= 26; i++){
		for (j = i + 1; j <= 26; j++){
			for (k = j + 1; k <= 26; k++){
				if (sat(i, j, k, ++stamp))
					ans++;
				//return 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
