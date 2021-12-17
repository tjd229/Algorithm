//string
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i;
		string S, T; cin >> S >> T;
		int cnt[26] = { 0 };
		int num = 0;
		for (i = 0; i < S.size(); ++i) {
			int c = S[i] - 'a';
			++cnt[c];
		}
		for (i = 0; i < 26; ++i) num += cnt[i] > 0;
		string ans = "";
		if (T == "abc" && num>2 && cnt[0]>0) {
			for (i = 0; i < cnt[0]; ++i) ans += 'a';
			for (i = 0; i < cnt[2]; ++i) ans += 'c';
			for (i = 0; i < cnt[1]; ++i) ans += 'b';
			for (i = 3; i < 26; ++i) {
				for(int j=0;j<cnt[i];++j)ans += 'a'+i;
			}
		}
		else {
			for (i = 0; i < 26; ++i) {
				for (int j = 0; j < cnt[i]; ++j)ans += 'a' + i;
			}
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}