//dp, greedy
#include <stdio.h>
#define ll long long
int l[2001], r[2001], a[2001];
ll d[2001];
int main() {
	int i, j,n, k;
	
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d%d%d",l+i,r+i,a+i),d[i]=-1;
	for (i = 0; i < n ; ++i) {//src
		int rem = k;
		ll tot = d[i];
		for (j = i + 1;d[i]>=0 && j <= n; ++j) {
			int reload = 0;
			//printf("%d:%d,%d\n",i,a[j],rem);
			if (a[j] > rem) {
				int r = (a[j] - rem);
				reload = r / k + ((r % k )> 0);
			}
			if (r[j] - l[j] < reload) break;
			rem = rem - a[j] + (ll)k * reload;
			tot += a[j];
			
			//printf("%lld,%d,%d\n",tot,rem,reload);
			if (j == n) {
				if (d[j]<0 || d[j]>tot) d[j] = tot;
			}
			else if( r[j]-l[j]+ l[j+1]-r[j]>=reload+1){
				if (d[j]<0 || d[j]>tot + rem) d[j] = tot + rem;
			}
			
			
		}
	}
	printf("%I64d",d[n]);
	return 0;
}