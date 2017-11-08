//category : djs

#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;

pii h[100001];
int p[100001];
int sz[100001];
bool cover[100002];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int main(){
	int i;
	int n;
	ll ans = 0;
	while (scanf("%d", &n)){
		if (n == 0) break;
		ans = 0;
		for (i = 1; i <= n; i++){
			scanf("%d", &h[i].first);
			h[i].second = i;
			p[i] = i;
			sz[i] = 1;
			cover[i] = false;			
		}
		cover[i] = false;
		
		sort(h + 1, h + 1 + n);
		while (n--){
			i = h[n + 1].second;
			if (cover[i + 1]) join(i, i + 1);
			if (cover[i - 1]) join(i-1, i);
			cover[i] = true;
			ans = max(ans, (ll)sz[find(i)] * h[n+1].first);
		}
		printf("%lld\n",ans);
	}

	return 0;
}