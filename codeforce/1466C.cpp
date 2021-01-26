//greedy
#include <iostream>
#include <string>
using namespace std; 
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string poem; cin >> poem;
		int cnt = 0;
		for (int i = 1; i < poem.size(); ++i) {
			if (i == 1) {
				if (poem[i] == poem[i - 1]) poem[i] = '#', ++cnt;
			}
			else {
				if (poem[i] == poem[i - 1] || poem[i] == poem[i - 2])
					poem[i] = '#', ++cnt;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}