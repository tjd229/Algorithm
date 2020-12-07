//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int c[500001];
int main() {
	int i, n, k;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d",c+i);
	sort(c + 1, c + 1 + n);
	long long suffix = 0; int ed=n;
	while (ed>0 &&suffix >= 0) {
		suffix += c[ed];
		--ed;
	}
	++ed;
	vector<vector<int> > seq(++k);
	i = 1; int s = 0;
	while (i<=ed &&c[i] < 0) {
		seq[s].push_back(c[i]);
		++i; s = (s + 1) % k;
	}
	while (i <= n) seq[0].push_back(c[i++]);
	long long ans = 0;
	for (i = 0; i < k; ++i) {
		for (long long j = 0; j < seq[i].size(); ++j)
			ans += j * seq[i][j];
	}
	printf("%I64d\n",ans);
	return 0;
}