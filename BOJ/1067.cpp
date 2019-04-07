//math, d&c, FFT
#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#define PI 3.14159265358979323846
#define base complex<double>
using namespace std;
void FFT(vector<base > &F, vector<base > &A, base w) {
	if (A.size() == 1) F = A;
	else {
		int n = A.size();
		vector<base > a[2], f[2];
		for (int i = 0; i < n; ++i) a[i & 1].push_back(A[i]);
		F.resize(n); n >>= 1;
		FFT(f[0], a[0], w*w); FFT(f[1], a[1], w*w);
		base x(1);
		for (int i = 0; i < n; ++i) {
			base odd = x * f[1][i];
			F[i] = f[0][i] + odd;
			F[i + n] = f[0][i] - odd;
			x *= w;
		}
	}
}
int main() {
	int i, N, n;
	vector<base> X, Y, S;
	for (scanf("%d", &N), n = 1; n < N + N; n <<= 1);
	for (i = 0, X.resize(n), Y.resize(n); i < N; ++i) {
		int x; scanf("%d", &x);
		X[i + N] = X[i] = x;
	}
	for (i = 0; i < N; ++i) {
		int y; scanf("%d", &y);
		Y[N - i - 1] = y;
	}
	//
	double theta = (PI + PI) / n;
	base w(cos(theta), sin(theta));
	FFT(X, X, w); FFT(Y, Y, w);
	for (i = 0; i < n; ++i) X[i] *= Y[i];
	base w_(cos(-theta), sin(-theta));
	FFT(S, X, w_);
	int ans = 0;
	for (i = 0; i < S.size(); ++i) {
		double coef = S[i].real() / n;
		coef += coef > 0 ? 0.5 : -0.5;
		if (ans < coef) ans = coef;
	}
	printf("%d",ans);
	return 0;
}
