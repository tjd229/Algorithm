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
int a[100001];
int x[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	int mv = 0;
	int ans = 0;
	for (mv = 1, i = 1; ans == 0 && i <= n && mv < 31; ++mv) {
		int bnd = 1 << mv;
		int cnt = 0;
		while (i <= n && a[i] < bnd) {
			++i;
			++cnt;
		}
		if (cnt > 2) ans = 1;
	}
	if (ans > 0) {
		cout << ans;
		return 0;
	}
	//60
	ans = -1;
	for (i = 1; i <= n; ++i) x[i] = x[i - 1] ^ a[i];
	for (i = 1; i <= n; ++i) {
		int l = i;
		while (l > 0) {
			int r = i + 1;
			while (r <= n) {
				int left = x[i] ^ x[l - 1];
				int right = x[r] ^ x[i];
				int cnt = i - l + r - (i + 1);
				if (cnt > 0 && left > right) {
					if (ans<0 || ans>cnt) ans = cnt;
				}
				++r;
			}
			--l;
		}
	}
	
	cout << ans;
	return 0;
}