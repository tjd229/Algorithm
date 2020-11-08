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
		string s; cin >> s;
		int i,stk = 0;
		int len = 0;
		for (auto c : s) {
			if (c == 'A')++stk;
			else {
				if (stk == 0) ++len;
				else --stk;
			}
		}
		cout << (len & 1) + stk<<"\n";
		
	}
 
	return 0;
}