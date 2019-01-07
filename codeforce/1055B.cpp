//djs

#include <stdio.h>
int p[100002];
int len[100002];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}
int main() {
	int n, m, l;
	int i;
	int cnt = 0;
	for (scanf("%d%d%d", &n, &m, &l), i = 1; i <= n; ++i) {
		scanf("%d",len+i);
		p[i] = i;
		if (len[i] > l) {
			++cnt;
			if (len[i - 1] > l) {
				cnt -= join(i - 1, i);
			}
		}
	}
	while (m--) {
		int t;
		scanf("%d",&t);
		if (t) {
			int p, d;
			scanf("%d%d",&p,&d);
			if (len[p] <= l) {
				len[p] += d;
				if (len[p] > l) {
					++cnt;
					if (len[p - 1] > l) cnt -= join(p-1,p);
					if (len[p + 1] > l) cnt -= join(p,p+1);
				}
			}
		}
		else printf("%d\n",cnt);
	}
	

	return 0;
}
