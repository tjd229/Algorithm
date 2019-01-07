//bs
#include <iostream>
#include <string>
#define reg register
using namespace std;
int n;
int hd0;
string o;
void gen(string &s,int l,int r,int target) {
	for (reg int i = 1; i < n; ++i) {
		if (l <= i && i <= r) s += char('0' +target);
		else s += char('0' + 1-target);
	}
}
int main() {
	int i;
	int l, r;
	int ans[2] = { -1,-1 };
	int hd;
	cin >> n;
	for (i = 0, o = ""; i < n; ++i) o += '0';
	cout << "? " << o << endl;
	cin >> hd0;
	o[0] = '1';
	cout << "? " << o << endl;
	cin >> hd;
	int target = hd > hd0;
	ans[1-target] = 0;
	if (target == 0) hd0 = n - hd0;
	l = 1;
	r = n-1;
	
	while (l <= r) {
		int m = (l + r) >> 1;
		string s = "";
		s+='0' + 1 - target;
		gen(s, l, m, target);
		cout << "? " << s << endl;
		cin >> hd;
		int diff = hd0 - hd;
		if (diff == m - l + 1) {
			ans[target] = l;
			break;
		}
		if (-diff == m - l + 1) {
			ans[target] = m + 1;
			l=m+1;
			//break;
		}
		else r = m - 1;
	}
	cout << "! " << ans[0]+1 <<" "<< ans[1]+1 << endl;
	return 0;
}
