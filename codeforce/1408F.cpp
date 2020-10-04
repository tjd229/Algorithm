//math, d&c
#include <stdio.h>
#include <vector>
#include <numeric>
#define pii pair<int,int>
using namespace std;
vector<pii > p;
void dc(vector<int> &v) {
	if (v.size() == 1) return;
	vector<int> v1, v2;
	for (int i = 0; i < v.size(); i += 2) {
		p.push_back({v[i],v[i+1]});
		v1.push_back(v[i]);
		v2.push_back(v[i + 1]);
	}
	dc(v1); dc(v2);
}
int main() {
	int n; scanf("%d", &n);
	if (n <3) {
		printf("0\n");
		return 0;
	}
	int base = 1;
	while (base + base <= n) base += base;
	vector<int> a(base);
	iota(a.begin(), a.end(), 1);
	dc(a);
	if (base != n) {
		int q = p.size();
		int pad = n - base;
		for (int i = 0; i < q; ++i) {
			int x = p[i].first, y = p[i].second;
			p.push_back({x+pad,y+pad});
		}
	}
	printf("%d\n",p.size());
	for (auto xy : p)
		printf("%d %d\n",xy.first,xy.second);

	return 0;
}