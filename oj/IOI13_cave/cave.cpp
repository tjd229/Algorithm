//bs
#include "cave.h"
#define reg register
int _N;
void fill(int *a, int val, int s, int e, int *chair) {
	for (reg int i = 0; i < s; ++i) a[chair[i]] = 1 - val;
	for (reg int i = s; i <= e; ++i) a[chair[i]] = val;
	for (reg int i = e + 1; i < _N; ++i) a[chair[i]] = 1 - val;
}
void exploreCave(int N) {
	_N = N;
	int chair[5000], S[5000], D[5000];
	
	int &rem = _N;
	for (reg int i = 0; i < N; ++i) chair[i] = i;
	for (int i = 0; i < N; ++i) {
		int val = 0;
		fill(S, val, 0, rem - 1, chair);
		if (tryCombination(S) == i) val = 1;
		int l = 0, r = rem - 1;
		int pos = -1;
		while (l <= r) {
			int m = (l + r) >> 1;
			fill(S, val, l, m, chair);
			if (tryCombination(S) == i) l = m + 1;
			else r = m - 1, pos = m;
		}
		S[chair[pos]] = val;
		D[chair[pos]] = i;
		--rem;
		chair[pos] ^= chair[rem] ^= chair[pos] ^= chair[rem];
	}
	answer(S, D);
}