//string, greedy
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
		//if one  char, first ->val 0
		int i;
		string s, t = ""; cin >> s;
		int cnt[26] = { 0 };
		for (auto c : s) ++cnt[c - 'a'];
		int prefix = -1;
		int low = -1;
		for (i = 0; i < 26; ++i) {
			if (cnt[i] == 1) {
				prefix = i;
				cnt[i] = 0;
				t += (char)('a' + i);
				break;
			}
			if (cnt[i] > 0 && low == -1) low = i;
		}
		if (prefix != -1) {
			for (i = 0; i < 26; ++i) {
				while (cnt[i] > 0) {
					t += (char)('a' + i);
					--cnt[i];
				}
			}
		}
		else {
			t += (char)('a' + low); --cnt[low];
			int r = low + 1;
			int remain = s.size() - 1-cnt[low];
			if (cnt[low]-1<= remain) {
				//cnt<=remain
				while (cnt[low] > 1) {
					t += (char)('a' + low); --cnt[low];
					while (cnt[r] == 0) ++r;
					t += (char)('a' + r); --cnt[r];
				}
			}
			else if(remain>0){
				
				while (cnt[r] == 0) ++r;
				
				if (remain - cnt[r] > 0) {
					t += (char)('a' + r); --cnt[r]; ++r;
					while (cnt[low] > 0) {
						t += (char)('a' + low); --cnt[low];
					}
					while (cnt[r] == 0) ++r;
					t += (char)('a' + r); --cnt[r];
				}
				else {
					while (cnt[r] > 0) {
						t += (char)('a' + r); --cnt[r];
					}
				}
			}
			//cout << t << endl;
			//do greedy
			for (i = 0; i < 26; ++i) {
				while (cnt[i] > 0) {
					t += (char)('a' + i);
					--cnt[i];
				}
			}
		}
		cout << t << "\n";
	}
 
 
	return 0;
}