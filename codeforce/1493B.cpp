//implementation
#include <iostream>
#include <string>
using namespace std;
int hh, mm;
int h, m;
bool v[10] = {1, 1, 1, 0, 0, 1,0,0,1,0};
int mirror[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};
bool valid(int t,int bnd) {
	int t1 = t / 10, t2 = t % 10;
	if (v[t1] == 0 || v[t2] == 0) return 0;
	int mirrored = mirror[t2] * 10 + mirror[t1];
	if (mirrored >= bnd) return 0;
	return 1;
	
}
void print_time(int t) {
	if (t < 10) cout << 0;
	cout << t;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		string s; cin >> h >> m>>s;
		hh = (s[0]-'0') * 10 + s[1]-'0';
		mm = (s[3] - '0') * 10 + s[4] - '0';
		while (valid(hh,m)==0 || valid(mm,h)==0) {
			++mm;
			if (mm == m) {
				++hh; mm = 0;
			}
			if (hh == h) hh = 0;
		}
		print_time(hh); cout << ":";
		print_time(mm); cout << "\n";
	}
 
	return 0;
}