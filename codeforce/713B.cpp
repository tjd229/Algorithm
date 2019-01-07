//bs, geometry

#include <stdio.h>
int col[4], row[4];
int ixes[3][4] = { {0,1,2,3},{0,2,1,3},{0,3,1,2} };
void rbs(int arg[4], int ref, int lb) { //ref=y
	int l = arg[ref]; //
	int r = arg[2 + ref];
	int &piv = arg[2 + ref];
	int res = 0;
	int cnt;
	while (l <= r) {
		int m = (l + r) >> 1;
		piv = m;
		printf("? %d %d %d %d\n", arg[0], arg[1], arg[2], arg[3]); fflush(stdout);
		scanf("%d", &cnt);
		if (cnt >= lb)
			r = m - 1;
		else l = m + 1;
	}
	piv = r + 1;
	//printf("piv:%d\n", piv); fflush(stdout);
}
void lbs(int arg[4], int ref, int lb) {
	int r = arg[2+ref];  //
	int l = arg[ref];
	int &piv = arg[ref];
	int res = 0;
	int cnt;
	while (l <= r) {
		int m = (l + r) >> 1;
		piv = m;
		printf("? %d %d %d %d\n", arg[0], arg[1], arg[2], arg[3]); fflush(stdout);
		scanf("%d", &cnt);
		if (cnt >= lb)
			l = m + 1;
		else r = m - 1;
	}
	piv = l-1;
	//printf("piv:%d\n", piv); fflush(stdout);
}
int main() {
	int i,j;
	int n,cnt1,cnt2;
	int t = 0;
	int arg[4];
	scanf("%d",&n);
	arg[0] = arg[1] = 1;
	arg[2] = arg[3] = n;
	rbs(arg, 0,2);
	col[3] = arg[2]; //arg[2]<=n
	lbs(arg, 0,2);
	col[0] = arg[0];
	rbs(arg, 0, 1);
	col[2] = arg[2];
	arg[2] = col[3];
	lbs(arg, 0, 1);
	col[1] = arg[0];
	arg[0] = col[0];

	rbs(arg, 1, 2);
	row[3] = arg[3];
	lbs(arg, 1, 2);
	row[0] = arg[1];
	rbs(arg, 1, 1);
	row[2] = arg[3];
	arg[3] = row[3];
	lbs(arg, 1, 1);
	row[1] = arg[1];
	if (col[1] > col[2]) col[1] ^= col[2] ^= col[1] ^= col[2];
	if (row[1] > row[2]) row[1] ^= row[2] ^= row[1] ^= row[2];
	for (i = 0; i < 3; ++i) {
		int *cx = ixes[i];
		for (j = 0; j < 3; ++j) {
			int *rx = ixes[j];
			printf("? %d %d %d %d\n", col[cx[0]], row[rx[0]], col[cx[1]], row[rx[1]]); fflush(stdout);
			scanf("%d", &cnt1);
			printf("? %d %d %d %d\n", col[cx[2]], row[rx[2]], col[cx[3]], row[rx[3]]); fflush(stdout);
			scanf("%d", &cnt2);
			if (cnt1 + cnt2 == 2) {
				printf("! ");
				printf("%d %d %d %d ", col[cx[0]], row[rx[0]], col[cx[1]], row[rx[1]]);
				printf("%d %d %d %d\n", col[cx[2]], row[rx[2]], col[cx[3]], row[rx[3]]); fflush(stdout);
				return 0;
			}

			printf("? %d %d %d %d\n", col[cx[0]], row[rx[2]], col[cx[1]], row[rx[3]]); fflush(stdout);
			scanf("%d", &cnt1);
			printf("? %d %d %d %d\n", col[cx[2]], row[rx[0]], col[cx[3]], row[rx[1]]); fflush(stdout);
			scanf("%d", &cnt2);
			if (cnt1 + cnt2 == 2) {
				printf("! ");
				printf("%d %d %d %d ", col[cx[0]], row[rx[2]], col[cx[1]], row[rx[3]]);
				printf("%d %d %d %d\n", col[cx[2]], row[rx[0]], col[cx[3]], row[rx[1]]); fflush(stdout);
				return 0;
			}
		}
	}
	
	return 0;
}
