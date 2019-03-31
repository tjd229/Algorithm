//ft
#include <stdio.h>
#define ll long long
const int LEAF = 1 << 20;
ll ft[LEAF+1];
ll _Sum(int ix) {
	ll res = 0;
	while (ix) {
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
ll Sum(int i, int j) {
	if (i > j) i ^= j ^= i ^= j;
	return _Sum(j) - _Sum(i - 1);
}
void Modify(int i, int k) {
	while (i <= LEAF) {
		ft[i] += k;
		i += (i&-i);
	}
}
int main() {
	int N, M;
	int t, i, j;
	for (scanf("%d%d", &N, &M); M--;) {
		scanf("%d%d%d",&t,&i,&j);
		if (t) Modify(i, j-Sum(i,i));
		else printf("%lld\n",Sum(i,j));
	}

	return 0;
}