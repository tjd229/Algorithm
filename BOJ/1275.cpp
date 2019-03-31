//st
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int LEAF = 1 << 19;
vector<int> comp;
ll st[LEAF + LEAF];
int x[100000], y[100000], a[100000], b[100000];
int arr[100001];
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix] + st[ix + ix + 1];
		ix >>= 1;
	}
}
ll sum(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to);
}
int main() {
	int i, N, Q;
	for (scanf("%d%d", &N, &Q), i = 1; i <= N; ++i) {
		scanf("%d",arr+i);
		comp.push_back(i);
	}
	for(i = 0; i < Q; ++i) {
		scanf("%d%d%d%d", x + i, y + i, a + i, b + i);
		comp.push_back(x[i]); comp.push_back(y[i]);
		comp.push_back(a[i]);
		if (x[i] > y[i]) x[i] ^= y[i] ^= x[i] ^= y[i];
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	int ix = lower_bound(comp.begin(),comp.end(),1)-comp.begin();
	for (i = 1; i <= N; ++i, ++ix) 
		upd(LEAF + ix, arr[i]);
	
	for (i = 0; i < Q; ++i) {
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		x[i] = lower_bound(comp.begin(), comp.end(), x[i]) - comp.begin();
		y[i] = lower_bound(comp.begin(), comp.end(), y[i]) - comp.begin();
		printf("%lld\n",sum(1,0,LEAF-1,x[i],y[i]));
		upd(LEAF+a[i],b[i]);
	}
	return 0;
}
