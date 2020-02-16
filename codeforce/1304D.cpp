//graph, tp sort
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int n;
string quiz;
int d[200001];
vector<int> edge[200001],l[200001],r[200001];
int ans[200001];
int cnt;
void dfs(int x) {
	//printf("%d\n",x);
	for(auto nxt:r[x])
		dfs(nxt);
	for (auto nxt : l[x])
		dfs(nxt);
	if(ans[x]==0)
		ans[x] = ++cnt;
}
void mn_sort() {//0(max,->), 1(min,<-)
	vector<int> v;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		d[i] = 0;
		l[i].clear(); r[i].clear();
		ans[i] = 0;
	}
	if (quiz[0] == '>')v.push_back(1);
	for (int i = 1; i < n - 1; ++i) {
		if (quiz[i] == '>' && quiz[i - 1] == '<') {
			v.push_back(i + 1);
		}
	}
	if (quiz[n - 2] == '<') v.push_back(n);
 
	reverse(v.begin(), v.end());
	for (int i = 0; i < n - 1; ++i) {
		int x = i + 1;
		if (quiz[i] == '<') {
			l[x + 1].push_back(x);
			++d[x];
		}
		else {//>
			r[x].push_back(1 + x);
			++d[x + 1];
		}
	}
	for (auto x : v) {
		
		dfs(x);
	}
}
void tp_sort(int dir) {//0(max,->), 1(min,<-)
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		d[i] = 0;
		edge[i].clear();
		ans[i] = 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (quiz[i] == '<') {
			v.push_back(i + 1 + 1);
			edge[i + 1].push_back(i + 1 + 1);
			++d[i + 1 + 1];
		}
		else {
			edge[i + 1 + 1].push_back(i + 1);
			++d[i + 1];
		}
	}
	/*for (auto x : v) {
		printf("%d ", x);
	}printf("\n");*/
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] - v[i - 1] != 1) {
			if (dir) {//min
				edge[v[i]].push_back(v[i - 1] - 1);
				++d[v[i - 1] - 1];
			}
			else {
				edge[v[i - 1]].push_back(v[i]);
				++d[v[i]];
			}
		}
	}
	int cnt = 1;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		ans[x] = cnt++;
		for (auto nxt : edge[x]) {
			if (--d[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> quiz;
		mn_sort();
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}cout << "\n";
		tp_sort(0);
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}cout << "\n";
	}
 
	return 0;
}