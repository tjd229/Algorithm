//category : st



#include <stdio.h>
#define LEAF (2<<20)
int st[LEAF + LEAF];
void insert(int ix, int diff){
	st[ix] += diff;
	if (ix != 1) insert(ix / 2, diff);
}
int candy(int ix, int order){
	st[ix]--;
	if (ix >= LEAF){
		return ix - LEAF + 1;
	}
	if (st[ix * 2] >= order){
		return candy(ix * 2, order);
	}
	else return candy((ix * 2) + 1, order - st[ix * 2]);
}
int main(){
	int n;
	int A, B, C;
	for (scanf("%d", &n); n--;){
		scanf("%d", &A);
		if (A == 1){
			scanf("%d", &B);
			printf("%d\n", candy(1, B));
		}
		else if (A == 2){
			scanf("%d%d", &B, &C);
			insert(LEAF - 1 + B, C);

		}
	}
	return 0;
}