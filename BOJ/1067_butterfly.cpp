//math, FFT
#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#define PI 3.14159265358979323846
#define base complex<double>
#define reg register
using namespace std;
int rearr[1<<17];
int rev(reg int n, reg int k) {
	int r = 0;
	while (k--) {
		r += r + (n & 1);
		n >>= 1;
	}
	return r;
}
void FFT(vector<base > &A, bool inv = 0) {
	for (int i = 0; i < A.size(); ++i) 
		if (rearr[i]) swap(A[i],A[rearr[i]]);
	
	int half = 1;
	for (int step = 2; step <= A.size(); step += step) {
		double theta = (PI + PI) / step;
		if (inv) theta = -theta;
		base ws(cos(theta), sin(theta));
		for (int i = 0; i < A.size(); i += step) {
			base w(1);
			for (int j = 0; j < half; ++j) {
				base odd = A[i + j + half] * w;
				A[i + j + half] = A[i + j] - odd;
				A[i + j] += odd;
				w *= ws;
			}
		}
		half += half;
	}
	if (inv) {
		for (int i = 0; i < A.size(); ++i) A[i] /= A.size();
	}
}

int main() {
	int i, N, n;
	vector<base> X, Y;
	int k = 0;
	for (scanf("%d", &N), n = 1; n < N + N; n <<= 1) ++k;
	for (i = 0; i < n; ++i) {
		int j = rev(i,k);
		if (i < j) rearr[i] = j;
	}
	for (i = 0, X.resize(n), Y.resize(n); i < N; ++i) {
		int x; scanf("%d", &x);
		X[i + N] = X[i] = x;
	}
	for (i = 0; i < N; ++i) {
		int y; scanf("%d", &y);
		Y[N - i - 1] = y;
	}
	//
	int ans = 0;
	FFT(X); FFT(Y);
	for (i = 0; i < n; ++i) X[i] *= Y[i];
	FFT(X, 1);
	for (i = 0; i < n; ++i) {
		double coef = X[i].real();
		coef += coef > 0 ? 0.5 : -0.5;
		if (ans < coef) ans = coef;
	}
	printf("%d", ans);
	return 0;
}
