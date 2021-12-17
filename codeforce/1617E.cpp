//graph, math
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int a[200001];
int d[200001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) {
		int base = 1;
		while (base < a[i]) base += base;
		int x = a[i];
		int K = base;
		while (x) {
			while (x + x <= K) K >>= 1;
			x = K - x;
			d[i]++;
		}
	}
 
	int x, y=-1, m=0, mx = -1;
	for (i = 1; i <= n; ++i) {
		if (mx < d[i]) {
			mx = d[i];
			x = i;
		}
	}
	set<int> ban; map<pair<int,int> , int> dist;
	int base = 1; int num = a[x]; ban.insert(a[x]); dist[{a[x], a[x]}] = 0;
	while (base < num) base += base;
 
	while (num) {
		while (num + num <= base) base >>= 1;
		num = base - num;
		dist[{a[x], num}] = ++m;
		ban.insert(num);
	}
	
	m = -1;
	for (i = 1; i <= n; ++i) {
		if (i == x) continue;
		int base = 1;
		while (base < a[i]) base += base;
		int lca = a[i]; int d = 0;
		while (ban.find(lca)==ban.end()) {
			while (lca + lca <= base) base >>= 1;
			lca = base - lca; ++d;
		}
		if (m < d + dist[{a[x], lca}]) {
			m = d + dist[{a[x], lca}];
			y = i;
		}
	}
	printf("%d %d %d",x,y,m);
 
	return 0;
}