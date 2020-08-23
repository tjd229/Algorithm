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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int piv = a[1];
		bool flag = 1;
		for (i = 2; i <= n; ++i) {
			flag &= (piv == a[i]);
		}
		if (flag) cout << n<<"\n";
		else {
			cout << "1\n";
		}
	}
 
	return 0;
}