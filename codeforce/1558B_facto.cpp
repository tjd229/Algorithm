//math, dp
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, m;
int p[4000001];
ll d[4000001];
vector<int> _div(int x) {
	vector<int> v = { 1 };
	while (x > 1) {
		int num = p[x]; int base = num;
		vector<int> ex;
		while (x%num == 0) {
			x /= num;
			for (auto d : v)
				ex.push_back(d*base);
			base *= num;
		}
		v.insert(v.end(), ex.begin(), ex.end());
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	return v;
}
int main() {
	//
	scanf("%d%d",&n,&m);
	for (int i = 2; i <= n; ++i) {
		if (p[i]) continue;
		p[i] = i;
		for (int j = i + i; j <= n; j += i)p[j] = i;
	}
	d[1] = 1; d[2] = 2;
	for (int i = 3; i <= n; ++i) {
		vector<int> divs = _div(i);
		for (auto x : divs) {
			if (x<i) {
				d[i] += (d[x] - d[x - 1] + m) % m;
				d[i] %= m;
			}
		}
		d[i] = (d[i]+d[i - 1] + d[i - 1] ) % m;
	}
	printf("%d",d[n]);
 
	return 0;
}