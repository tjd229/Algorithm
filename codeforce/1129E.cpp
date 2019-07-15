//graph, bs
#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int p[501];
int c[501];
int ask(int *T,int s,int e,int v) {
	int i;
	for (printf("1\n1\n%d\n", e - s + 1), i = s; i <= e; ++i)
		printf("%d ",T[i]);
	printf("\n%d\n", v); fflush(stdout);
	int c; scanf("%d",&c);
	return c;
}
int main() {
	int T[500]; int tsz = 0;
	int i, n; scanf("%d",&n);
	vector<pii > order;
	for (i = 2; i <= n; ++i) T[i] = i;
	for (i = 2; i <= n; ++i) {
		c[i] = ask(T,2,n,i);
		order.push_back({c[i],i});
	}
	order.push_back({n,1});
	sort(order.begin(), order.end());
	for (i = 0; order[i].first == 1; ++i)
		T[tsz++] = order[i].second;
	while (i < n) {
		int c = order[i].first;
		vector<int> v;
		while (i < n && c == order[i].first) {
			v.push_back(order[i].second);
			++i;
		}
		if (v[0] == 1) {//degen
			for (int j = 0; j < tsz; ++j) p[T[j]] = 1;
			break;
		}
		for (auto x : v) {
			while (1) {
				int l = 0, r = tsz - 1;
				int pick = -1;
				while (l <= r) {
					int m = (l + r) >> 1;
					if (ask(T, l, m, x)) r = m - 1,pick=m;
					else l = m + 1;
				}
				if (pick < 0) break;
				int c = T[pick];
				p[c] = x; --tsz;
				T[tsz] ^= T[pick] ^= T[tsz] ^= T[pick];
			}
		}
		for (auto x : v) T[tsz++] = x;
	}
	for (printf("ANSWER\n"), i = 2; i <= n; ++i)
		printf("%d %d\n",i,p[i]);
	fflush(stdout);
	return 0;
}