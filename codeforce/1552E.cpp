//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int a[101], b[101];
int cnt[10001];
int main() {
	vector<int> c[101];
	vector<tuple<int,int,int> > it;
	int i, j, n, k; scanf("%d%d",&n,&k);
	int nk = n * k;
	int mxcnt = n / (k - 1) + ( (n%(k-1))>0);
	for (i = 1; i <= nk; ++i) {
		int clr; scanf("%d",&clr);
		c[clr].push_back(i);
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j < k; ++j)
			it.push_back({c[i][j],c[i][j-1],i});
	}
	sort(it.begin(), it.end());
	for (auto range : it) {
		int s, e, clr; tie(e, s, clr) = range;
		if (a[clr] != 0) continue;
		int mx=0;
		for (i = s; i <= e && mx<=mxcnt; ++i) 
			mx = max(mx, cnt[i]+1);
		if (mx <= mxcnt) {
			a[clr] = s; b[clr] = e;
			for (i = s; i <= e; ++i) ++cnt[i];
		}
	}

	for (i = 1; i <= n; ++i)
		printf("%d %d\n",a[i],b[i]);


	return 0;
}