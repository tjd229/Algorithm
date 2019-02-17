//greedy
#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int i, N;
	int ans = 0;
	priority_queue<int> q;
	for (scanf("%d", &N); N--;) {
		int sz; scanf("%d",&sz);
		q.push(-sz);
	}
	while (q.size() > 1) {
		int t1 = q.top(); q.pop();
		int t2 = q.top(); q.pop();
		ans -= t1 + t2;
		q.push(t1+t2);
	}
	printf("%d",ans);
	return 0;
}