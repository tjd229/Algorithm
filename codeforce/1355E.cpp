//greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int h[100001];
int N, A, R, M;
void opt(ll up, ll down, ll &add, ll &rm, ll &mv) {
	mv = 0;
	if (A + R > M) {
		mv = min(up, down);
		up -= mv;
		down -= mv;
	}
	add = up;
	rm = down;
}
int main() {
	int i;
	ll r = 0,l=0;
	vector<int> v;
	for (scanf("%d%d%d%d", &N, &A, &R, &M), i = 1; i <= N; ++i)
		scanf("%d", h + i), r += h[i],v.push_back(h[i]);
	sort(h + 1, h + 1 + N);
	if (r%N) {
		for (i = 1; i <= N && (r + i) % N; ++i);
		v.push_back((r+i)/N);
		for (i = 1; i <= N && (r - i) % N; ++i);
		if (r - i > 0) v.push_back((r-i)/N);
	}
	else v.push_back(r / N);
 
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
 
	ll ans = -1;
	i = 1;
	for(auto piv:v){		
		for (; i <= N && piv == h[i]; ++i) {
			l += h[i];
			r -= h[i];
		}
		ll cnt = i - 1;
		
		ll up = cnt * piv - l;
		ll dn = r-(N - cnt)*piv;
		ll add, rm, mv;
		opt(up, dn, add, rm, mv);
		//printf("%lld,%lld,%lld,%lld,%lld\n",up,dn,add,rm,mv);
		ll cost = add * A + rm * R + mv * M;
		if (ans<0 || ans > cost) ans = cost;
		
	}
	printf("%I64d",ans);
 
}