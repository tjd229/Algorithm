//math
#include <stdio.h>
#include <time.h>
#include <random>
int nxt[50001], val[50001];
int main() {
	int i;
	int n, s, x;
	int ans = -1;
	srand(time(NULL));
	for (scanf("%d%d%d", &n, &s, &x), i = 0; i <= n; ++i) val[i] = -1;	
	if (n < 2000) {
		for (; s != -1 && ans<0;s = nxt[s]) {
			printf("? %d\n", s); fflush(stdout);
			scanf("%d%d", val + s, nxt + s);
			if (x <= val[s]) ans = val[s];
		}
		printf("! %d",ans);
	}
	else {
		for (i = 0; i < 1000; ++i) {
			int ix = rand()*rand() % n+1;
			//while (val[ix] < 0) 
				//ix = rand()*rand() % n + 1;
			printf("? %d\n", ix); fflush(stdout);
			scanf("%d%d", val + ix, nxt + ix);
			if (nxt[ix] != -1) val[nxt[ix]] = val[ix];
			if (val[ix] <= x && val[s] < val[ix]) s = ix;
			
		}
		if (x <= val[s]) ans = val[s];
		for (i=0; s != -1 && ans<0 && i<999;++i, s = nxt[s]) {
			printf("? %d\n", s); fflush(stdout);
			scanf("%d%d", val + s, nxt + s);
			if (x <= val[s]) ans = val[s];
		}
		printf("! %d", ans);
	}
	
	return 0;
}
