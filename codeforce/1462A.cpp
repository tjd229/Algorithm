//greedy
#include <stdio.h>
int b[301],a[301];
int main(){
	int t; 
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i)scanf("%d",b+i);
		int l = 1, r = n;
		int it = 1;
		while (l <= r) {
			a[it++] = b[l++];
			if (l <= r) a[it++] = b[r--];
		}
		for(i = 1; i <= n; ++i) printf("%d ",a[i]);
		puts("");
	}
 
	return 0;
}