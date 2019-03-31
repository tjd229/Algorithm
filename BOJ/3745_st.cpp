//st
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 17;
int st[LEAF + LEAF];
int p[100000];
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int mx(int ix, int s, int e, int ub) {
	if (ub <= s) return 0;
	if (e < ub) return st[ix];
	return max(mx(ix + ix, s, (s + e) >> 1, ub), mx(ix + ix + 1, 1 + ((s + e) >> 1), e, ub));
}
int main() {
	int i, N;
	while (scanf("%d", &N)!=-1) {
		vector<int> comp;
		memset(st, 0, sizeof(st));
		for (i = 0; i < N; ++i) {
			scanf("%d",p+i);
			comp.push_back(p[i]);
		}
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
		for (i = 0; i < N; ++i) {
			p[i] = lower_bound(comp.begin(), comp.end(), p[i])-comp.begin();
			int len = mx(1, 0, LEAF - 1, p[i]);
			upd(LEAF + p[i], len + 1);
		}
		printf("%d\n",st[1]);
	}
	return 0;
}