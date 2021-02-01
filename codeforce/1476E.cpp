//graph, tp sort, string, hashing
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int basemask[4] = {31,31<<5,31<<10,31<<15};
int mask[16];
char buf[4];
int p[100001];
int s[100001];
int mt[100001];
vector<int> st[1 << 20];
vector<int> edge[1 << 20];
int ind[1 << 20];
int p2ix[1 << 20];
int main() {
	int i, n, m, k;
	int bnd = 0;
	bool flag = 1;
	for (scanf("%d%d%d", &n, &m, &k), i = 1,bnd=1<<k; i <= n; ++i) {
		scanf(" %s",buf);
		int &h = p[i];
		for (int j = 0; j < k; ++j) {
			h <<= 5;
			if (buf[j] != '_') h += buf[j] - 'a'+1;
		}
	}
	for (i = 0; i < bnd; ++i) {
		for (int j = 0; j < k; ++j) if (i&(1 << j)) mask[i] |= basemask[j];
	}
	for (i = 1; i <= m; ++i) {
		scanf(" %s %d", buf,mt+i);
		int &h = s[i];
		for (int j = 0; j < k; ++j) {
			h <<= 5;
			h += buf[j] - 'a' + 1;
		}
		for (int j = 0; j < k; ++j) {
			int c = h & basemask[j];
			int patc = p[mt[i]] & basemask[j];
			if (patc > 0 && patc != c) flag = 0;
		}
		for (int j = 0; j < bnd; ++j) {
			int pick = mask[j] & h;
			st[pick].push_back(i);
		}
	}
	if (flag == 0) {
		printf("NO");
		return 0;
	}
	vector<int> ans;
	queue<int> q;
	for (i = 1; i <= n; ++i) {
		int u = p[i];
		p2ix[u] = i;
		for (auto six : st[u]) {
			int v = p[mt[six]];
			if (u==v) continue;
			edge[u].push_back(v); ++ind[v];
		}
	}
	for (i = 1; i <= n; ++i) {
		int x = p[i];
		if (ind[x] == 0) {
			ans.push_back(i);
			q.push(x);
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v : edge[u]) {
			if (--ind[v] == 0) {
				q.push(v);
				ans.push_back(p2ix[v]);
			}
		}
	}
	reverse(ans.begin(), ans.end());
	flag = ans.size() == n;
	for (printf("%s\n", flag ? "YES" : "NO"), i = 0; i < ans.size() && flag; ++i)
		printf("%d ",ans[i]);
	return 0;
}