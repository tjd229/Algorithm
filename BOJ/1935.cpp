//implementation
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int val[26];
string form;
int main() {
	int N;
	stack<double> stk;
	cin >> N >> form;
	for (int i = 0; i < N; ++i) cin >> val[i];
	for (auto c : form) {
		if ('A' <= c && c <= 'Z') stk.push(val[c-'A']);
		else {
			double t2 = stk.top(); stk.pop();
			double t1 = stk.top(); stk.pop();
			if (c == '+') stk.push(t1+t2);
			else if (c == '-') stk.push(t1-t2);
			else if (c == '*') stk.push(t1*t2);
			else stk.push(t1/t2);
		}
	}
	cout << fixed; cout.precision(2);
	cout << stk.top();
	return 0;
}