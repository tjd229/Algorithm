//dp
#include <stdio.h>
#include <memory.h>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
int a[1001], m[1001];
int n;
ll sim(int piv) {
	deque<pii > up, dn;
	up.push_back({ 0,0 });
	for (int i = 1; i <= piv; ++i) {
		while (up.back().first > m[i])
			up.pop_back();
		up.push_back({m[i],i});
	}
	dn.push_back({ 0,n + 1 });
	for (int i = n; i > piv; --i) {
		while (dn.front().first > m[i])
			dn.pop_front();
		dn.push_front({m[i],i});
	}
	int h = up.back().first;
	for (int i = piv; i > 0; --i) {
		if (up.back().second == i) {
			up.pop_back();
			h = m[i];
		}
		a[i] = h;
	}
	h = dn.front().first;
	for (int i = piv + 1; i <= n; ++i) {
		if (dn.front().second == i) {
			dn.pop_front();
			h = m[i];
		}
		a[i] = h;
	}
	ll sum = 0;
	for (int i = 1; i <= n; ++i) sum += a[i];
	return sum;
}
int main() {
	int i;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",m+i);
	int pick = 0;
	ll mx = 0;
	for (i = 0; i <= n; ++i) {
		ll sum = sim(i);
		if (mx < sum) {
			mx = sum;
			pick = i;
		}
	}
	sim(pick);
	for (i = 1; i <= n; ++i) printf("%d ",a[i]);
	return 0;
}