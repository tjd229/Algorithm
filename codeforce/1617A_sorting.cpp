//greedy
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		string S, T; cin >> S >> T;
		sort(S.begin(), S.end());
		if (T == "abc") {
			int A = 0, B = 0, C = 0;
			for (auto c : S) {
				A |= c == 'a';
				B |= c == 'b';
				C |= c == 'c';
			}
			if (A + B + C == 3) {
				auto l = lower_bound(S.begin(), S.end(), 'b');
				auto r = upper_bound(S.begin(), S.end(), 'c');
				reverse(l, r);
			}
		}
		cout << S<<"\n";
		
	}

	return 0;
}