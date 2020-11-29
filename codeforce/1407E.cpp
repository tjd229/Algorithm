//graph, dp
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> b[500001], w[500001];
int d[500001][2];

int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 1; i < n; ++i) d[i][0] = d[i][1] = -1;
	while (m--) {
		int u, v, t; scanf("%d%d%d",&u,&v,&t);
		if (t) w[v].push_back(u);
		else b[v].push_back(u);
	}
	queue<int> q; q.push(n);
	while (q.size()) {
		int x = q.front(); q.pop();
		int len = d[x][0] > d[x][1] ? d[x][0] : d[x][1];
		for (auto nxt : b[x]) {
			if (d[nxt][0]<0 ) {
				d[nxt][0] = len + 1;
				if (d[nxt][0] >= 0 && d[nxt][1] >= 0)
					q.push(nxt);
			}
		}
		for (auto nxt : w[x]) {
			if (d[nxt][1]<0 ) {
				d[nxt][1] = len + 1;
				if (d[nxt][0] >= 0 && d[nxt][1] >= 0)
					q.push(nxt);
			}
		}
	}

	if (d[1][0] < 0 || d[1][1]<0) printf("-1\n");
	else printf("%d\n", d[1][0] < d[1][1] ? d[1][1] : d[1][0]);
	for ( i = 1; i <= n; ++i) {
		if (d[i][0] < 0) printf("0");
		else if (d[i][1] < 0) printf("1");
		else printf("%d", d[i][0] < d[i][1]);
		
	}

	return 0;
}