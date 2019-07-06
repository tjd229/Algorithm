//math
#include "Annalib.h"

void Anna(int N, long long X, int K, int P[]) {
	int A[150];
	for (int i = 0; i < N; ++i) A[i] = 1;
	for (int i = 0; i < K; ++i) A[P[i]] = 0;
	
	for (int i = 0; i < N ; i += 3) {
		int s = A[i] + A[i + 1] + A[i + 2];
		if (!s) continue;
		if (X & 1) {
			if ((X & 2) && s == 3) X >>= 2;//111
			else if ((X & 2) == 0 && (A[i + 2] & A[i])) X >>= 2, A[i + 1] = 0;//101
			else if (A[i + 2]) A[i] = A[i + 1] = 0, X >>= 1;//001 or 110
			else if (A[i + 1] & A[i]) A[i + 2] = 0, X >>= 1;
			else A[i] = A[i + 1] = A[i + 2] = 0;
		}
		else{
			if ((X & 2) && A[i+1] + A[i + 2] == 2) {//011[01]
				A[i] = 0;
				X >>= 2;
			}
			else if ((X & 2) == 0 && A[1+i]) {//010[00]
				A[i] = A[i + 2] = 0;
				X >>= 2;
			}
			else if (A[i]) {//100
				A[i+1] = A[i + 2] = 0;
				X >>= 1;
			}
			else A[i] = A[i + 1] = A[i + 2] = 0;
		}
		

	}
	for (int i = 0; i < N; ++i) Set(i, A[i]);
}
