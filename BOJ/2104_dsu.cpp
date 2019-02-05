//djs
#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
int p[100001];
ll sum[100001];
int able[100002];
pii order[100002];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sum[a] += sum[b];
}
int main() {
	int i, N;
	ll ans = 0;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d",sum+i);
		p[i] = i;
		order[i] = {sum[i],i};
	}
	sort(order + 1, order + 1 + N);
	while (N--) {
		i = order[N + 1].second;
		int mn = order[N + 1].first;
		if (able[i + 1]) un(i, i + 1);
		if (able[i - 1]) un(i - 1, i);
		ll pt = (ll)mn * sum[find(i)];
		if (ans < pt) ans = pt;
		able[i] = 1;
	}
	printf("%lld",ans);
	return 0;
}