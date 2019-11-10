//dp
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
const int mod = 1e9 + 7;
ll d[100001];
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s; //no m,w
	int n = s.size();
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; ++i)
		d[i] = (d[i - 1] + d[i - 2]) % mod;
 
	ll ans = 1;
	char last = -1;
	int cnt = 0;
	for (auto c : s) {
		if (c == 'm' || c == 'w') ans = 0,cnt=0;
		else if (last != c) {
			if (cnt >= 2) {
				ans = ans * d[cnt]%mod;
			}
			cnt = 0;
		}
		if (c == 'u' || c=='n') ++cnt;
		last = c;
	}
	if (cnt >= 2) {
		ans = ans * d[cnt] % mod;
	}
	cout << ans;
 
	return 0;
}