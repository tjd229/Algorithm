//implementation
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	int N;
	cin >> N;
	while (N--) {
		stack<char> stk;
		string word;
		cin >> word;
		for (auto c : word) {
			if (stk.empty() || stk.top() != c) stk.push(c);
			else stk.pop();
		}
		cnt += stk.empty();
	}
	cout << cnt;
	return 0;
}