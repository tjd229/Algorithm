//greedy, math
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int c[500000];
int main() {
	int i, n, k;
	long long ans = 0;
	for (scanf("%d%d", &n, &k), i = 0; i < n; ++i) scanf("%d",c+i);
	sort(c, c + n);
	priority_queue<long long> pq;
	for (i = 0; i <= k; ++i) pq.push(0);
	for (i = n-1; i >=0; --i) {
		long long top = pq.top(); pq.pop();
		ans += top;
		pq.push(top+c[i]);
	}
 
	printf("%I64d\n",ans);
	return 0;
}