//math
#include <iostream>
#include <string>
using namespace std;
int s[1000001];
int main() {
	string a, b; cin >> a >> b;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '1') ++s[i + 1];
	}
	for (int i = 1; i <= a.size(); ++i)
		s[i] += s[i - 1];
	int bs = 0;
	for (int i = 0; i < b.size(); ++i) bs += (b[i] == '1');
	int ans = 0;
	for (int i = b.size(); i <= a.size(); ++i) {
		int f = s[i] - s[i - b.size()]-bs;
		ans += (f & 1) == 0;
	}
	cout << ans;
	return 0;
}