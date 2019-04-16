//math, d&c, FFT

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#define ll long long
#define cpd complex<double>
using namespace std;
const double PI = acos(-1);
int ans[1<<20];
void FFT(vector<cpd > &F, vector<cpd > &A,cpd w) {
	if (A.size() == 1) F = A;
	else {
		int n = A.size();
		vector<cpd > a[2], f[2];
		for (int i = 0; i < n; ++i) a[i & 1].push_back(A[i]);
		F.resize(n); n >>= 1;
		FFT(f[0], a[0], w*w); FFT(f[1], a[1], w*w);
		cpd x(1);
		for (int i = 0; i < n; ++i) {
			cpd odd = x * f[1][i];
			F[i] = f[0][i] + odd;
			F[i + n] = f[0][i] - odd;
			x *= w;
		}
	}
}
int main() {
	int i;
	ios::sync_with_stdio(false); cin.tie(0);
	string A, B; cin >> A >> B;
	if (A[0] == '0' || B[0] == '0') {
		cout << 0;
		return 0;
	}
	vector<cpd > a, b;
	for (reverse(A.begin(), A.end()), i = 0; i < A.size(); ++i)
		a.push_back(A[i]-'0');
	int mx = a.size();
	for (reverse(B.begin(), B.end()), i = 0; i < B.size(); ++i)
		b.push_back(B[i] - '0');
	if (mx < b.size()) mx = b.size();
	int p = 1;
	for (; p < mx + mx; p += p);
	a.resize(p); b.resize(p);

	double theta = (PI + PI) / p;
	cpd w(cos(theta), sin(theta));
	FFT(a, a, w); FFT(b, b, w);
	for (i = 0; i < p; ++i) a[i] *= b[i];
	w = cpd(cos(-theta), sin(-theta));
	FFT(a, a, w);

	ll carry = 0;
	int *pt = ans;
	for (i = 0; i < p; ++i,++pt) {
		ll coef = a[i].real() / p + 0.01;
		coef += carry;
		*pt = coef % 10;
		carry = coef / 10;
	}
	while (carry) {
		*pt = carry % 10;
		carry /= 10;
        ++pt;
	}
	while (*pt == 0) --pt;
	for (i = pt - ans; i >= 0; --i) cout << ans[i];
	
	return 0;
}
