//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
bool chk(string &s) {
	int l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] != s[r]) return 0;
		++l; --r;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S; cin >> S;
	if (chk(S)) cout << 0;
	else {
		cout << "4\nL 2\nL 2\nR 2\n";
		int n = S.size();
		n += 2+n;
		cout << "R " << n-1;
	}
 
	return 0;
}