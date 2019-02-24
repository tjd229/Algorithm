//graph, djs, tp sort
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int n, m;
int ind[2001];
string eval[1001];
vector<int > edge[2001];
int p[2001];
int lev[2001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, j;
	int ix1 = 1;
	cin >> n >> m;
	int nm = n + m;
	for (i = 1; i <= n; ++i) {
		cin >> eval[i];
	}
	for (i = 1; i <= nm; ++i) p[i] = i;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < m; ++j) {
			if (eval[i][j] == '=') un(i,n+j+1);
		}
	}
	bool flag = 1;
	for (i = 1; i <= n && flag; ++i) {
		for (j = 0; j < m && flag; ++j) {
			int u = i;
			int v = n + j + 1;
			u = find(u); v = find(v);
			if (eval[i][j] == '>') {
				if (find(u) == find(v)) flag = 0;
				else {
					edge[v].push_back(u);
					++ind[u];
				}
			}
			else if (eval[i][j] == '<') {
				if (find(u) == find(v)) flag = 0;
				else {
					edge[u].push_back(v);
					++ind[v];
				}
			}
		}
	}
	if (flag) {
		queue<int> q;
		for (i = 1; i <= nm; ++i) if (ind[i]==0) q.push(i),lev[i]=1;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto v : edge[u]) {
				if (--ind[v] == 0) {
					q.push(v);
					lev[v] = lev[u] + 1;
				}
			}
		}
		for (i = 1; i <= nm; ++i) {
			lev[i] = lev[find(i)];
			flag &= (lev[i] != 0);
			//cout << lev[i] << "\n";
		}
	}
	if (flag) {
		cout << "Yes\n";
		for (i = 1; i <= n; ++i) cout << lev[i] << " ";
		cout << "\n";
		for (i = 1; i <= m; ++i) cout << lev[n + i] << " ";
	}
	else cout << "No";
	return 0;
}
