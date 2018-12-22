//graph

#include <stdio.h>
#define ll long long
int to[1000001];
int vis[1000001];
int m[1000001];
int a[1000001],pos[1000001];
ll dfs(int x,int &mn,int &cnt) {
	if (vis[x]) return 0;
	if (m[a[x]] < mn) mn = m[a[x]];
	vis[x] = 1;
	return dfs(to[x], mn,++cnt) + m[a[x]];
}
int main() {
	int i, n;
	int piv = 1e5;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", m + i);
		if (piv > m[i]) piv = m[i];
	}
	for (i = 1; i <= n; ++i) {
		scanf("%d",a+i);
		pos[a[i]] = i;
	}
	for (i = 1; i <= n; ++i) {
		int b;
		scanf("%d",&b);
		to[pos[b]] = i;
	}
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		int mn = 1e5;
		int cnt = 0;
		ll res = dfs(i,mn,cnt);
		if (cnt == 2) ans += res;
		else if (cnt > 2) {
			res += (ll)mn*(cnt-2);
			ll use_piv = mn + mn + piv + piv + (ll)(cnt-1) * (piv-mn);
			if (use_piv < 0) res += use_piv;
			ans += res;
		}
	}
	printf("%lld",ans);
	return 0;
}
