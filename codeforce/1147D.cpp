//graph
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
//same:union, diff:edge
string s;
const int mod = 998244353;
int m,p[2001],clr[2001];
int node0, node1;
bool dfs(int x,vector<pii > *edge) {
	bool res = 1;
	for (auto p : edge[x]) {
		int diff = p.second;
		int nxt = p.first;
		if (clr[nxt]) {
			int d = clr[nxt] - clr[x];
			if (d < 0) d = -d;
			if (d != diff) return 0;
		}
		else {
			clr[nxt] = clr[x] & 1 ? clr[x] + diff : clr[x] - diff;
			if (!dfs(nxt, edge)) return 0;
		}
	}
	return 1;
}
int main() {
	long long ans=0;
	int l, r;
	cin >> s;  m=s.size();
	reverse(s.begin(), s.end());
	s = "#" + s;
	for (int i = 1; i < m; ++i) {
		vector<pii > edge[2001];
		node1 = m + i + 1;
		for (int j = 0; j <= node1; ++j) p[j] = j,clr[j]=0;
		for (l = 1, r = m; l < r; ++l, --r) {
			edge[l].push_back({ r,0 });
			edge[r].push_back({ l,0 });
		}
		for (l = 1, r = i; l < r; ++l, --r) {
			edge[m+l].push_back({ m+r,0 });
			edge[m+r].push_back({ m+l,0 });
		}
		for (int j = 1; j <= m; ++j) {
			if (s[j] == '?') continue;
			else if (j > i) {
				int p = s[j] == '0' ? node0 : node1;
				edge[p].push_back({j,0});
				edge[j].push_back({p,0});
			}
			else {
				edge[j].push_back({ m + j,s[j] == '1' });
				edge[m+j].push_back({ j,s[j] == '1' });
			}
		}
		edge[m + i].push_back({node1,0 });
		edge[node1].push_back({ m + i,0 });
		edge[node0].push_back({ node1,1 });
		edge[node1].push_back({ node0,1 });
		clr[node0] = 1;
		long long cnt = 1;
		if (!dfs(node0, edge)) continue;
		for (int j = 1; j < node1; ++j) {
			if (clr[j]) continue;
			clr[j] = 1;
			if (!dfs(j, edge)) {
				cnt = 0;
				break;
			}
			
			cnt = (cnt + cnt) % mod;
		}
		
		ans = (ans + cnt) % mod;
	}
	cout << ans;
}