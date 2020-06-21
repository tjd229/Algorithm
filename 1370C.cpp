//game
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
		int n; cin >> n;
		if (n == 1) cout << "FastestFinger\n";
		else if (n == 2) cout << "Ashishgup\n";
		else if(n&1) cout << "Ashishgup\n";//W //w prime case
		else {
			int odd = 0;
			int two = 0;
			bool win = 0;
			
			for (int i = 2; n > 1;++i) {
				//cout << n << endl;
				ll chk = (ll)i*i;
				if (chk > n) {
					++odd;
					break;
				}
				while (n%i == 0) {
					//cout << "loop\n";
					//cout << i << endl;
					if (i == 2) ++two;
					else ++odd;
					n /= i;
				}
			}
			if (odd == 0) win = 0;
			else if (two == 1) {
				if (odd == 1) win = 0;//(odd x 2)
				else win = 1; //(odd x odd x ... x2)
			}
			else win = 1; //odd>0 && two>1(@x2x2)
 
			if(win) cout << "Ashishgup\n";
			else cout << "FastestFinger\n";
		}
	}
 
	return 0;
}