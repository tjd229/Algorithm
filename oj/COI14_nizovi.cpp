//bs
#include <stdio.h>
int _cmp(int X,int Y) {
	if (X == Y) return 0;
	printf("cmp %d %d\n", X, Y); fflush(stdout);
	int res; scanf("%d",&res);
	return res;
}
void _rev(int X,int Y) {
	if (X < Y) {
		printf("reverse %d %d\n", X, Y); fflush(stdout);
	}
}
int main() {
	int Na, Nb, i; scanf("%d%d",&Na,&Nb);
	int l, r;
	int sa = 1, sb = 1;
	int X, Y;
	int aix = 1, bix = Na + 1;
 
	while (bix<=Na+Nb && _cmp(bix-1,bix)>0) {
		while (sa < Na && _cmp(aix, bix) <= 0) ++aix, ++sa;
      	while (sa < Na && _cmp(aix, aix+1) == 0) ++aix, ++sa;
		l = bix, r = Na + Nb;
		Y = l;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (_cmp(aix, m) < 0) r = m - 1;
			else Y = m, l = m + 1;
		}
		_rev(aix, Y); _rev(aix, aix+Y - bix); _rev(aix+Y-bix+1, Y);
		aix += Y - bix + 1;
		bix = Y + 1;
	}
	printf("end\n"); fflush(stdout);
	
	return 0;
}