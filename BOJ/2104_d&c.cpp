//d&c
#include <stdio.h>
#define ll long long
int A[100001];
ll dandc(int s,int e) {
	if (s == e) return (ll)A[s] * A[s];
	int m = (s + e) >> 1;
	ll left = dandc(s, m);
	ll right = dandc(m + 1, e);
	ll res = A[m] * (ll)A[m];
	int l = m - 1;
	int r = m + 1;
	int mn = A[m];
	ll sum = A[m];
	while (l>=s || r<=e ) {
		int ix;
		if (l < s) ix = r++;
		else if (e < r) ix = l--;
		else ix = A[l] < A[r] ? r++ : l--;
		if (mn > A[ix]) mn = A[ix];
		sum += A[ix];
		ll pt = sum * mn;
		if (pt > res) res = pt;
	}
	if (res < left) res = left;
	if (res < right) res = right;
	return res;
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%d", A + i);
	printf("%lld",dandc(1,N));
	return 0;
}