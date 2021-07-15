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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, s; cin >> s;
		int len = 0;
		int base = 1;
		while (s>=base) {
			++len; 
			s -= base;
			base += 2;			
		}
		if (s) ++len;
		cout << len << "\n";
	}
 
	return 0;
}