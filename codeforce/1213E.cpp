//implementation
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s, t;
bool valid(int *p,int len=3) {
	for (int i = 1; i < len; ++i) {
		if (s[0] == p[i - 1] && s[1] == p[i]) return 0;
		if (t[0] == p[i - 1] && t[1] == p[i]) return 0;
	}
	return 1;
}
void print(string s,int n) {
	while (n--) cout << s;
}
int main() {
	int n; cin >> n >> s >> t;
	int c = 0;
	c |= s[0] == s[1];
	c |= t[1] == t[0];
	int p[4] = { 'a','b','c' };
 
	if (c) {
		do {
			p[3] = p[0];
			if (valid(p,4)) {
				cout << "YES\n";
				string str = "000";
				for (int i = 0; i < 3; ++i)
					str[i] = p[i];
				print(str,n);
				return 0;
			}
		} while (next_permutation(p, p + 3));
		cout << "NO";
	}
	else {
		do {
			if (valid(p)) {
				cout << "YES\n";
				string str = "0";
				for (int i = 0; i < 3; ++i) {
					str[0] = p[i];
					print(str, n);
				}
				return 0;
			}
		} while (next_permutation(p, p + 3));
		cout << "NO";
	}
 
	return 0;
}