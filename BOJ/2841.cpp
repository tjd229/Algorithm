//implementation
#include <stdio.h>
#include <stack>
using namespace std;
stack<int> stk[7];
int main() {
	int i, N, P;
	int cnt = 0;
	for (scanf("%d%d", &N, &P); N--;) {
		int str, f;
		scanf("%d%d",&str,&f);
		while (stk[str].size() && stk[str].top() > f) {
			stk[str].pop();
			++cnt;
		}
		if (stk[str].empty() || stk[str].top() < f) {
			stk[str].push(f);
			++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}