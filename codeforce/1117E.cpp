//string, math
#include <string>
#include <iostream>
using namespace std;
int p[10000];
int main() {
	int i,j;
	string t,s;
	cin >> t;
	s.resize(t.size());
	if (t.size() <= 26) {
		char c = 'a';
		string t_;
		cout << "? ";
		for (i = 0; i < t.size(); ++i, ++c) cout << c;
		cout << endl; cin >> t_;
		for (i = 0; i < t.size(); ++i) {
			s[t_[i] - 'a'] = t[i];
		}
		cout << "! " << s << endl;		
	}
	else {
		string s1, s2, s3;
		string t_;
		s1 = s2 = s3 = "";
		int base = 26 * 26;
		char c = 'a' - 1;
		for (i = 0; i < t.size(); ++i) {
			if (i%base == 0) ++c;
			s1 += c;
		}
		cout << "? "<<s1<<endl;
		cin >> t_;
		for (i = 0; i < t.size(); ++i) p[i] = t_[i] - 'a';
		base = 26;
		c = 'a' - 1;
		for (i = 0; i < t.size(); ++i) {
			if (i%base == 0) ++c;
			if (c > 'z') c = 'a';
			s2 += c;
		}
		cout << "? " << s2 << endl;
		cin >> t_;
		for (i = 0; i < t.size(); ++i) p[i] = p[i]*26+t_[i] - 'a';
		c = 'a'-1;
		for (i = 0; i < t.size(); ++i) {
			if (++c > 'z') c = 'a';
			s3 += c;
		}
		cout << "? " << s3 << endl;
		cin >> t_;
		for (i = 0; i < t.size(); ++i) p[i] = p[i] * 26 + t_[i] - 'a';
		for (i = 0; i < t.size(); ++i) s[p[i]] = t[i];
		cout << "! " << s << endl;
	}
	return 0;
}
