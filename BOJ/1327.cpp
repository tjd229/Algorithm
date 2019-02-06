//implementation
#include <stdio.h>
#include <set>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int base[10] = { 0,1,10, 100,1000,10000, 100000,1000000,10000000, 100000000 };
int N, K;
set<int> vis;
int dst;
int kswap(int n,int l) {//rev
	int r = l + K - 1;
	if (r > N) return -1;
	while (l < r) {
		int ln = (n % base[l + 1])/base[l];
		int rn = (n%base[r + 1]) / base[r];
		n += rn * base[l] - ln * base[l];
		n += ln * base[r] - rn * base[r];
		--r;
		++l;
	}
	return n;
}
int bfs(int perm) {
	vis.insert(perm);
	queue<pii > q;
	q.push({perm,0});
	while (q.size()) {
		int t = q.front().second;
		int n = q.front().first;
		q.pop();
		if (n == dst) return t;
		for (int i = 1; i < N; ++i) {
			int nxt = kswap(n, i);
			if (nxt == -1) break;
			if (vis.find(nxt) == vis.end()) {
				vis.insert(nxt);
				q.push({nxt,t+1});
			}
		}
	}
	return -1;
}
int main() {
	int i;
	int perm = 0;
	for (scanf("%d%d", &N, &K), i = 1; i <= N; ++i) {
		int n;
		scanf("%d",&n);
		perm += n * base[i];
		dst += i * base[i];
	}
	//printf("%d,%d\n",perm,kswap(perm,1));
	printf("%d", bfs(perm));
	return 0;
}