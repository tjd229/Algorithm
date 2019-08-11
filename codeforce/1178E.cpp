//string, greedy
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> bk, fr;
string s;
void find(int l,int r) {
	if (l > r) return;
	if (r - l + 1 <= 3) {
		fr.push_back(s[l]);
		return;
	}
	char c[3] = { 0 };
	++c[s[l] - 'a']; ++c[s[l + 1] - 'a'];
	++c[s[r] - 'a']; ++c[s[r-1] - 'a'];
	for (int i = 0; i < 3; ++i) {
		if (c[i] > 1) {
			bk.push_back(i + 'a');
			fr.push_back(i + 'a');
			break;
		}
	}
	find(l + 2, r - 2);
}
int main() {
	cin >> s;
	find(0, s.size() - 1);
	for (auto c : fr) cout << c;
	while (bk.size()) {
		cout << bk.back();
		bk.pop_back();
	}
	return 0;
}