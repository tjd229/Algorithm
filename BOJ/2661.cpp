//implementation
#include <stdio.h>
int arr[81];
int N;
bool check(int ix) {
	int bnd = ix >> 1;
	for (int pad = 1; pad <= bnd; ++pad) {
		int l = ix - pad;
		int r = ix;
		bool flag = 1;
		for (; r > ix-pad; --r,--l) {
			flag &= (arr[l] == arr[r]);
		}
		if (flag) return 0;
	}
	return 1;
}
bool bf(int ix) {
	if (ix > N) {
		for (int i = 1; i <= N; ++i) printf("%d",arr[i]);
		return 1;
	}
	for (int i = 1; i <= 3; ++i) {
		arr[ix] = i;
		if (check(ix)) {
			if (bf(ix + 1)) return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d",&N);
	bf(1);
	return 0;
}