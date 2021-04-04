//math

#include <stdio.h>
#include <map>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9 + 7;
int a[200001];
map<pii, int> st;
map<int, int> mp[200001];
void decomp(int x,map<int,int> &xmap) {
	for (int i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			while (x%i == 0) {
				++xmap[i];
				x /= i;
			}
		}
	}
	if (x > 1) ++xmap[x];
}
int main() {
	int i, n, q;
	ll gcd = 1;
	for (scanf("%d%d", &n, &q), i = 1; i <= n; ++i) {
		scanf("%d",a+i);
		decomp(a[i], mp[i]);
		for (auto it : mp[i]) {
			int x = it.first;
			for (int j = 1; j <= it.second; ++j) {
				pii p = {x,j};
				if(++st[p]==n)
					gcd = gcd * x % mod;
			}
		}
	}
 
	while (q--) {
		int x; scanf("%d%d",&i,&x);
		map<int, int> xmap; decomp(x, xmap);
		for (auto it : xmap) {
			int y = it.first;
			for (int j = 1; j <= it.second; ++j) {
				pii p = { y,++mp[i][y] };
				if(++st[p]==n)
					gcd = gcd * y % mod;
			}
		}
		printf("%I64d\n",gcd);
	}
 
	return 0;
}