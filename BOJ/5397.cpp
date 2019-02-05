//implementation
#include <iostream>
#include <string>
using namespace std;
int l[1000001], r[1000001];
char val[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string hist;
		cin >> hist;
		int cap = 0;
		int cur = 0;
		r[0] = 0;
		for (auto cmd : hist) {
			if (cmd == '<') cur = l[cur];
			else if (cmd == '>') cur = r[cur];
			else if (cmd == '-') {
				if (val[cur]) {
					l[r[cur]] = l[cur];
					if(cur!=r[cur])
						r[l[cur]] = r[cur];
					else r[l[cur]] = l[cur];
					cur = l[cur];					
				}
			}
			else {
				val[++cap] = cmd;
				l[cap] = cur;
				if (cur != r[cur]) {
					l[r[cur]] = cap;
					r[cap] = r[cur];
				}
				else r[cap] = cap;
				r[cur] = cap;
				cur = r[cur];
			}
		}
		cur = 0;
		do {
			cur = r[cur];
			cout << val[cur];
		} while (r[cur] != cur);
		cout << "\n";
	}
	return 0;
}