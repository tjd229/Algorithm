//https://programmers.co.kr/learn/courses/30/lessons/76503
//graph, greedy
#include <string>
#include <vector>
#define ll long long
using namespace std;
vector<int> edge[300000];
ll A[300000];
int n;
ll ans;
void dfs(int x, int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x);
	}
	if (x) {
		if (A[x] < 0) {
			A[from] += A[x];
			ans -= A[x];
		}
		else if (A[x] > 0) {
			A[from] += A[x];
			ans += A[x];
		}
	}
	
}
long long solution(vector<int> a, vector<vector<int>> edges) {
	
	n = a.size();
	ans = 0;
	for (int i = 0; i < n; ++i) A[i] = a[i];
	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i][0], v = edges[i][1];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0, -1);
	if (A[0] != 0) return -1;
	return ans;
}