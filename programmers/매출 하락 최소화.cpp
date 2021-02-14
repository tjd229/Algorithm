//https://programmers.co.kr/learn/courses/30/lessons/72416
//graph, dp
#include <string>
#include <vector>
#define ll long long
using namespace std;
ll d[300000][2];
vector<int> p;
vector<int> edge[300000];
ll _min(ll a, ll b) { return a < b ? a : b; }
void dfs(int x) {
	ll sum = 0;
	for (auto nxt : edge[x]) {
		dfs(nxt);
		sum += _min(d[nxt][0], d[nxt][1]);
	}
	d[x][1] = sum + p[x];
	d[x][0] = 1e18;
	if (edge[x].empty())d[x][0] = 0;
	for (auto nxt : edge[x]) {
		ll exp = sum - _min(d[nxt][0], d[nxt][1]);
		exp += d[nxt][1];
		d[x][0] = _min(d[x][0], exp);
	}
}
int solution(vector<int> sales, vector<vector<int>> links) {
	int answer = 0;
	p = sales;
	for (auto arr : links) {
		int u = arr[0], v = arr[1];
		--u; --v;
		edge[u].push_back(v);
	}
	dfs(0);
	return _min(d[0][0],d[0][1]);
}