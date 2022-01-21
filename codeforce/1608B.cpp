//greedy
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int p[100001];
int main() {
	int t; cin >> t;
	while (t--) {
		int n,a,b; cin >> n>>a>>b;
		if (n == 2) {
			if (a + b == 0) cout << "1 2\n";
			else cout << "-1\n";
		}
		else if (n == 3) {
			if (a + b == 1) {
				if (a) cout << "1 3 2\n";
				else cout << "2 1 3\n";
			}
			else if (a + b == 0) cout << "1 2 3\n";
			else cout << "-1\n";
		}
		else {
			if (a == b) {
				int r = a+b; 
				if (r<=n-2) {
					for (int i = 1; i <= n; ++i) p[i] = i;
					for (int i = 2; r &&i+1 <= n; i += 2) {
						p[i] = i + 1; p[i + 1] = i;
						r -= 2;
					}
					for (int i = 1; i <= n; ++i) cout << p[i] << " ";
					cout << "\n";
				}
				else cout << "-1\n";
			}
			else if (a + 1 == b) {
				int need = a + b + 2;
				int r = need, l = 1;
				if (need > n) cout << "-1\n";
				else {
					vector<int> p;
					while (l < r) {
						p.push_back(r--);
						p.push_back(l++);
					}
					p.push_back(r);
					for (int i = n; i > need; --i) cout << i << " ";
					for (auto x : p) cout << x << " ";
					cout << "\n";
				}
			}
			else if (b + 1 == a) {
				int need = a + b + 2;
				int r = need, l = 1;
				if (need > n) cout << "-1\n";
				else {
					vector<int> p;
					while (l < r) {
						p.push_back(l++);
						p.push_back(r--);
					}
					p.push_back(r);
					for (int i = 1; i <= n - need;++i) cout << i << " ";
					for (auto x : p) cout << x+n-need << " ";
					cout << "\n";
				}
			}
			else cout << "-1\n";
		}
		
	}
 
	return 0;
}
