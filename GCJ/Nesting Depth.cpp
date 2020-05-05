//implementation
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f

#include <iostream>
#include <string>
using namespace std;
string S;
char S_[10001];
int main() {
	int tc, T; cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		cin >> S;
		int pos = 0;
		int depth = 0;
		for (auto c : S) {
			int digit = c - '0';
			while (depth < digit) {
				++depth;
				S_[pos++] = '(';
			}
			while (depth > digit) {
				--depth;
				S_[pos++] = ')';
			}
			S_[pos++] = c;
		}
		while (depth) {
			--depth;
			S_[pos++] = ')';
		}
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < pos; ++i) cout << S_[i];
		cout << "\n";
	}

	return 0;
}