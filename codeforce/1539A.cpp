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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k; cin >> k;
	while (k--) {
		int i, n, x, t; cin >> n >> x >> t;
		int st = 0, ed = t;
		int cross = ed / x;
		ll dis = n - (cross - 1)-1;
		if (dis < 0) {
			dis = 0;//cross>0
			--n;
			dis = (n * (n + 1LL)) >> 1;
		}
		else {
			dis *= cross;
			//if (cross > -100) {
			ll sigma = cross - 1;
			dis += (sigma*(sigma + 1)) >> 1;
			//}
		}
		cout << dis << "\n";
		
	}
 
	return 0;
}