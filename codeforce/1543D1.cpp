//math
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
//int pwd=2;
//int ask(int y) {
//	printf("ask:%d\n",y);
//	if (y == pwd) {
//		printf("1\n");
//		return 1;
//	}
//	else {
//		pwd ^= y;
//		return 0;
//	}
//}
int ask(int y) {
	cout << y << endl;
	int r; cin >> r;
	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (ask(0));
		else {
			int last = 0;
			for (int i = 1; i < n; ++i) {
				if (ask(last ^ i)) break;
				last = i;
			}
		}
	}
 
	return 0;
}