//greedy
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
int a[51],b[51];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int nn = n + n;
		for (i = 1; i <= nn; ++i) cin >> a[i];
		sort(a + 1, a + 1 + nn);
		int l = 1, r = nn; i = 1;
		while (l < r) {
			b[i++] = a[l++];
			b[i++] = a[r--];
		}
		for (i = 1; i <= nn; ++i)
			cout << b[i] << " ";
		cout << "\n";
	}
 
	return 0;
}