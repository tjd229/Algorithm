//dp
#include <stdio.h>
int d[300001];
int b[300001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, k, l;
		for (scanf("%d%d%d", &n, &k, &l), i = 1; i <= n; ++i) {
			scanf("%d", d + i);
			b[i] = l - d[i];
			if (b[i] > k) b[i] = k;
		}
		int kk =k+ k;
		b[0] = k;
		int atten = 0;
		int ta = 0;
		for (i = 0; i < n && b[n] >= 0; ++i) {
			//printf("%d\n", i);
			if (b[i] < 0 ) break;
			int curt = (ta+i - atten)%kk;
			if (b[i] == k) {
				atten = i + 1;
				ta = (kk - b[i+1]) % kk;//set dec possibly
			}
			else if (curt> k) {//dec
				int up = k - (curt - k);//>0
				int bnd = up - 1 < b[i + 1] ? up - 1 : b[i + 1];
				atten = i + 1;
				ta = (kk-bnd) % kk;
			}
			else if (b[i] >= b[i + 1]) {//asc
				int dt = i + 1 - atten;
				int nxtt = (ta + dt) % kk;
				int up = nxtt > k ? k - (nxtt - k) : nxtt;
				if (d[i + 1] + up > l) break;
				atten = i + 1;
				ta = nxtt;
			}
			//b[i]<b[i+1]
		}
		printf("%s\n",i==n? "Yes":"No");
	}
	return 0;
}