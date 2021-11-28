//string
#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int i; cin >> s;
		int n = s.size();
		int mn = 10000;
		int pick = 0;
		for (i = 0; i < n; ++i) {
			if (s[i] < mn) {
				mn = s[i];
				pick = i;
			}
		}
		cout << s[pick] << " ";
		for (i = 0; i < n; ++i) {
			if (i != pick) cout << s[i];
		}
		cout << "\n";
		//puts("");
	}
 
	return 0;
}