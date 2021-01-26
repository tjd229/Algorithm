//greedy
#include <stdio.h>
#include <queue>
#define ll long long
using namespace std;
int k[300001];
int c[300001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		priority_queue<int> q;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%d", k + i), q.push({k[i]});
		for (i = 1; i <= m; ++i) scanf("%d",c+i);
 
		for (i = 1; i <= n && i<q.top(); ++i) {
			q.pop();
			q.push(i);
		}
		ll cost = 0;
		while (q.size()) {
			int x = q.top(); q.pop();
			cost+=c[x];
		}
		printf("%I64d\n",cost);
 
	}
	return 0;
}