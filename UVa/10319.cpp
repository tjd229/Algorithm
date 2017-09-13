//Manhattan
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1260
//category : 2-SAT, graph, SCC

#include <stdio.h>
#include <vector>
#define NOT 60
using namespace std;
//const int not = 60;
int visit[1 + NOT + NOT];
void dfs(int ix, int stamp, vector<int> edge[1 + NOT + NOT]){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], stamp, edge);
	edge[0].push_back(ix);
}
void add_edge(int u, int v, vector<int> edge[1 + NOT + NOT]){
	if (u < 0) u = NOT - u;
	if (v < 0) v = NOT - v;
	edge[u].push_back(v);
}
int sign(int a){
	if (a > 0) return 1;
	if (a < 0) return -1;
	return 0;
}
bool check(vector<int> &v){
	if (v.size() <= 1) return true;

	int record[NOT + 1] = { 0 };
	for (int i = 0; i < v.size(); i++){
		if (v[i] > NOT) v[i] %= NOT;
		if (record[v[i]] != 0) return false;
		record[v[i]]++;
	}
	return true;
}
int main(){
	int n;
	int S, A, m;
	int s1, a1, s2, a2;
	int i;
	bool ans;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (scanf("%d", &n); n--;){
		ans = true;
		vector<int> edge[1 + NOT + NOT], back[1 + NOT + NOT];
		scanf("%d%d%d", &S, &A, &m);
		
		while (m--){
			scanf("%d%d%d%d", &s1, &a1, &s2, &a2);
			a1 += 30;
			a2 += 30;
			if (s1 == s2&&a1 == a2) continue;
			else if (s1 == s2){
				add_edge(-s1*sign(a2 - a1), s1*sign(a2 - a1), edge);
				add_edge(s1*sign(a2 - a1), -s1*sign(a2 - a1), back);
			}
			else if (a1 == a2){
				add_edge(-a1*sign(s2 - s1), a1*sign(s2 - s1), edge);
				add_edge(a1*sign(s2 - s1), -a1*sign(s2 - s1), back);
			}
			else{
				add_edge(-a1*sign(s2 - s1), s1*sign(a2 - a1), edge);
				add_edge(-a1*sign(s2 - s1), a2*sign(s2 - s1), edge);
				add_edge(s1*sign(a2 - a1), -a1*sign(s2 - s1), back);
				add_edge(a2*sign(s2 - s1), -a1*sign(s2 - s1), back);

				add_edge(-s2*sign(a2 - a1), s1*sign(a2 - a1), edge);
				add_edge(-s2*sign(a2 - a1), a2*sign(s2 - s1), edge);
				add_edge(s1*sign(a2 - a1), -s2*sign(a2 - a1), back);
				add_edge(a2*sign(s2 - s1), -s2*sign(a2 - a1), back);

				add_edge(-a2*sign(s2 - s1), s2*sign(a2 - a1), edge);
				add_edge(-a2*sign(s2 - s1), a1*sign(s2 - s1), edge);
				add_edge(s2*sign(a2 - a1), -a2*sign(s2 - s1), back);
				add_edge(a1*sign(s2 - s1), -a2*sign(s2 - s1), back);

				add_edge(-s1*sign(a2 - a1), s2*sign(a2 - a1), edge);
				add_edge(-s1*sign(a2 - a1), a1*sign(s2 - s1), edge);
				add_edge(s2*sign(a2 - a1), -s1*sign(a2 - a1), back);
				add_edge(a1*sign(s2 - s1), -s1*sign(a2 - a1), back);
			}
		}
		
		for (i = 1; i <= S; i++) dfs(i, n + 1, edge), dfs(NOT + i, n + 1, edge);
		for (i = 1; i <= A; i++) dfs(i + 30, n + 1, edge), dfs(NOT + i + 30, n + 1, edge);
		for (i = edge[0].size() - 1; i >= 0; i--){
			dfs(edge[0][i], -n - 1, back);
			if (!check(back[0])) ans = false;
			back[0].clear();
		}
		
		printf("%s\n", ans ? "Yes" : "No");
		
	}

	return 0;
}