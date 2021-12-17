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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		if (n & 1) {
			int c = 1;
			int a, b;
			a = b = (n - 1) >> 1;
			if ((a & 1)==0) {
				--a; ++b;
			}
			else {
				a -= 2; b += 2;
			}
			cout << a << " " << b << " " << c << "\n";
		}
		else {
			int c = 1;
			int a, b;
			a = b = (n - 1) >> 1;
			++b;
			cout << a << " " << b << " " << c << "\n";
		}
	}
 
 
	return 0;
}