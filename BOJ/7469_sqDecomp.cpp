//category : bs, sqrt Decomp.

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000];
int sqrt_n;
vector<int> g[400];
int query(int from,int to,int x){
	int i;
	int cnt = 0;
	if (sqrt_n == to - from&&(to-1)/sqrt_n==from/sqrt_n) 
		return lower_bound(g[from / sqrt_n].begin(), g[from / sqrt_n].end(), x) - g[from / sqrt_n].begin();
	else if (sqrt_n > to - from){		
		for (i = from; i < to; i++) cnt += (a[i] < x);
		return cnt;
	}
	int g_s = (from / sqrt_n + (from%sqrt_n != 0))*sqrt_n;
	int g_e = (to / sqrt_n)*sqrt_n;
	cnt += query(from, g_s, x);
	cnt += query(g_e, to, x);
	for (i = g_s; i < g_e; i += sqrt_n) cnt += query(i, i + sqrt_n, x);
	return cnt;
}
int main(){
	int i, j, k;
	int n, m;
	int l, r, mid;
	int ans = 0;
	int min_a = 1000000000;
	int max_a = -1000000000;
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	scanf("%d%d",&n,&m);
	for (i = 1; i*i <= n; i++) sqrt_n = i;
	for (i = 0; i < n; i++){
		scanf("%d",a+i);
		if (min_a > a[i]) min_a = a[i];
		if (max_a < a[i]) max_a = a[i];
		g[i/ sqrt_n].push_back(a[i]);
	}
	for (i = 0; g[i].size()!=0; i++) sort(g[i].begin(), g[i].end());
	while (m--){
		scanf("%d%d%d",&i,&j,&k);
		l = min_a;
		r = max_a;
		while (l <= r){
			mid = (l + r) >> 1;
			if (query(i - 1, j, mid) < k){
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}