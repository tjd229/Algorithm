//implementation
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
#define reg register
using namespace std;
int mem[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	string hist; cin >> n >> hist;
	for (auto c : hist) {
		if (c == 'L') {
			for (reg int i = 0; i < 10; ++i) {
				if (mem[i] == 0) {
					mem[i] = 1;
					break;
				}
			}
		}
		else if (c == 'R') {
			for (reg int i = 9; i >= 0; --i) {
				if (mem[i] == 0) {
					mem[i] = 1;
					break;
				}
			}
		}
		else {
			int ix = c - '0';
			mem[ix] = 0;
		}
	}
	for (int i = 0; i < 10; ++i) cout << mem[i];
 
	return 0;
}