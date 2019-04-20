//math, FFT
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <complex>
#define cpd complex<double>
using namespace std;
const double PI = acos(-1);
int rearr[(1<<19)];
int rev(int i, int k = 19) {
	int res = 0;
	while (k--) {
		res += res+(i & 1); 
		i >>= 1;
	}
	return res;
}
void FFT(vector<cpd > &A, bool inv = 0) {
	for (int i = 0; i < A.size(); ++i)
		if (rearr[i]) swap(A[i],A[rearr[i]]);
	int half = 1;
	for (int step = 2; step <= A.size(); step += step) {
		double theta = (PI + PI) / step;
		if (inv) theta = -theta;
		cpd ws(cos(theta), sin(theta));
		for (int i = 0; i < A.size(); i += step) {
			cpd w(1);
			for (int j = 0; j < half; ++j) {
				cpd odd = A[i + j + half]*w;
				A[i + j + half] = A[i + j] - odd;
				A[i + j] += odd;
				w *= ws;
			}
		}
		half = step;
	}
	for (int i = 0; i < A.size() && inv; ++i) A[i] /= A.size();
}
int main() {
	int i, N, M, p = 1 << 19;
	vector<cpd > A(p);
	for (scanf("%d", &N), A[0] = 1, i = 0; i < N; ++i) {
		int k; scanf("%d",&k);
		A[k] = 1;
	}
	for (i = 0; i < p; ++i) {
		int j = rev(i);
		if (i < j) rearr[i] = j;
	}
	FFT(A);
	for (i = 0; i < p; ++i) A[i] *= A[i];
	FFT(A, 1);
	int ans = 0;
	for (scanf("%d", &M); M--;) {//no duplicated?
		int d; scanf("%d",&d);
		ans += int(0.01 + A[d].real()) != 0;
	}
	
	printf("%d",ans);
	return 0;
}
