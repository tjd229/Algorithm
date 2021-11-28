//math, greedy
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
int a[200001];
int b[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; 
		cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		if (n & 1) {
			int ix1=n-2, ix2=n-1, ix3=n;
			if (a[ix1] + a[ix2] == 0) {
				ix1 = n - 2, ix2 = n, ix3 = n - 1;
				if (a[ix1] + a[ix2] == 0) {
					ix1 = n - 1, ix2 = n, ix3 = n - 2;
				}
			}
			b[ix3] = -1 * (a[ix1] + a[ix2]);
			b[ix1] = b[ix2] = a[ix3];
			
			//b[n] = -1 * (a[n - 1] + a[n-2]);
			//b[n - 1] = b[n - 2] = a[n];
			for (i = 1; i <= n - 3; i += 2) {
				b[i] = -a[i + 1];
				b[i + 1] = a[i];
			}
		}
		else {
			for (i = 1; i <= n; i += 2) {
				b[i] = -a[i + 1];
				b[i + 1] = a[i];
			}
 
		}
		for (i = 1; i <= n; ++i) cout << b[i] << " ";
		cout << "\n";
		/*ll cum = 0;
		for (i = 1; i <= n; ++i) cum += a[i] * b[i];
		cout << cum << "\n";*/
	}
 
 
	return 0;
}