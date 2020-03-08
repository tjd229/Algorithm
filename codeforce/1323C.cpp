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
int p[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string seq;
	int n,i;
	int s = 0;
	cin >> n >> seq;
	for (i = 0; i < n;++i) {
		char c = seq[i];
		if (c == '(') {
			++s;
		}
		else {
			--s;
		}
		p[i] = s;
	}
	if (s != 0) cout << -1;
	else {
		int ans = 0;
		
		for (i = 0; i < n;) {
			int j = i;
			while (j<n && p[j] >= 0) ++j;
			int k = j + 1;
			while (k < n && p[k] < 0) ++k;
			if (k < n) {
				ans += k - j + 1;
			}
			i = k + 1;
		}
		cout << ans;
	}
 
	return 0;
}