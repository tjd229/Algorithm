//bs
#include "dna.h"

#include <cstdlib>
#define reg register
std::string make_str(int len, char c) {
	std::string s = "";
	for (reg int i = 0; i < len; ++i) s += c;
	return s;
}
std::string analyse(int n, int t) {
	int cnt = 0;
	int l = 1, r = n;
	while (l <= r) {
		int m = (l + r) >> 1;
		if(make_test(make_str(m,'0'))) cnt=m,l=m+1;
		else r=m-1;
	}
	if (!cnt) return make_str(n,'1');
	std::string s = make_str(cnt, '0');
	int stk = cnt;
	while (s.size()<n && stk<=cnt) {//len<n && stk
		if (make_test(s + '1')) s += '1',stk=0;
		else s += '0',++stk;
	}
	if (s.size() == n && make_test(s)) return s;
	int bnd = s.size() - stk;
	std::string sub = "";
	for (reg int i = 0; i < bnd; ++i) sub += s[i];
	l = 0, r = stk - 1; cnt = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (make_test(sub + make_str(m, '0'))) cnt=m,l = m + 1;
		else r = m - 1;
	}
	s = sub + make_str(cnt,'0');
	while (s.size() < n) {
		s = '1' + s;
		if (!make_test(s)) s[0] = '0';
	}
	return s;


    return "0";
}                       