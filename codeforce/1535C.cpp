//line sweeping
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
string s;
int o0, o1 , e1, e0 ;
void op(int num,int pos,int val) {
	if (pos == 1) {
		if (num == 0) o0 += val;
		else o1 += val;
	}
	else {
		if (num == 0) e0 += val;
		else e1 += val;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll ans = 0;
		cin >> s;
		int l = 0, r = 0;
		o0 = 0, o1 = 0, e1 = 0, e0 = 0;
		for (; r < s.size(); ++r) {
			if (s[r] != '?') {
				int num = s[r] - '0';
				int pos = r & 1;
				if (pos == 1) {//odd
					if (num == 0) {
						++o0;
						while (o1 > 0 || e0 > 0) {
							if (s[l] != '?') {
								int nn = s[l] - '0';
								int pp = l & 1;
								op(nn, pp, -1);
							}
							++l;
						}
					}
					else {
						++o1;
						while (o0 > 0 || e1 > 0) {
							if (s[l] != '?') {
								int nn = s[l] - '0';
								int pp = l & 1;
								op(nn, pp, -1);
							}
							++l;
						}
					}
				}
				else {//e
					if (num == 0) {
						++e0;
						while (e1 > 0 || o0 > 0) {
							if (s[l] != '?') {
								int nn = s[l] - '0';
								int pp = l & 1;
								op(nn, pp, -1);
							}
							++l;
						}
					}
					else {
						++e1;
						while (e0 > 0 || o1 > 0) {
							if (s[l] != '?') {
								int nn = s[l] - '0';
								int pp = l & 1;
								op(nn, pp, -1);
							}
							++l;
						}
					}
				}
			}
			ans += r - l + 1;
		}
		cout << ans<<"\n";
	}
 
 
	return 0;
}