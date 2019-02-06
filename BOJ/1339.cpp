
//gredy
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
char board[10][8];
ll val[26];
int main() {
	int i, j,N;
	cin >> N;
	ll ans = 0;
	for (i = 0; i < N; ++i) {
		string word;
		cin >> word;
		reverse(word.begin(), word.end());
		for (int j = 0; j < word.size(); ++j) board[i][7 - j] = word[j];
	}
	for (i = 0; i < N; ++i) {
		ll base = 1;
		for (j = 7; j >= 0 && board[i][j]; --j, base *= 10)
			val[board[i][j] - 'A']+=base;
	}
	sort(val, val + 26, [](int a,int b) {
		return a>b;
	});
	for (i = 9; i > 0; --i) ans += val[9-i] * i;
	cout << ans;
	return 0;
}
