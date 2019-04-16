//math, FFT
#include <math.h>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <string>
#define ll long long
#define compd complex<double>
#define reg register
using namespace std;
const double PI = acos(-1);
const int cut = 2;
int rearr[1 << 21];
int ans[1 << 21];
int rev(int n, int k) {
	int r = 0;
	while (k--) {
		r += r + (n & 1);
		n >>= 1;
	}
	return r;
}
void FFT(vector<compd > &A, bool inv = 0) {
	for (int i = 0; i < A.size(); ++i)
		if (rearr[i]) swap(A[i], A[rearr[i]]);
	int half = 1;
	for (int step = 2; step <= A.size(); step += step) {
		double theta = (PI + PI) / step;
		if (inv) theta = -theta;
		compd ws(cos(theta), sin(theta));
		for (int i = 0; i < A.size(); i += step) {
			compd w(1);
			for (int j = 0; j < half; ++j) {
				compd odd = A[i + j + half] * w;
				A[i + j + half] = A[i + j] - odd;
				A[i + j] += odd;
				w *= ws;
			}
		}
		half = step;
	}
	for (int i = 0; inv && i < A.size(); ++i) A[i] /= A.size();
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string A, B; cin >> A >> B;
	vector<compd > a, b;
	if (A[0] == '0' || B[0] == '0') {
		cout<<0;
		return 0;
	}
	int i, num = 0;
	int base = 1;
	int bnd = 1;
	for (i = 1; i < cut; ++i, bnd *= 10);
	for (reverse(A.begin(), A.end()), i = 0; i < A.size(); ++i) {
		num += base * (A[i] - '0');
		base *= 10;
		if (base > bnd) {
			a.push_back(num);
			base = 1, num = 0;
		}
	}
	a.push_back(num); num = 0;
	base = 1;
	int mx = a.size();
	for (reverse(B.begin(), B.end()), i = 0; i < B.size(); ++i) {
		num += base * (B[i] - '0');
		base *= 10;
		if (base > bnd) {
			b.push_back(num);
			base = 1, num = 0;
		}
	}
	b.push_back(num); num = 0;
	if (mx < b.size()) mx = b.size();
	int p = 1, k = 0;
	for (; p < mx + mx; p += p) ++k;
	for (i = 0; i < p; ++i) {
		int j = rev(i, k);
		if (i < j) rearr[i] = j;
	}
	a.resize(p); b.resize(p);
	FFT(a); FFT(b);
	for (i = 0; i < p; ++i) a[i] *= b[i];
	FFT(a, 1);
	int s = 0;
	for (i = 0; i < p; ++i, s += cut)
		ans[s] = a[i].real() + 0.01;
	
	for (i = 0; i < s  || ans[i]; ++i) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	//cout << i << endl;
	while (!ans[i]) --i;
	for (; i >= 0; --i) 
		cout << ans[i];
	
	return 0;
}
