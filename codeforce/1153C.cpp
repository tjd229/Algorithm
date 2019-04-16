//greedy
#include <iostream>
#include <string>
using namespace std;
int len;
string s;
char ans[300001];
int op, cl;
int main() {
	int i;
	cin >> len >> s;
	if (len & 1) cout << ":(";
	else {
		op = cl = len >> 1;
		for (i = 0; i < len;++i) {
			char c = s[i];
			if (c == '(') --op,ans[i]=c;
			else if (c == ')') --cl,ans[i]=c;			
		}
		bool flag = op>=0 && cl>=0;
		int tot = 0;
		for (i = 0; i < len && flag; ++i) {
			if (!ans[i]) {
				if (op) ans[i] = '(', --op;
				else ans[i] = ')', --cl;
			}
			tot += ans[i] == '(' ? 1 : -1;
			if (tot <= 0 && i<len-1) flag = 0;
		}
		flag &= (tot == 0);
		if (flag) {
			for (i = 0; i < len; ++i) cout << ans[i];
		}
		else cout << ":(";
	}
	return 0;
}
