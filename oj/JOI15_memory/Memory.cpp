//line sweeping, math
#include "Memory_lib.h"


int concat(int l,int r,int op,int mode) {
	return mode + (op << 2) + (r << 8) + (l << 15);
}
int Memory(int N, int M) {
	if (N & 1) return -2;
	int sq6 = 64;
	int sq7 = 128;
	int mode = M & 3; M >>= 2;
	int op = M & (sq6 - 1); M >>= 6;
	int r = M & (sq7 - 1); // i
	int l = M >> 7; //j
	//printf("%d,%d,%d,%d\n",l,r,op,mode);
	if (r == N)
		return op ? -2 : -1;
	if (l == N) return -2;

	char c = Get(l + 1);
	if (l == r) {
		++l;
		if (c == ']' || c == '>') {
			if (--op < 0) return -2;
			return concat(l,++r,op,mode);
		}
		else {
			mode = (c == '[') + 1;
			op = 1;
			return concat(l, r, op, mode);
		}
	}
	else {
		switch (c) {
		case '<':case '[':
			++op;
			break;
		case '>':
			--op;
			if (op < 0) return -2;
			if (l > r && op == 0) {
				if (mode != 1) return -2;
				return concat(0, ++r, op, 0);
			}
			break;
		case ']':
			--op;
			if (op < 0) return -2;
			if (l > r && op == 0) {
				if (mode != 2) return -2;
				return concat(0, ++r, op, 0);
			}
			break;
		}
		++l;
	}
	//op>50 chk
	if (op > (N >> 1)) return -2;
	return concat(l,r,op,mode);
}
