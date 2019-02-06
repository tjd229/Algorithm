//implementation
#include <iostream>
#include <string>
using namespace std;
int x[100000];
void print(int l,int r,int rev) {
	if (l - r > 1) cout << "error\n";
	else {
		cout << "[";
		while (l - r < 1) {
			if (rev) cout << x[r--];
			else cout << x[l++];
			if (l - r < 1) cout << ",";
		}
		cout << "]\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		string cmd,arr;
		int l = 0;
		int r = -1;
		int num = 0;
		int rev = 0;
		cin >> cmd>>N>>arr;
		for (auto c : arr) {
			if ('0' <= c && c <= '9') num = num * 10 + c - '0';
			else if (c != '[') {
				x[++r] = num;
				num = 0;
			}
		}
		r = N - 1;
		for (auto c : cmd) {
			if (c == 'R') rev = 1 - rev;
			else if (rev) --r;
			else ++l;
		}
		print(l,r,rev);
	}
	return 0;
}