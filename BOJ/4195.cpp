//djs
#include <iostream>
#include <string>
#include <map>
using namespace std;
int p[100001],sz[100001];
int ix;
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, T, F;
	cin >> T;
	while (T--) {
		string f1, f2;
		map<string, int> h;
		ix = 1e5;
		cin >> F;
		if (ix > F + F) ix = F + F;
		for (i = 1; i <= ix; ++i) p[i] = i,sz[i]=1;
		ix = 1;
		while (F--) {
			cin >> f1 >> f2;
			int &u = h[f1];
			if (u == 0) u = ix++;
			int &v = h[f2];
			if (v == 0) v = ix++;
			un(u, v);
			cout << sz[find(u)] << "\n";
		}
	}
	return 0;
}