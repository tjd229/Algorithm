//greedy, math
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int c[500000];
int main() {
	int i, n, k;
	long long ans = 0;
	for (scanf("%d%d", &n, &k), i = 0; i < n; ++i) scanf("%d",c+i);
	sort(c , c  + n);
	vector<vector<int> > seq(++k);
	long long suf = 0;
	for (i = 0; i < n; ++i) suf += c[i];
	i = 0; int s = 0;
	while (suf < 0) {
		seq[s].push_back(c[i]);
		suf -= c[i++];
		s = (s + 1) % k;
	}
	while (i < n) seq[0].push_back(c[i++]);
	for (i = 0; i < k; ++i) {
		for (long long j = 0; j < seq[i].size(); ++j)
			ans += j * seq[i][j];
	}
	printf("%I64d\n",ans);
	return 0;
}