//math
#include "Brunolib.h"
long long Bruno(int N, int A[]) {
	long long X = 0;
	int recon[70] = { 0 };
	int pos = 0;
	for (int i = 0; i < N; i += 3) {
		int mask = (A[i] << 2) + A[i + 1] + A[i + 1] + A[i + 2];
		if (mask == 1 || mask == 6) recon[pos++] = 1;
		else if (mask == 2) pos += 2;
		else if (mask == 3) recon[++pos] = 1, ++pos;
		else if (mask == 4) ++pos;
		else if (mask == 5) recon[pos++] = 1, ++pos;
		else if (mask == 7)
			recon[pos] = recon[pos + 1] = 1, pos += 2;
	}
	//printf("%d\n",pos);
	pos = 60;
	while (pos--) {
		X <<= 1;
		X += recon[pos];
	}
	return X;
}