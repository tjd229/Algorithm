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
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w, h; cin >> w >> h;
	int wh = w + h;
	long long ans = 1;
	long long base = 2;
	while (wh) {
		if (wh & 1) {
			ans = ans * base%mod;
		}
		wh >>= 1;
		base = base * base%mod;
	}
	cout << ans;
	
	return 0;
}