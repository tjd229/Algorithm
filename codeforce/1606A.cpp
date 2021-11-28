//string
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int AB=0, BA = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i - 1] == 'a' && s[i] == 'b') ++AB;
			else if (s[i - 1] == 'b' && s[i] == 'a') ++BA;
		}
		if (BA == AB) cout << s << "\n";
		else {
			if (s[0] == 'a' && s[1]=='b') {
				if (AB - 1 == BA) {
					s[0] = 'b';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[0] == 'b' && s[1] == 'a') {
				if (BA - 1 == AB) {
					s[0] = 'a';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[0] == 'a' && s[1] == 'a') {
				if (AB == 1 + BA) {
					s[0] = 'b';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[0] == 'b' && s[1] == 'b') {
				if (AB +1== BA) {
					s[0] = 'a';
					cout << s << "\n";
					continue;
				}
			}
			int len = s.size();
			if (s[len - 1] == 'a' && s[len - 2] == 'b') {
				if (AB == BA-1) {
					s[len-1] = 'b';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[len - 1] == 'b' && s[len - 2] == 'a') {
				if (AB - 1 == BA) {
					s[len - 1] = 'a';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[len - 1] == 'b' && s[len - 2] == 'b') {
				if (AB == 1 + BA) {
					s[len - 1] = 'a';
					cout << s << "\n";
					continue;
				}
			}
			else if (s[len - 1] == 'a' && s[len - 2] == 'a') {
				if (AB+1 == BA) {
					s[len - 1] = 'b';
					cout << s << "\n";
					continue;
				}
			}
		}
	}
 
 
	return 0;
}