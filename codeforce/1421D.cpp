//math, geometry
#include <stdio.h>
#define ll long long
const int dx[6] = {1,1,0,-1,-1,0};
const int dy[6] = {1,0,-1,-1,0,1};
int c[6];
ll axis_x(ll x) {
	if (x > 0) return c[1] * x;
	else return c[4] * -x;
}
ll axis_y(ll y) {
	if (y > 0) return c[5] * y;
	else return c[2] * -y;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int x, y; scanf("%d%d",&y,&x);
		for (int i = 0; i < 6; ++i) scanf("%d",c+i);
		ll ans,cost;
		if (y > 0) {
			ans = c[5] * (ll)y + axis_x(x);
			cost = c[0] * (ll)y + axis_x(x-y);
			if (ans > cost) ans = cost;
		}
		else {
			ans = c[2] * (ll)-y + axis_x(x);
			cost = c[3] * (ll)-y + axis_x(x - y);//y<0
			if (ans > cost) ans = cost;
		}
		if (x > 0) {
			cost = c[0] * (ll)x + axis_y(y - x);
			if (ans > cost) ans = cost;
		}
		else {
			cost = c[3] * (ll)-x + axis_y(y-x);//x<0
			if (ans > cost) ans = cost;
		}
		printf("%I64d\n",ans);
		
	}

	return 0;
}