//bs
#include <iostream>
#include <string>
#define ll long long
using namespace std;
const string ex_cmd = "examine";
const string sol_cmd = "solution";
bool I(string cmd, int x, int y) {
	cout << cmd << " " << x << " " << y << endl;
	string flat="#";
	if (cmd[0] == 'e')cin >> flat;
	return flat[0] == 't';
}
int main() {
	int N, X0, Y0; cin >> N >> X0 >> Y0;
	ll rx,lx, last=X0,d = 1;
	ll l, r;
	while (1) {
		rx = X0 + d;
		if (rx > N) {
			rx = N;
			break;
		}
		if (!I(ex_cmd, rx, Y0)) {
			--rx;
			break;
		}
		d += d;
		last = rx;
	}
	l = last, r = rx;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (I(ex_cmd, m, Y0)) l = m + 1, rx = m;
		else r = m - 1;
	}
	d = -1; last = X0;
	while (1) {
		lx = X0 + d;
		if (lx < 1) {
			lx = 1;
			break;
		}
		if (!I(ex_cmd, lx, Y0)) {
			++lx;
			break;
		}
		d += d;
		last = lx;
	}
	l = lx, r = last;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (I(ex_cmd, m, Y0)) r = m - 1, lx = m;
		else l = m + 1;
	}
	int M = rx - lx + 1;
	X0 = lx;
	l = Y0 - M; r = Y0;
	if (l < 1) l = 1;
	while (l <= r) {
		ll m=(l + r) >> 1;
		if (I(ex_cmd, X0, m)) r = m - 1, Y0 = m;
		else l = m + 1;
	}
	for (X0 -= M + M;; X0 -= M + M) {
		if (X0 < 1 || !I(ex_cmd, X0, Y0)) {
			X0 += M + M;
			break;
		}
	}
	for (Y0 -= M + M;; Y0 -= M + M) {
		if (Y0 < 1 || !I(ex_cmd, X0, Y0)) {
			Y0 += M + M;
			break;
		}
	}
  for (Y0 -= M, X0 -= M;; Y0 -= M , X0 -=  M) {
		if (Y0 < 1 ||X0<1|| !I(ex_cmd, X0, Y0)) {
			Y0 += M;
			X0 += M;
			break;
		}
	}
	I(sol_cmd,X0+M+M+(M>>1),Y0 + M + M + (M >> 1));
	return 0;
}
