//string
#include <string>
#include <iostream>
using namespace std;
const char vowel[5] = {'a','e','i','o','u'};
bool is_vowel(char c) {
	for (int i = 0; i < 5; ++i) if (c == vowel[i]) return 1;
	return 0;
}
int main() {
	string s, t;
	cin >> s >> t;
	if (s.size() == t.size()) {
		for (int i = 0; i < s.size(); ++i) {
			bool sv = is_vowel(s[i]);
			bool tv = is_vowel(t[i]);
			if (sv != tv) {
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}
	else
		cout << "No";
	return 0;
}
