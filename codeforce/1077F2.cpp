//dp

#include <stdio.h>
#include <memory.h>
#include <deque>
#define ll long long
#define pli pair<ll,int>
using namespace std;
int a[5001];
ll d[5001][5001];
deque<pli > dq[5001];
ll max(ll a, ll b) { return a < b ? b : a; }
int main() {
	int i,j;
	int n, k, x;
	ll ans = -1;
	memset(d, -1, sizeof(d));
	for (scanf("%d%d%d", &n, &k, &x), i = 1; i <= n; ++i) scanf("%d",a+i);
	for (i = 0; i <= n; ++i) dq[i].push_back({0,i});
	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= i; ++j) {
			while (dq[j].size() && i - dq[j].front().second > k) dq[j].pop_front();
		}
		for (j = 1; j<=i; ++j) {	
			//if(k>1 && dq[j].size())
				//d[i][j] = dq[j].back().first;
			//while (dq[j - 1].size() && i - dq[j - 1].front().second > k) dq[j - 1].pop_front();
			if (dq[j - 1].empty()) continue;
			d[i][j] = max(d[i][j], dq[j - 1].front().first + a[i]);
			
		}
		for (j = 1;j <= i; ++j) {
			if (d[i][j] < 0) continue;
			while (dq[j].size() && dq[j].back().first < d[i][j]) dq[j].pop_back();
			dq[j].push_back({d[i][j], i});
		}
		
	}
	for (i = 0; i < k; ++i) ans = max(ans, d[n-i][x]);
	printf("%I64d",ans);
	return 0;
}
