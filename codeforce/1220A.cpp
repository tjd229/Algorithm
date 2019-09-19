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
int cnt[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; string card;
	cin >> n >> card;
	for (auto c : card) 
		cnt[c - 'a']++;
	
	int o = 'o' - 'a', e = 'e' - 'a';
	int nc = 'n' - 'a';
	while (cnt[o] && cnt[e] && cnt[nc]) {
		--cnt[o]; --cnt[e]; --cnt[nc];
		cout << 1 << " ";
	}
	int z = 'z' - 'a', r = 'r' - 'a';
	while (cnt[o] && cnt[e] && cnt[z] && cnt[r]) {
		--cnt[o]; --cnt[e];
		--cnt[r]; --cnt[z];
		cout << 0 << " ";
	}
 
	return 0;
}