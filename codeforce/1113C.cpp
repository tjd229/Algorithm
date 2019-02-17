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
int a[300001], ex[300001];
int cnt[(1<<20)+1][2];
int main() {
	int n;
	int i;
	cin >> n;
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		ex[i] = ex[i - 1] ^ a[i];
		
	}
	/*for (i = 1; i <= n; ++i) {
		cout << ex[i] << endl;
	}
	return 0;*/
	++cnt[0][0];
	for (i = 1; i <= n; ++i) {
		/*int len = 1;
		for (; i - len - len >= 0; len <<= 1) {
			ans += (ex[i] ^ ex[i - len] == ex[i - len] ^ ex[i - len - len]);
		}*/
		ans += cnt[ex[i]][i & 1];
		++cnt[ex[i]][i & 1];
	}
	cout << ans;
	return 0;
}
