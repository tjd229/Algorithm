//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int s[101], d[101];
int main() {
	int i, n, t;
	cin >> n >> t;
	int st = 1e9;
	int ans = 0;
	for (i = 1; i <= n; ++i) {
		cin >> s[i] >> d[i];
		if (s[i] == t) ans = i,st=t;
		if (s[i] > t) {
			if (st > s[i]) {
				st = s[i];
				ans = i;
			}
		}
		else {
			while (s[i] < t) s[i] += d[i];
			if (st > s[i]) {
				st = s[i];
				ans = i;
			}
		}
	}
	cout << ans;
	return 0;
}
