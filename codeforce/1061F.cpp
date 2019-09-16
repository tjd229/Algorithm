//graph, math

#include <stdio.h>
#include <time.h>
#include <random>
#include <vector>
using namespace std;
int ban[1501];
int n, k;
int coin;
bool ask(int a, int b, int c) {
	if (a == b || b == c) return 1;
	else if (a == c) return 0;
	--coin;
	printf("? %d %d %d\n", a, b, c); fflush(stdout);
	char buf[4]; scanf("%s",buf);
	return buf[0] == 'Y';
 
	
}
bool leaf(int x) {
	int y = x;
	while (y == x) y = rand() % n + 1;
	for (int i = 1; i <= n; ++i)
		if (i != x && ask(i, x, y)) return 0;
	return 1;
}
void bcd(int a, int b, vector<int> &v) {
	v.clear();
	for (int i = 1; i <= n; ++i) {
		if (a == i || b == i) continue;
		if (ask(a, i, b)) v.push_back(i);
	}
}
int main() {
	srand(time(0));
	int i; scanf("%d%d", &n, &k); 
	int depth = 0; int sub = 0, r = 1;
	int sum = 0;
	vector<int> v;
	while (sum != n) {
		sum += r;
		r *= k;
		++depth;
	}
	coin = 60 * n;
	int a = 1, b = 2;
	while (!leaf(a)) {
		ban[a] = 1;
		while (ban[a])
			a = rand() % n + 1;
	}
	ban[a] = 1;
	do {
		while (ban[b]) b = rand() % n + 1;
		while (!leaf(b)) {
			ban[b] = 1;
			while (ban[b])
				b = rand() % n + 1;
		}
		bcd(a, b, v);
		ban[b] = 1;
	} while (v.size() != depth + depth - 3);
	sub = 0;
	for (i = 1, r = 1; i < depth; ++i, r *= k) sub += r;
	sub = n - sub;
	for (i = 1; i <= n; ++i) {
		if (i == a || i == b) continue;
		if (ask(a, i, b)) v.push_back(i);
	}
	for (auto x : v) {
		int y = 0;
		for (i = 1; i <= n; ++i)
			y += ask(a, x, i);
		if (y == sub) {
			printf("! %d", x); fflush(stdout);
			return 0;
		}
	}
	return 0;
}