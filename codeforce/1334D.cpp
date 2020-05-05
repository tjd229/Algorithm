//graph, bs, greedy
#include <stdio.h>
#define ll long long
ll s[100002];
int main() {
	int T;
	int i,bnd = 1e5;
	for (i = bnd; i > 0; --i)
		s[i] = s[i + 1] + 2;
	for (i = 1; i <= bnd; ++i) s[i] += s[i - 1];
	
	for (scanf("%d", &T); T--;) {
		int n; 
		ll l, r;
		scanf("%d%I64d%I64d",&n,&l,&r);
		int L = bnd - (n-1) + 1;//s[?]-s[L-1]
		int st = L, ed = bnd;
		int seg = -1;//head seg
		//printf("%d~%d\n",st,ed);
		while (st <= ed) {
			int m = (st + ed) >> 1;
			//printf("%d\n", m);
			if (s[m-1] - s[L - 1]+1<= l) {
				seg = m;
				st = m + 1;
			}
			else ed=m-1;			
		}
		//printf("seg:%d\n",seg);
		int head = seg - L + 1;
		ll k = l - (s[seg-1] - s[L - 1])-1;
		int val = head + 1 + (k >> 1);
		//printf("%d,%d,%d\n",head,val,k);
		ll src = (ll)n * (n - 1) + 1;
		for (; l <= r && l < src; ++l) {
			if (l & 1) printf("%d ",head);
			else {
				printf("%d ",val);
				++val;
				if (val > n) {
					++head;
					val = head + 1;
				}
			}
		}
		if (l <= r) printf("1");
		printf("\n");
	}
 
	return 0;
}