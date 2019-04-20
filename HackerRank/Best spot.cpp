//math, FFT, d&c
//https://www.hackerrank.com/contests/w6/challenges/best-spot/editorial
#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#define cpd complex<double>
using namespace std;
const double PI = acos(-1);
int R, C, H, W;
int sqx[501][501], sqy;
void FFT(vector<cpd > &F, vector<cpd > &A, cpd w) {
	if (A.size() == 1) F = A;
	else {
		int n = A.size();
		vector<cpd > a[2], f[2];
		for (int i = 0; i < n; ++i) a[i & 1].push_back(A[i]);
		F.resize(n); n >>= 1;
		FFT(f[0], a[0], w*w); FFT(f[1], a[1], w*w);
		cpd x = 1;
		for (int i = 0; i < n; ++i) {
			cpd odd = f[1][i] * x;
			F[i] = f[0][i] + odd;
			F[i + n] = f[0][i] - odd;
			x *= w;
		}
	}
}
int main() {
	int i, j;
	int RC, p;
	for (scanf("%d%d", &R, &C), RC = R * C, p = 1; p < RC + RC; p += p);
	vector<cpd > h(p), ps(p);
	int ix = 0;
	for (i = 1; i <= R; ++i) {
		for (j = 1; j <= C; ++j,++ix) {
			scanf("%d",sqx[i]+j);
			h[ix] = h[ix + RC] = sqx[i][j];
			sqx[i][j] *= sqx[i][j];
			sqx[i][j] += sqx[i][j - 1] + sqx[i - 1][j] - sqx[i - 1][j - 1];
		}
	}
	for (scanf("%d%d", &H, &W), i = 1,ix=RC; i <= H; ++i,ix-=C) {
		for (j = 1; j <= W; ++j) {
			int height; scanf("%d",&height);
			ps[ix - j] = height;
			sqy += height * height;
		}
	}
	double theta = (PI + PI) / p;
	cpd w(cos(theta), sin(theta));
	FFT(h, h, w); FFT(ps, ps, w);
	for (i = 0; i < p; ++i) h[i] *= ps[i];
	w = {cos(-theta),sin(-theta)};
	FFT(h, h, w);
	int ans = -1;
	int r, c;
	for (i = 1,ix=RC-1; i <= R-H+1; ++i,ix+=C) {
		for (j = 1; j <= C-W+1; ++j) {
			double coef = h[ix+j-1].real()/p;
			coef += coef > 0 ? 0.5 : -0.5;
			int xy = coef;
			int sum = sqx[i + H-1][j + W-1]-sqx[i-1][j+W-1]
				-sqx[i+H-1][j-1]+sqx[i-1][j-1];
			sum += sqy - xy - xy;
			if (ans<0 || ans>sum) {
				ans = sum;
				r = i, c = j;
			}
		}
	}
	printf("%d\n%d %d",ans,r,c);
	return 0;
}
