//d&c
#include "secret.h"
int range[1000][1000];
int _A[1000], _N;
void pre(int s, int e) {
	if (s >= e) return;
	int m = (s + e) >> 1;
	for (int i = m - 1; i >= s; --i)
		range[i][m] = Secret(_A[i], range[i + 1][m]);
	pre(s, m - 1);
	++m;
	for (int i = m + 1; i <= e; ++i)
		range[m][i] = Secret(range[m][i - 1], _A[i]);
	pre(m + 1, e);
}
void Init(int N, int A[]) {
	_N = N;
	for (int i = 0; i < N; ++i) _A[i] = range[i][i] = A[i];
	pre(0, N - 1);
}
int op(int s, int e, int l, int r) {
	int m = (s + e) >> 1;
	if (m <= r && m + 1 >= l) {
		if (r == m || m + 1 == l) return range[l][r];
		return Secret(range[l][m], range[m + 1][r]);
	}
	if (m > r) return op(s, m - 1, l, r);
	else return op(m + 2, e, l, r);
}
int Query(int L, int R) {
	if (L == R) return _A[L];
	else if (L + 1 == R) return Secret(_A[L], _A[R]);
	return op(0, _N - 1, L, R);
}