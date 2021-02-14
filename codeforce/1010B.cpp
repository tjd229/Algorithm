//bs
#include <stdio.h>
int p[30];
int ask(int y) {
	printf("%d\n", y); fflush(stdout);
	int resp; scanf("%d",&resp);
	return resp;
}
int main() {
	int i,m, n; scanf("%d%d",&m,&n);
	for (i = 0; i < n; ++i) {
		int resp = ask(1);
		if (resp == 0) return 0;
		p[i] = resp == 1;
	}
	int l = 2, r = m;
	int o = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		int resp = ask(m);
		if (resp == 0) return 0;
		if (p[o] == 0) resp = -resp;
		if (resp < 0) r = m - 1;
		else l = m + 1;
		o = (o + 1) % n;
	}
	return 0;
}