//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[3001];
int mx,n;
int acc(int s) {
	int piv = 0;
	for (int i = 1; i <= s; ++i) piv += a[i];
	
	if (piv < mx) return -1;
	int stk = 0; int op = s - 1;
	int last = s;
	for (int i = s + 1; i <= n; ++i) {
		if (last + 1 != i) ++op;
		stk += a[i];
		if (stk == piv) {
			last = i;
			stk = 0;
		}
		else if (stk > piv) return -1;
	}
	if (stk) return -1;
	return op;
	
}
int main(){
	
	int t;
	for (scanf("%d", &t); t--;) {
		int i;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		mx = *max_element(a + 1, a + 1 + n);
		bool same = 1;
		for (i = 2; i <= n && same; ++i)
			if (a[i - 1] != a[i]) same = 0;
		if (same)
			printf("0\n");
		else {
			int ans = n - 1;
			for (i = 1; i <= n; ++i) {
				int op = acc(i);
				//printf("%d,%d\n",i,op);
				if (op >= 0 && ans > op) ans = op;
			}
			printf("%d\n",ans);
		}
	}
 
	return 0;
}