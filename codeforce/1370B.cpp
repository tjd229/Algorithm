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
int a[2001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int nn = n + n;
		vector<int> odd, even;
		for (int i = 1; i <= nn; ++i) {
			cin >> a[i];
			if (a[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
		if (odd.size() & 1) {
			odd.pop_back();
			even.pop_back();
		}
		else {
			if (odd.size() > 1) {
				odd.pop_back();
				odd.pop_back();
			}
			else {
				even.pop_back();
				even.pop_back();
			}
		}
		for (int i = 0; i < odd.size(); i+=2)
			cout << odd[i] << " " << odd[i + 1] << "\n";
		for (int i = 0; i < even.size(); i += 2)
			cout << even[i] << " " << even[i + 1] << "\n";
 
	}
 
	return 0;
}