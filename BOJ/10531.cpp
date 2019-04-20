//math, FFT, d&c
#include <stdio.h>
#include <vector>
#include <math.h>
#include <complex>
#define compd complex<double>
#define ll long long
using namespace std;
const double PI = acos(-1);
void FFT(vector<compd > &F, vector<compd > &A, compd w) {
	if (A.size() == 1) F = A;
	else {
		int n = A.size();
		vector<compd > a[2], f[2];
		for (int i = 0; i < n; ++i) a[i & 1].push_back(A[i]);
		F.resize(n); n >>= 1;
		FFT(f[0], a[0], w*w); FFT(f[1], a[1], w*w);
		compd x(1);
		for (int i = 0; i < n; ++i) {
			compd odd = x * f[1][i];
			F[i] = f[0][i] + odd;
			F[i + n] = f[0][i] - odd;
			x *= w;
		}

	}
}
int main() {
	vector<compd > A;
	int i, N, M;
	int p = 1 << 19;
	A.resize(p);
	for (scanf("%d", &N); N--;) {
		int k; scanf("%d",&k);
		A[k] = 1;
	}A[0] = 1;
	double theta = (PI + PI) / p;
	compd w(cos(theta), sin(theta));
	FFT(A, A, w);
	for (i = 0; i < p; ++i) A[i] *= A[i];
	w = compd(cos(-theta), sin(-theta));
	FFT(A, A, w);
	int ans = 0;
	for (scanf("%d", &M); M--;) {
		int d; scanf("%d",&d);
		ans += int(0.01+A[d].real()) != 0;
		//printf("%d,%d\n",d,int(A[d].real()+0.01));
	}
	//for (i = 0; i < p; ++i) printf("%d\n",int(A[i].real()+0.01));
	printf("%d",ans);
	return 0;
}
