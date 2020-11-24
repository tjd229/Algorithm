//math
#include <stdio.h>
#define AND 0
#define OR 1
#define XOR 2
int a[1 << 16];
int qry(int op, int i, int j) {
	++i; ++j;
	if (op == AND) printf("AND ");
	else if (op == OR) printf("OR ");
	else printf("XOR ");
	printf("%d %d\n", i, j); fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
int main() {
	int i, n; scanf("%d",&n);
	int x01 = qry(XOR, 0, 1), x12 = qry(XOR, 1, 2);
	int x02 = x12 ^ x01;
	int a01 = x01 + (qry(AND, 0, 1) << 1);
	int a12 = x12 + (qry(AND, 2, 1) << 1);
	int a02 = x02 + (qry(AND, 0, 2) << 1);
	
	a[0] = (a01 + a02 - a12) >> 1;
	a[1] = (a01 + a12 - a02) >> 1;
	a[2] = (a02 + a12 - a01) >> 1;
	for (i = 3; i < n; ++i)
		a[i] = a[i - 1] ^ qry(XOR,i-1,i);
	for (printf("!"),i = 0; i < n; ++i)
		printf(" %d",a[i]);
	fflush(stdout);
 
	return 0;
}