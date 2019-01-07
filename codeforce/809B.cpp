//bs
#include <iostream>
#include <string>
using namespace std;
int bs(int l, int r) {
	if(l == r) return l;
	if (l > r) return -1;
	int bnd = r;
	int x=r;
	string Noora;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (m + 1 > bnd) return x;
		cout << "1 " << m << " " << m + 1 << endl;
		cin >> Noora;
		if (Noora[0] == 'N') l = m + 1;
		else r = m - 1,x=m;
	}
	return x;
}
int main() {
	int n, k;
	cin >> n >> k;
	
	int x = bs(1, n);
	int y = bs(x + 1, n); //1,x-1
	if (y < 0) 
		y = bs(1, x - 1);
	string chk1, chk2;
	cout << "1 " << x << " " << y << endl;
	cin >> chk1;
	cout << "1 " << y << " " << x << endl;
	cin >> chk2;
	if (chk1[0] == 'N' || chk2[0] == 'N') y = bs(1, x - 1);

	cout << "2 " << x << " " << y << endl;

	return 0;
}
