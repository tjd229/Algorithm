//implementation
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const ll bnd = (1LL << 32) - 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string cmd;
	int l; 
	vector<ll> stk = { 0 };//ac
	vector<ll> lstk = { 1 };//loop stk
	cin >> l;
	while (l--) {
		cin >> cmd;
		if (cmd[0] == 'a') ++stk.back();
		else if (cmd[0] == 'f') {
			ll n; cin >> n;
			stk.push_back(0);
			lstk.push_back(n);
		}
		else {
			ll m = stk.back()*lstk.back();
			stk.pop_back();
			lstk.pop_back();
			stk.back() += m;
		}
		if (stk.back() > bnd) {
			cout << "OVERFLOW!!!";
			return 0;
		}
	}
	//cout << stk.size() << endl;
	cout << stk.back();
	
	return 0;
}