//implementation
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int vstat = 1 + (1 << ('e' - 'a')) + (1 << ('i' - 'a')) + (1 << ('o' - 'a')) + (1 << ('u' - 'a'));
int L, C;
char c[15];
string pw;
inline bool is_vowel(char c) {
	return 0 < (vstat&(1 << (c - 'a')));
}
void guess(int last,int len,int c1,int c2) {
	int d1, d2;
	for (int i = last + 1; i+L-len <= C; ++i) {
		d1 = d2 = 0;
		pw[len] = c[i];
		if (is_vowel(c[i])) ++d1;
		else ++d2;
		c1 += d1;
		c2 += d2;
		if (len == L - 1) {
			if (c1 > 0 && c2 > 1) cout << pw << "\n";
		}
		else
			guess(i,len+1,c1,c2);
		c1 -= d1; c2 -= d2;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;	
	cin >> L >> C;
	for (i = 0; i < C; ++i) cin >> c[i];
	sort(c, c + C);
	pw.resize(L);
	guess(-1,0,0,0);
	return 0;
}