//math, greedy
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
vector<int> lb[63];
int val[300001],sign[300001];
ll mask[300001];
int pop_cnt(ll n) {
	int res = 0;
	while (n) {
		++res;
		n -= (n&-n);
	}
	return res;
}
int main() {
	int i, n;
	ll sum = 0,s=0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d%I64d", val + i, mask + i); sign[i] = 1;
		sum += val[i];
		int j = 0; ll b = mask[i]>>1;
		while (b) {
			++j;
			b >>= 1;
		}
		lb[j].push_back(i);
	}
	if (sum < 0) {
		sum = -sum;
		for (i = 1; i <= n; ++i) val[i] = -val[i];
	}
	for (i = 0; i < 63 && sum>=0; ++i) {
		sum = 0;
		for (auto x : lb[i]) sum += val[x]*sign[x];
		if (sum > 0)
			s += (1LL << i);			
		sum = 0;
		for (int j = 1; j <= n; ++j) {
			int cnt = pop_cnt(mask[j] & s);
			if (cnt & 1) sign[j] = -1;
			else sign[j] = 1;
			sum += val[j] * sign[j];
		}
	}
	printf("%I64d",s);
	return 0;
}