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
int gcd(int a, int b) {
	if (a == 0) return b;//a<b
	return gcd(b%a,a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a > b) a ^= b ^= a ^= b;
		int d = gcd(a, b);
		if (d == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
 
	return 0;
}