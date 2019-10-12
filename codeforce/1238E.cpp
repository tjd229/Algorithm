//dp
#include <stdio.h>
#include <queue>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll d[1 << 20];
bool vis[1 << 20];
int w[20][20];
char s[100000];
int n, m;
 
int main() {
	int i;
	for (scanf("%d%d %s", &n, &m, s), i = 1; i < n; ++i) {
		int u = s[i - 1] - 'a';
		int v = s[i] - 'a';
		++w[u][v]; ++w[v][u];
	}
	vector<int> pre, post;
	queue<pii >q;
	q.push({ 0,1 });
	while (q.size()) {
		int stat = q.front().first;
		int pos = q.front().second;
		q.pop();
		pre.clear(); post.clear();
		for (int i = 0; i < m; ++i) {
			if (stat&(1 << i)) pre.push_back(i);
			else post.push_back(i);
		}
		for (auto u : post) {
			int nxt = stat + (1 << u);
			if (vis[nxt] == 0) {
				vis[nxt] = 1, d[nxt] = 1e18;
				q.push({ nxt,pos + 1 });
			}
			ll presum = 0, postsum = 0;
			for (auto v : pre) presum += w[u][v] * pos;
			for (auto v : post) {
				if (u == v) continue;
				postsum += w[u][v] * pos;
			}
			ll dist = d[stat] + presum - postsum;
			if (d[nxt] > dist) d[nxt] = dist;
		}
	}
	printf("%I64d", d[(1 << m) - 1]);
 
	return 0;
}