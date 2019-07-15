//bs, math
#include <iostream>
#include <string>
using namespace std;
bool cmp(int x,int y) {
	cout << "? " << x << " " << y << endl;
	char symbol; cin >> symbol;
	return symbol == 'y';//x<y
}
int main() {
	int i, x, y;
	string s; cin >> s;
	do {
		x = 0; y = 1;
		if (!cmp(x, y))
			cout << "! " << 1 << endl;
		else {
			x = 1; y = 2;
			while (cmp(x, y)) x = y, y += y;
			int l = x, r = y - 1;
			int a;
			while (l <= r) {
				int m = (l + r) >> 1;
				if (cmp(m, y)) r = m - 1;
				else l = m + 1, a = m;//m>=y
			}
			cout << "! " << a + 1 << endl;
		}
 
		cin >> s;
	} while (s[0]!='e');
	return 0;
}