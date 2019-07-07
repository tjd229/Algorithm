//greedy

#include "xylophone.h"
#include <stdio.h>
static int A[5001];//ans
int d[5001];
void solve(int N) {
	for (int i = 2; i <= N; ++i) 
		d[i] = query(i-1,i);
	A[1] = 1;
	A[2] = 1 + d[2];
	int mx = A[2], mn = 1;
	int mxi = 2, mni = 1;
	for (int i = 3; i <= N; ++i) {
		int diff = query(i-2,i);
		int sign = A[i - 2] > A[i - 1] ? -1 : 1;
		if (diff == d[i - 1]) A[i] = A[i - 1] - sign * d[i];
		else if (diff == d[i]) A[i] = A[i - 1] - sign * diff;
		else A[i] = A[i - 1] + sign * d[i];

		if (mx < A[i]) mx = A[i], mxi = i;
		if (mn > A[i]) mn = A[i], mni = i;
	}
	if (mni > mxi) {
		mn = 10000;
		for (int i = 2; i <= N; ++i) 
			d[i] = A[i] - A[i - 1];
		for (int i = 2; i <= N; ++i) {
			A[i] = A[i - 1] - d[i];
			if (mn > A[i]) mn = A[i];
		}
	}
	//for (int i = 1; i <= N; ++i) printf("%d:%d\n",i, A[i] );
	for (int i = 1; i <= N; ++i) answer(i, A[i] + 1 - mn);
}
