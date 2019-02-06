//implementation
#include <string>
#include <iostream>
using namespace std;
string f;
int N;
int perm[51];
void print() {
	for (int i = 0; i < N; ++i) cout << perm[i] << " ";
}
bool bf(int fix,int pix, long long stat) {
	if (fix == f.size() || pix == N) {
		if (fix == f.size() && pix == N) {
			print();
			return 1;
		}
		return 0;
	}
	int n = f[fix] - '0';
	if (n && 0 == (stat&(1LL << n))) {
		stat |= (1LL << n);
		perm[pix] = n;
		if (bf(fix + 1, pix + 1, stat)) return 1;
		stat -= (1LL << n);
	}
	if (fix + 1 < f.size()) {
		n = n * 10 + f[fix + 1] - '0';
		if (n && n <= N && 0 == (stat&(1LL << n))) {
			stat |= (1LL << n);
			perm[pix] = n;
			if (bf(fix + 2, pix + 1, stat)) return 1;
		}
	}
	return 0;
}
int main() {
	cin >> f;
	if (f.size() <10) {
		for (auto c : f) cout << c << " ";
	}
	else {
		N = 9+((f.size() - 9) >> 1);
		bf(0, 0, 0);
	}
	return 0;
}