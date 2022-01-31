//math
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int vis[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, a, b; cin >> a >> b;
		int ans = b - a;
		for (i = a; i <= b; ++i) {
			int op = 1 - a - b+i;
			int bb = 0;
			for (int k = 21; k >= 0; --k) {
				int _bit = 1 << k;
				if ((b&_bit)) bb += _bit;
				if ((i&_bit) && (b&_bit) == 0) {
					bb += _bit;
					break;
				}
			}
			op += (i | bb);
			if (ans > op) ans = op;
		}
 
 
		cout << ans << "\n";
 
	}
 
 
	return 0;
}
