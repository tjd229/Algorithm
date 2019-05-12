//implementation
#include "springboard.h"
#include <stdio.h>
void Reorder(int N) {
	int rem = N>>1;
	int dir = PutBall(1+rem);
	while (rem>1) {
		int r = rem & 1;
		rem >>= 1;
		rem += r;
		if (dir > 0) dir = PutBall(N - rem + 1);// , printf("put %d, d=%d\n", N - rem + 1, dir);
		else dir = PutBall(rem);// , printf("put %d, d=%d\n", rem, dir);
	}
	//printf("d:%d\n",dir);
	//return;
	if (dir > 0) {
		dir=PutBall(N);
		if (dir < 0) PutBall(1);
	}
	else {
		dir=PutBall(1);
		if (dir < 0) PutBall(1);
	}
}
