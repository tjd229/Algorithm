//math
#include <stdio.h>
#include <vector>
#define AND 0
#define OR 1
#define XOR 2
using namespace std;
vector<int> v[1 << 16];
int a[1 << 16],x[1<<16];
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
	for (i = 1; i < n; ++i) {
		x[i] = qry(XOR, 0, i);
		v[x[i]].push_back(i);
	}
	int piv = -1;
	if (v[0].size()) piv = 0,v[0].push_back(0);
	for (i = 1; i < n && piv < 0; ++i) {
		if (v[i].size() > 1) piv = i;
	}
	if (piv < 0) {
		i = v[n - 1][0]; int j = i == 1 ? 2:1;
		int a0i = x[i];
		int a0j = x[j] + (qry(AND,0,j)<<1);
		int aij = (x[i] ^ x[j]) + (qry(AND,i,j)<<1);
		a[0] = (a0j + a0i - aij)>>1;
		for (i = 1; i < n; ++i) a[i] = a[0] ^ x[i];
	}
	else {
		i = v[piv][0];
		a[i] = qry(AND, v[piv][1], i);
		a[0] = a[i] ^ x[i];
		for (i = 1; i < n; ++i) a[i] = a[0] ^ x[i];		
	}
 
 
	for (printf("!"),i = 0; i < n; ++i)
		printf(" %d",a[i]);
	fflush(stdout);
 
	return 0;
}
