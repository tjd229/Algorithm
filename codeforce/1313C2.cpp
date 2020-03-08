//dp

#include <stdio.h>
#include <queue>
#define pii pair<int,int>
#define ll long long
using namespace std;
int m[500001], a[500001];
ll froml[500001], fromr[500002];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i)scanf("%d",m+i);
	deque<pii > dq; dq.push_back({0,0});
	ll sum = 0;
	for (i = 1; i <= n; ++i) {
		int r = i;
		while (dq.back().first > m[i]) {
			int l = dq.back().second;
			int h = dq.back().first;
			dq.pop_back();
			ll len = r - l;//l+1~r
			sum -= len*(h - m[i]);
			r = l;
		}
		dq.push_back({m[i],r});
		sum += m[i];
		froml[i] = sum;
	}
	dq.clear(); dq.push_back({0,n+1});
	sum = 0;
	for (i = n; i > 0; --i) {
		int l = i;
		while (dq.front().first > m[i]) {
			int r = dq.front().second;
			int h = dq.front().first;
			dq.pop_front();
			ll len = r - l;
			sum -= len * (h-m[i]);
			l = r;
		}
		dq.push_front({m[i],l});
		sum += m[i];
		fromr[i] = sum;
	}
	ll mx = 0;
	int piv = 0;
	for (i = 0; i <= n; ++i) {
		if (mx < froml[i] + fromr[i + 1]) {
			mx = froml[i] + fromr[i + 1];
			piv = i;
		}
	}
	dq.clear(); dq.push_back({0,0});
	for (i = 1; i <= piv; ++i) {
		while (dq.back().first > m[i])
			dq.pop_back();
		dq.push_back({m[i],i});
	}
	int h = dq.back().first;
	for (i = piv; i > 0; --i) {
		if (dq.back().second == i) {
			h = dq.back().first;
			dq.pop_back();
		}
		a[i] = h;
	}
	dq.clear(); dq.push_back({ 0,n + 1 });
	for (i = n; i > piv; --i) {
		while (dq.front().first > m[i])
			dq.pop_front();
		dq.push_front({m[i],i});
	}
	h = dq.front().first;
	for (i = piv + 1; i <= n; ++i) {
		if (dq.front().second == i) {
			h = dq.front().first;
			dq.pop_front();
		}
		a[i] = h;
	}
	
	for (i = 1; i <= n; ++i)printf("%d ",a[i]);
	return 0;
}