//https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007543d8
//math

#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
ll N[500];
ll decomp(ll x,vector<int> &p) {
	ll sum = 0;
	for (int i = 0; i < p.size() && x>1; ++i) {
		int cnt = 0;
		while (x%p[i] == 0) {
			x /= p[i];
			++cnt;
			sum += p[i];
		}
		if (cnt > N[p[i]]) return -1;
	}
	if (x > 1) return -1;
	return sum;
}
int main() {
	int x, T;
	for (scanf("%d", &T), x = 1; x <= T; ++x) {
		int i,M; vector<int> p;
		ll s = 0;
		for (scanf("%d", &M), i = 0; i < M; ++i) {
			int P; scanf("%d",&P);
			p.push_back(P);
			scanf("%lld",N+P);
			s += N[P] * P;
		}
		ll y = 0;
		ll st = s - 60*499;
		if (st < 2) st = 2;
		for (; st < s; ++st) {
			ll rsum = decomp(st, p);
			if (rsum != -1 && s-rsum==st) 
				y = st;
			
		}

		printf("Case #%d: %lld\n",x,y);
	}


	return 0;
}