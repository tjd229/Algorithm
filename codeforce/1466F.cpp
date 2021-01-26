//graph, djs
#include <stdio.h>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int p[500001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	return 1;
}
int main() {
	int i, n, m;
	long long T = 1;
	vector<int> S;
	for (scanf("%d%d", &n,&m), i = 1; i <= m; ++i) p[i] = i;
	for (i = 1; i <= n; ++i) {
		int k, x1, x2;
		scanf("%d%d",&k,&x1);
		if (k > 1) scanf("%d",&x2);
		else x2 = 0;
		if (dsu(x1, x2)) {
			T = (T + T) % mod;
			S.push_back(i);
		}
	}
	printf("%I64d %d\n",T,S.size());
	for (auto x : S) printf("%d ",x);
 
	return 0;
}