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
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		deque<int> dq;
		for (i = 1; i <= n; ++i) cin >> a[i];
		dq.push_back(a[n]);
		ll ans = 0;
		for (i = n - 1; i >= 1; --i) {
			if (dq.size() && dq.front() <= a[i]) {
				ans += a[i] - dq.front();
				int piv = a[i];
				while (dq.size() && dq.front() <= piv)
					dq.pop_front();
				
			}
			
			dq.push_front(a[i]);
		}
		
		cout << ans << "\n";
	}
 
	return 0;
}