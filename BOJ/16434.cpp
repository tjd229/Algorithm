//math
#include <stdio.h>
#define ll long long
int N;
ll atk;
int main() {
	int i;
	int t, a;
	ll h;
	ll hp = 0;
	ll ans = 0;
	for (scanf("%d%lld", &N, &atk), i = 1; i <= N; ++i) {		
		scanf("%d%d%lld", &t, &a, &h);
		if (t == 1) {
			h -= atk;
			if (h > 0) {
				ll turn = h / atk + (h % atk>0);
				hp -= turn * a;
			}
		}
		else {
			atk += a;
			hp += h;
			if (hp > 0) hp = 0;
		}
		if (ans > hp) ans = hp;
	}
	printf("%lld",-ans+1);
	return 0;
}
