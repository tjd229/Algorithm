//greedy
#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int T;
	int i, M;
	for (scanf("%d", &T); T--;) {
		priority_queue<int> mxh, mnh;
		scanf("%d",&M);
		printf("%d\n", (M >> 1) + 1);
		for (i = 0; i < M; ++i) {
			int e; scanf("%d",&e);
			mxh.push(e);
			if ((i & 1) == 0) {
				if (mxh.size()>1) {
					mnh.push(-mxh.top());
					mxh.pop();
					while (mxh.top() > -mnh.top()) {
						mnh.push(-mxh.top()); mxh.pop();
						mxh.push(-mnh.top()); mnh.pop();
					}
				}
				printf("%d ",mxh.top());
			}
			if (i == 19) {
				i -= 20, M -= 20;
				puts("");
			}
		}
		if (i) puts("");
	}
	return 0;
}