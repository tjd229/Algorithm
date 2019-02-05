//implementation
#include <iostream>
#include <string>
#define reg register
using namespace std;
int l[600001], r[600001];
char val[600001];
int main() {
	reg int i;
	ios::sync_with_stdio(false);
	cin.tie(0);
	string load; reg int N;
	cin >> load>>N;
	for (i = 1; i <= load.size(); ++i) {
		val[i] = load[i-1];
		l[i] = i - 1;
		r[i] = i;
		r[l[i]] = i;		
	}
	r[0] = 1;
	reg int cap = load.size();
	i = cap;
	while (N--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') i = l[i];
		else if (cmd == 'D') i = r[i];
		else if (cmd == 'B') {
			if (val[i]) {
				l[r[i]] = l[i];
				if(i!=r[i])
					r[l[i]] = r[i];
				else r[l[i]] = l[i];
				i = l[i];
			}
		}
		else {
			cin >> val[++cap];
			l[cap] = i;
			r[cap] = r[i];
			if (i != r[i]) l[r[i]] = cap;
			else r[cap] = cap;
			r[i] = cap;
			i = r[i];
		}
	}
	i = 0;
	do {
		i = r[i];
		cout << val[i];
	} while (i != r[i]);
	return 0;
}