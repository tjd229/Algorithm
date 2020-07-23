//implementation, string
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
const string sub = "abacaba";
const string dummy = "caba";
const string dummy2 = "bacaba";
const string dummy3 = "abac";
const string dummy4 = "abacab";
string s;
int n;
bool chk(int i) {
	if (i + 6 >= n) return 0;
	for (int k = 0; k < 7; ++k)
		if (s[i + k] != sub[k]) return 0;
	return 1;
}
bool rep(int i) {
	if (i + 6 >= n) return 0;
	for (int k = 0; k < 7; ++k) {
		if (s[i + k] == '?') continue;
		if (s[i + k] != sub[k]) return 0;
	}
	int cnt = 0;	
	for (int k = 0; k < 4 && i+7+k<n; ++k) {
		if (s[i + 7 + k] == dummy[k]) ++cnt;
	}
	
	if (cnt == 4) return 0;
	cnt = 0;
	for (int k = 0; k < 6 && i + 7 + k < n; ++k) {
		if (s[i + 7 + k] == dummy2[k])++cnt;
	}
	if (cnt == 6) return 0;
	cnt = 0;
	for (int k = 1; k <= 4 && i-k>=0; ++k) {
		if (s[i - k] == dummy3[4-k])++cnt;
		//printf("%c,%c\n",s[i-k],dummy3[4-k]);
	}
	if (cnt == 4) return 0;
	//printf("cnt:%d\n",cnt);
	cnt = 0;
	for (int k = 1; k <= 6 &&i - k >= 0; ++k) {
		if (s[i - k] == dummy4[6 - k]) ++cnt;
	}
	if (cnt == 6) return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int i;
		cin >> n >> s;
		int cnt = 0;
		for (i = 0; i < n; ++i) cnt += chk(i);
		if (cnt == 1) {
			for (i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'z';
			cout << "Yes\n" << s << "\n";
			
		}
		else if (cnt > 1) {
			cout << "No\n";			
		}
		else {
			bool flag = 0;
			for (i = 0; i < n && !flag; ++i) {
				if (rep(i)) {
					for (int k = 0; k < 7; ++k) s[i + k] = sub[k];
					flag = 1;
				}
			}
			if (flag) {
				for (i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'z';
				cout << "Yes\n" << s << "\n";
			}
			else cout << "No\n";
		}
	}
 
	return 0;
}
