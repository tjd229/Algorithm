//graph
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
vector<int> edge[100001];
vector<int> candi;
int p[100001];
int c[100001];
void dfs(int x) {
	bool del = c[x];
	for (auto nxt : edge[x]) {
		del &= c[nxt];
	}
	if (del) candi.push_back(x);
	for (auto nxt : edge[x]) dfs(nxt);
}
int main() {
	int i, n,r;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		if (p[i] > 0) {
			edge[p[i]].push_back(i);
		}
		else r = i;
	}
	dfs(r);
	if (candi.empty()) cout << -1;
	else {
		sort(candi.begin(), candi.end());
		for (auto x : candi) cout << x << " ";
	}
	return 0;
}
