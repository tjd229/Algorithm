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
const int mod = 1e9 + 7;
ll d[61];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k; cin >> k;
	d[1] = 1; ll cum = 16;
	for (int i = 2; i <= k; ++i) {
		d[i] = d[i - 1] * cum%mod;
		cum = cum * cum % mod;
	}
	cout << d[k]*6%mod;
 
	return 0;
}