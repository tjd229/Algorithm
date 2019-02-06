//implementation
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string parse(int s,int e,string &code) {
	if (code[e] == '/') return "#";
	string tag = "";
	for (int i = s; i <= e; ++i) {
		if (code[i] == '/') continue;
		else if (code[i] == ' ') break;
		tag += code[i];
	}
	return tag;
	
}
int main() {
	string html;
	while (getline(cin,html)) {
		if (html[0] == '#') break;
		stack<string> stk;
		int l, r;
		for (l = 0; l < html.size(); ++l) {
			if (html[l] == '<') {
				for (r = l; r < html.size(); ++r) {
					if (html[r] == '>') {
						string tag = parse(l + 1, r - 1, html);
						if (tag[0] != '#') {
							if (stk.empty() || stk.top() != tag)
								stk.push(tag);
							else stk.pop();
						}
						l = r;
						break;
					}
				}
			}
		}
		if (stk.size()) cout << "il";
		cout << "legal\n";
	}
	return 0;
}