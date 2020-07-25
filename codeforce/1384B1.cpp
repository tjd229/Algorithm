//graph
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
int d[101];
int vis[101][201];
int n, k, l;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t; cin >> t;
	while (t--) {
		vector<int > p;
		cin >> n >> k >> l;
		for (i = 1; i <= n; ++i) cin >> d[i];
		bool flag = 0;
		int kk = k + k;
		for (i = 0; i <= k; ++i) p.push_back(i);
		for (i = k - 1; i > 0; --i) p.push_back(i);
		queue<pii > q;
		for (i = 0; i < kk; ++i) q.push({0,i}),vis[0][i]=t+1;
		while (q.size() && flag == 0) {
			pii stat = q.front(); q.pop();
			int x = stat.first;
			int cur = stat.second;
			if (x == n) {
				flag = 1;
				break;
			}
			int nt = (cur + 1) %kk;
			if (vis[x + 1][nt] != t + 1 && d[x + 1] + p[nt] <= l) {
				vis[x + 1][nt] = t + 1;
				q.push({1+x,nt});
			}
			if (vis[x][nt] != t + 1 && d[x] + p[nt] <= l) {
				vis[x][nt] = t + 1;
				q.push({x,nt});
			}
		}
 
 
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
 
	return 0;
}