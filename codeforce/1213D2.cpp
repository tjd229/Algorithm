//implementation
#include <stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[400001];
int ans;
int inq[200001];
int n, k;
void merge(int x,int a,int b) {
	int i = 0, j = 0;
	
	while (i < v[a].size() || j < v[b].size()) {
		if (v[x].size() >= k) break;
		if (i == v[a].size()) {
			v[x].emplace_back(v[b][j] + 1);
			++j;
		}
		else if (j == v[b].size()) {
			v[x].emplace_back(v[a][i] + 1);
			++i;
		}
		else {
			int op = v[a][i] < v[b][j] ? v[a][i++] : v[b][j++];
			v[x].emplace_back(op + 1);
		}
	}
	int op = 0;
	for (i = 0; v[x].size() >= k && i < k; ++i)
		op += v[x][i];
	if (v[x].size() >= k && ans > op) ans = op;
}
int main() {
	int i;
	priority_queue<int> q;
	ans = 1e9;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
		int a; scanf("%d",&a);
		v[a].emplace_back(0);
		inq[a] = 1;
	}
	for (i = 1; i <= 200000; ++i) {
		if (v[i].size()) q.push(i);
	}
	while (q.size()) {
		int x = q.top(); q.pop();
		if (x == 0) break;
		merge(x, x + x, x + x + 1);
		int p = x >> 1;
		if (!inq[p]) q.push(p),inq[p]=1;
	}
	printf("%d",ans);
	return 0;
}