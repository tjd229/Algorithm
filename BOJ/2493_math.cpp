//greedy, math
//ref : http://wookje.dance/2018/03/19/boj-1493-%EB%B0%95%EC%8A%A4-%EC%B1%84%EC%9A%B0%EA%B8%B0/
#include <stdio.h>
#define ll long long
int cube[20];

int main() {
	int l, w, h;
	int N;
	int i, j;
	for (scanf("%d%d%d%d",&l,&w,&h, &N), i = 0; i < N; ++i) {
		scanf("%d",&j);
		scanf("%d", cube + j);
	}
	ll f = 0;
	ll ans = 0;
	for (i = 19; i >= 0; --i) {
		f <<= 3;
		ll x = (ll)(l >> i)*(w >> i)*(h >> i)-f;
		if (x > cube[i]) {
			if (i == 0) {
				ans = -1;
				break;
			}
			x = cube[i];
		}
		ans += x;
		f += x;

	}
	printf("%lld",ans);
	return 0;
}
//5 6 7
//3
//0 100
//1 100
//2 1
//ans:77
