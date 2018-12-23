//bs

#include <iostream>
#include <string>
using namespace std;
int main() {//b | w
	int n;
	string hat;
	int l = 0;
	int r = 1e9;
	cin >> n;
	cout << "0 1"<<endl;
	cin >> hat;
	char c = hat[0];
	while (--n) {
		int mid = (l+r) >> 1;
		cout << mid << " 1" << endl;
		cin >> hat;
		//cout << hat << endl;
		if (hat[0] == c) l = mid;
		else r = mid;
	}
	cout << l << " 2 " << r << " 0";

	return 0;
}
