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
ll sum[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long ans = 0;
	string s; cin >> s;
	int v = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0 && s[i] == 'o') continue;
		if (s[i] == 'o') {
			if (v > 1) sum[i] = v-1;
			v = 0;
		}
		else ++v;
	}
	if (v > 1) sum[s.size()] = v-1;
	for (int i = 1; i <= s.size(); ++i) sum[i] += sum[i - 1];
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'o') {
			ll l = sum[i];
			ll r = sum[s.size()] - l;
			ans += l * r;
		}
	}
	cout << ans;
	return 0;
}