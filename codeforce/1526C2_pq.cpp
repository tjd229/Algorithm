//greedy
#include <stdio.h>
#include <queue>
#define ll long long
using namespace std;
int main() {
	int i, n;
	ll tot = 0; int ans = 0;
	priority_queue<int> q;//mn heap
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		int a; scanf("%d", &a);
		tot += a; ++ans;
		q.push(-a);
		while (tot < 0) {
			a = -q.top(); q.pop();
			tot -= a; --ans;			
		}
	}
	printf("%d",ans);
 
	return 0;
}