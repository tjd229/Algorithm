//djs
#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
pii order[100001];
int p[100001];
int sz[100001];
int h[100002];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int main() {
	int i, N;
	int ans = 0;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d",h+i);
		p[i] = i;
		sz[i] = 1;
		order[i] = {h[i],i};
	}
	sort(order + 1, order + 1 + N);
	while (N--) {
		i = order[N + 1].second;
		int mn = order[N + 1].first;
		if (mn <= h[i + 1]) un(i, i + 1);
		if (mn <= h[i - 1]) un(i - 1, i);
		int pt = mn * sz[find(i)];
		if (ans < pt) ans = pt;
	}
	printf("%d",ans);
	return 0;
}