//greedy
#include <stdio.h>
#include <queue>
#define ll long long
using namespace std; 
int w[100001];
int d[100001];
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		ll sum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) d[i] = 0,scanf("%d",w+i),sum+=w[i];
		priority_queue<int> q;
		for (i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			++d[u], ++d[v];
		}
		for (i = 1; i <= n; ++i) {
			while (--d[i]) q.push(w[i]);
		}
		printf("%I64d ", sum);
		while (q.size()) {
			int w = q.top(); q.pop();
			sum+=w;
			printf("%I64d ", sum);
		}
		puts("");
	}
	return 0;
}