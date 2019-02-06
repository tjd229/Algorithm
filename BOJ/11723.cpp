//implementation
#include <string>
#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int S = 0;
	int M,x;
	cin >> M;
	while (M--) {
		string cmd;
		cin >> cmd;
		if (cmd[1] == 'd') {
			cin >> x;
			S |= 1 << x;
		}
		else if (cmd[1] == 'e') {
			cin >> x;
			if (S&(1 << x)) S -= 1 << x;
		}
		else if (cmd[1] == 'h') {
			cin >> x;
			cout << (0<(S & (1 << x)))<<"\n";
		}
		else if (cmd[1] == 'o') {
			cin >> x;
			S ^= 1 << x;
		}
		else if (cmd[1] == 'l') S = (1<<21)-2;
		else S = 0;
	}
	return 0;
}
