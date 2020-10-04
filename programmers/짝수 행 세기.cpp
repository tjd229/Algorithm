//dp, math
//https://programmers.co.kr/learn/courses/30/lessons/68647?language=cpp
#include <string>
#include <vector>
#include <memory.h>
#define ll long long
using namespace std;
const int mod = int(1e7) + 19;
ll f[301],invf[301];
ll d[301][301];
ll _pow(ll n,ll e=mod-2) {
	ll res = 1;
	while (e) {
		if (e & 1) 
			res = res * n%mod;
		e >>= 1;
		n = n * n%mod;
	}
	return res;
}
ll nck(int n,int k) {
	ll nume = f[n];
	ll deno = invf[k] * invf[n - k] % mod;
	return nume * deno%mod;
}
int solution(vector<vector<int>> a) {
	f[0] = f[1] = 1;
	invf[0] = invf[1] = 1;
	for (int i = 2; i <= 300; ++i) {
		f[i] = f[i - 1] * i%mod;
		invf[i] = _pow(f[i], mod - 2);
	}
	memset(d, -1, sizeof(d));
	int n = a.size(), m = a[0].size();
	vector<int> cnts(m);
	for (int j = 0; j < m; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += a[i][j];
		cnts[j] = cnt;
	}
	d[0][n - cnts[0]] = nck(n, cnts[0]);
	for (int i = 0; i < m - 1; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (d[i][j] < 0) continue;
			for (int k = 0; k <= cnts[i + 1]; ++k) {
				int even = j, odd = n - j;
				//even-k+(cnts[i+1]-k)
				int nxtj = even - k + cnts[i + 1] - k;
				if (nxtj<0 || nxtj>n) continue;
				if (even < k || odd < cnts[i + 1] - k) continue;
				int add = nck(even, k)*nck(odd, cnts[i + 1] - k) % mod;
				if (d[i + 1][nxtj] < 0) d[i + 1][nxtj] = 0;//init
				d[i + 1][nxtj] += d[i][j] * add%mod;
				d[i + 1][nxtj] %= mod;
			}
		}
	}
	//d[m-1][n]
	int ans = d[m - 1][n];
	if (ans < 0) ans = 0;
	return ans;
}