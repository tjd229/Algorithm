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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int cnt[3] = { 0 };
		int n; cin >> n;
		if (n == 4) cout << "-1\n";
		else if (n == 3) cout << "1 0 0\n";
		else if (n < 3) cout << "-1\n";
		else {
			if (n % 10 == 4) {
				n -= 14;
				cnt[2] = 2;
			}
			else if (n % 10 == 1) {
				n -= 11;
				cnt[0] = 2, cnt[1] = 1;
			}
			else if (n % 10 == 2) {
				cnt[0] = 4;
				n -= 12;
			}
			int r = n % 10;
			n -= r;
			cnt[1] += n / 5;
			if (r == 3) cnt[0]++;
			else if (r == 5) ++cnt[1];
			else if (r == 6) cnt[0] += 2;
			else if (r == 7) cnt[2]++;
			else if (r == 8)++cnt[0], ++cnt[1];
			else if (r == 9) cnt[0] += 3;
			for (int i = 0; i < 3; ++i) cout << cnt[i] << " ";
			cout << "\n";
			
		}
	}
 
	return 0;
}