//d&c, string
#include <string>
using namespace std;
 
extern int query(string str);
int cnt[26];
 
string dc(int s,int e) {
	if (s == e) {
		string res(cnt[s], 'a' + s);
		return res;
	}
	int m = (s + e) >> 1;
	string left = dc(s, m);
	string right = dc(m + 1, e);
	if (left.size() == 0) return right;
	if (right.size() == 0) return left;
	string res = "";
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		int len = query(res + left[l] + right.substr(r));
		int base = res.size() + right.size() - r;
		if (len > base) res += left[l++];
		else res += right[r++];
	}
	if (l < left.size()) res += left.substr(l);
	else res += right.substr(r);
	
	return res;
}
string guess(int n, int s) {
	for (int i = 0; i < s; ++i) {
		string str(n, 'a' + i);
		cnt[i] = query(str);
	}
 
	return dc(0,s-1);
}
