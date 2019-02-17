//string
#include <iostream>
#include <string>
using namespace std;
string s;
bool chk(string &ss,int l,int r) {
	bool flag = 0;
	int ix = 0;
	while (l <= r) {
		if (ss[l] != ss[r]) return 0;
		flag |= (s[ix] != ss[l]);
		++l; --r;
		++ix;
	}
	return flag;
}
int main() {
	string  ss;
	cin >> s;
	ss = s + s;
	
	for (int i = 0; i < s.size(); ++i) {
		if (chk(ss, i, i + s.size() - 1)) {
			cout << "1";
			return 0;
		}
	}
	int l = 0; int r = s.size() - 1;
	int len = 1;
	while (l < r) {
		bool flag = 0;
		for (int i = 0; i < len; ++i) flag |= (s[i] != s[l - i]);
		if (flag) {
			cout << "2";
			return 0;
		}
		++l; --r;
		++len;
	}
	cout << "Impossible";
	return 0;
}
