//implementation
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
ll in(int a1, int a2, int b1, int b2) {
	//a1<=a2, b1<=b2
	if (a2 < b1 || b2<a1) return 0;
	int l = a1 > b1 ? a1 : b1;
	int r = a2 < b2 ? a2 : b2;
	return r-l+(a1!=b1);
}
int main() {
	int i, n;
	cin >> n;
	int x, y;
	ll ans = 1;
	x = y = 0;
	for (i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a == x && b == y) continue;
		ans += in(x, a, y, b);
		x = a; y = b;
		//cout << ans << endl;
	}
	if (ans == 0) ++ans;
	cout << ans;
	return 0;
}
