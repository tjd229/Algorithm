//greedy, djs
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
bool valid[200000];
int p[200000], sz[200000];
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
bool dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	sz[a] += sz[b];
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n;
		string s; cin >> n >> s;
		for (i = 0; i < n; ++i) {
			p[i] = i;
			sz[i] = 1;
			if (i > 0 && s[i - 1] == s[i]) dsu(i - 1, i);
			valid[i] = 1;
		}
		int op = 0;
		int l = 0, r = 0;
		int dir = 1;
		for (; l < n;) {
			if (r < l) r=l;
			if (valid[l] == 0) {
				++l;
				continue;
			}
			int par = find(l);
			if (sz[par] > 1) {
				++op;
				while (l < n && s[par] == s[l]) ++l;
			}
			else {//sz[l]==1
				if (dir == 1) {
					while (r < n && sz[find(r)] == 1) ++r;
					if (r < n) {
						int par = find(r);
						--sz[par];
						valid[r] = 0;
						++r, ++l;
						++op;
						continue;
					}
					else {
						dir = -1;
						r = n;
					}
				}
				if (dir == -1) {
					while (l < r && valid[r] == 0) --r;
					valid[r] = 0;
					++l, --r;
					++op;
				}
			}
			//printf("%d,%d\n",l,r);
			//int _; scanf("%d",&_);
		}
		cout << op << "\n";
	}
 
	return 0;
}