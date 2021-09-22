//greedy
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
vector<int> ans;
int a[10][200001], c[10];
vector<int> ban[100000];
ll pick(vector<int> &v) {
	ll cum = 0;
	for (int i = 0; i < v.size(); ++i)
		cum += a[i][v[i]];
	return cum;
}
int main() {
	int i, j, n, m;
 
	set<vector<int> > st,vis;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		for (scanf("%d", c + i), j = 1; j <= c[i]; ++j)
			scanf("%d", a[i] + j);
	}
	for (scanf("%d", &m), i = 0; i < m; ++i) {
		ll cum = 0; ban[i].resize(n);
		for (j = 0; j < n; ++j) {
			int b; scanf("%d", &b); ban[i][j] = b;
			cum += a[j][ban[i][j]];
		}
		st.insert(ban[i] );
	}
	for (i = 0; i < n; ++i) ans.push_back(c[i]);
	priority_queue<pair<ll, vector<int> > > q;
	q.push({ pick(ans), ans });
	vis.insert(ans);
	while (1) {
		ll val = q.top().first;
		auto v = q.top().second; q.pop();
		auto it = st.lower_bound(v);
		if (it == st.end() ||*it != v) {
			ans = v;
			break;
		}
		st.erase(it); 
		for (i = 0; i < n; ++i) {
			if (v[i] == 1) continue;
			ll nxt = val;
			nxt -= a[i][v[i]]; nxt += a[i][v[i] - 1];
			v[i] = v[i] - 1;
			if (*vis.lower_bound(v) != v) {
				q.push({ nxt,v });
				vis.insert(v);
			}
			v[i] = v[i] + 1;
		}
	}
	for (auto x : ans)
		printf("%d ", x);
 
	return 0;
}