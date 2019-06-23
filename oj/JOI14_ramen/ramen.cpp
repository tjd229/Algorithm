//d&c
#include "ramen.h"
int X[400], Y[400];
int XSZ, YSZ;
void Ramen(int N) {
	for (int i = 0; i < N; i += 2) {
		if (i + 1 == N) {
			X[XSZ++]=i;
			Y[YSZ++] = i;
		}
		else if (Compare(i, i + 1)>0) {
			Y[YSZ++] = i;
			X[XSZ++] = i + 1;
		}
		else {
			Y[YSZ++] = i+1;
			X[XSZ++] = i;
		}
	}
	for (int i = 1; i < XSZ; ++i) {
		if (Compare(X[0], X[i]) > 0) X[0] ^= X[i] ^= X[0] ^= X[i];
	}
	for (int i = 1; i < YSZ; ++i) {
		if (Compare(Y[0], Y[i]) < 0) Y[0] ^= Y[i] ^= Y[0] ^= Y[i];
	}
	Answer(X[0],Y[0]);
}
