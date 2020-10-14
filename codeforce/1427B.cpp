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
string s;
int n;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,  k; cin >> n >> k >> s;
		priority_queue<pii > q;
		int head = -1, tail = n;
		vector<pii > v;
		if (s[0] == 'L') {
			head = 0;
			while (head < n && s[head] == 'L') ++head;
		}
		if (s[n - 1] == 'L') {
			tail = n - 1;
			while (tail >= 0 && s[tail] == 'L') --tail;
		}
		
		i = 0;
		if (head != -1) i = head;
			for (; i < n;) {
				if (s[i] == 'W') ++i;
				else {
					int j = i;
					while (j < n && s[j] == 'L') ++j;
					if (j < n && s[j] == 'W') {
						v.push_back({ j - i,i });
					}
					i = j;
				}
			}
		
		if (v.size()) {
			sort(v.begin(), v.end());
			for (i = 0; i < v.size() && k; ++i) {
				int len = v[i].first;
				int pos = v[i].second;
				while (k && len) {
					--k; --len;
					s[pos++] = 'W';
				}
			}
		}
		while (k &&head > 0) {
			--k; s[--head] = 'W';
		}
		while (k &&tail<n) {
			--k; s[++tail] = 'W';
		}
		int pt = 0;
		char last = -1;
		for (i = 0; i < n; ++i) {
			if (s[i] == 'W') {
				if (last == 'W') pt += 2;
				else ++pt;
			}
			last = s[i];
		}
		cout << pt << "\n";
		//cout << s << endl;
	}
 
 
	return 0;
}
