//math, bs, greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int a[200001];
ll b[200001];
int coef[200001];
ll cst[200001];
int main() {
	int i, n, q;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i),coef[i]=-1;
	for (i = 1; i <= n; ++i) scanf("%I64d",b+i);
	for (i = 2; i <= n; ++i) {
		b[i] -= a[i]; a[i] = 0;
		cst[i] += b[i];
		for (int j = i + i; j <= n; j += i) {
			coef[j] -= coef[i];
			cst[j] -= cst[i];
		}
	}
	ll base = 0;
	vector<pair<ll,int> > rank[2];
	vector<ll> cum_coef[2], cum_cst[2];
	for (i = 2; i <= n; ++i) {
		//printf("%d,%lld\n",coef[i],cst[i]);
		if (coef[i] == 0) base += abs(cst[i]);
		else if (coef[i] > 0) {
			ll div = -cst[i] / coef[i];
			if (div >= 0 && (-cst[i]) % coef[i]) ++div;
			rank[0].push_back({div, i});
		}
		else {
			ll div = -cst[i] / coef[i];
			if (div <= 0 && (cst[i]) % (-coef[i]) ) --div;
			rank[1].push_back({ div, i });
		}
	}
	for (i = 0; i < 2; ++i) {
		sort(rank[i].begin(), rank[i].end());
		for (auto p : rank[i]) {
			int ix = p.second;
			//printf("%d:%d,%d\n",i,p.first,p.second);
			cum_coef[i].push_back(coef[ix]);
			cum_cst[i].push_back(cst[ix]);
		}
		for (int j = 1; j < cum_coef[i].size(); ++j) cum_coef[i][j] += cum_coef[i][j - 1];
		for (int j = 1; j < cum_cst[i].size(); ++j) cum_cst[i][j] += cum_cst[i][j - 1];
	}
	for (scanf("%d", &q); q--;) {
		int x; scanf("%d",&x);
		x = x - a[1];
		//x = abs(x);
		ll ans = base + abs(x);
		if (rank[0].size()) {
			pair<ll, int> p = { x,0 };
			auto it = lower_bound(rank[0].begin(), rank[0].end(), p);

			ll pre_coef, pre_cst, post_coef, post_cst;
			pre_coef = pre_cst = 0;
			post_coef = cum_coef[0].back();
			post_cst = cum_cst[0].back();

			if (it != rank[0].begin()) {
				int len = it - rank[0].begin() - 1;
				pre_coef = cum_coef[0][len];
				pre_cst = cum_cst[0][len];
				post_coef -= pre_coef;
				post_cst -= pre_cst;
			}
			ans += abs(post_cst + post_coef * x);
			ans += abs(pre_cst + pre_coef * x);
		}
		if (rank[1].size()) {
			pair<ll, int> p = { x,1e9 };
			auto it = upper_bound(rank[1].begin(), rank[1].end(), p);

			ll pre_coef, pre_cst, post_coef, post_cst;
			pre_coef = pre_cst = 0;
			post_coef = cum_coef[1].back();
			post_cst = cum_cst[1].back();

			if (it != rank[1].begin()) {
				int len = it - rank[1].begin() - 1;
				pre_coef = cum_coef[1][len];
				pre_cst = cum_cst[1][len];
				post_coef -= pre_coef;
				post_cst -= pre_cst;
			}
			//printf("x:%d\n",x);
			//printf("%lld,%lld\n", pre_cst, pre_coef);
			//printf("%lld,%lld\n", post_cst, post_coef);
			ans += abs(post_cst + post_coef * x);
			ans += abs(pre_cst + pre_coef * x);
		}
		printf("%I64d\n",ans);
	}
	
	

	return 0;
}