//bs, implementation
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll f[1001];
int _h, _l;
ll sim(int l,int r,int pos, ll cnt) {
	if (l >= r) return 0;
	int m = (l + r) >> 1;
	if (m == pos) {
		l = m + 1;
		while (l < r) {
			m = (l + r) >> 1;
			if (_h == 0) return 0;
			r = m;
			cnt = _h * cnt%mod;
			--_h;
		}
		int remain = _h + _l;
		
		return cnt*f[remain]%mod;
	}
	else if (m > pos) {
		if (_h == 0) return 0;
		--_h;
		return sim(l, m, pos, cnt*(1+_h)%mod);
	}
	else {
		if (_l == 0) return 0;
		--_l;
		return sim(m+1, r, pos, cnt*(1 + _l) % mod);
	}
}
int main() {
	int i, n, x, pos; scanf("%d%d%d",&n,&x,&pos);
	_l =x-1;
	_h = n - _l-1;
	f[0] = f[1] = 1;
	for (i = 2; i <= n; ++i) 
		f[i] = i * f[i - 1] % mod;
	
	printf("%I64d",sim(0,n,pos,1));

	return 0;
}