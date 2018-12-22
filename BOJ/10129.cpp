//dp

#include <stdio.h>
#include <deque>
#define pii pair<int,int>
using namespace std;
int d[1000001];
int ans[1000001];
int main() {
	int n, i;
	int q, k;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",d+i);
	for (scanf("%d", &q); q--;) {
		scanf("%d",&k);
		deque<pii > dq; //val, ix(h)
		dq.push_back({0,1});
		for (i = 2; i <= n; ++i) {
			while (dq.front().second + k < i) dq.pop_front();
			ans[i] = dq.front().first;
			if (d[i] >= d[dq.front().second]) ++ans[i];
			while (dq.size() && dq.back().first > ans[i]) dq.pop_back();
			while (dq.size() && dq.back().first == ans[i] &&
				d[i]>=d[dq.back().second]) dq.pop_back();
			dq.push_back({ans[i],i});
		}
		printf("%d\n",ans[n]);
	}

	return 0;
}
