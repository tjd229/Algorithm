//bs
#include <iostream>
#include <string>
#define ll long long
using namespace std;
int x1, x2, y1, y2;
int n;
int dx[100000], dy[100000];
ll cx, cy;
string s;
ll ans;
inline ll md(ll x1, ll y1, ll x2, ll y2) {
	ll dx = x1 - x2;
	if (dx < 0) dx = -dx;
	ll dy = y1 - y2;
	if (dy < 0) dy = -dy;
	return dx + dy;
}
bool sim(ll cycle) {
	ll cnt = cycle * n;
	ll x = x1 + cycle * cx;
	ll y = y1 + cycle * cy;
	for (int i = 0; i < n; ++i) {
		ll dist = md(x,y,x2,y2);
		if (dist <= cnt) {
			if (ans<0 ||ans > cnt) ans = cnt;
			return 1;
		}
		++cnt;
		x += dx[i]; y += dy[i];
	}
	ll dist = md(x, y, x2, y2);
	if (dist <= cnt) {
		if (ans<0 || ans > cnt) ans = cnt;
		return 1;
	}
	return 0;
}
int main() {
	int i;
	cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
	for (i = 0; i < n; ++i) {
		char c = s[i];
		if (c == 'U')++cy, ++dy[i];
		else if (c == 'D') --cy, --dy[i];
		else if (c == 'L') --cx, --dx[i];
		else ++cx, ++dx[i];
	}
	ll l, r;
	l = 0;
	r = 2e9;
	ans = -1;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (sim(m)) r = m - 1;
		else l = m + 1;
	}
	cout << ans;
	return 0;
}
