//https://programmers.co.kr/learn/courses/30/lessons/60058
//implementation

#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;
bool valid(int s,int e,string &p) {
	int stk = 0;
	for (int i = s; i <= e; ++i) {
		if (p[i] == '(') ++stk;
		else --stk;
		if (stk < 0) return 0;
	}
	return stk == 0;
}
string balance(int s,string &p) {
	if (s >= p.size()) return "";
	int stk = p[s] == '(' ? 1 : -1;
	int e = s + 1;
	while (stk) {
		p[e] == '(' ? ++stk : --stk;
		++e;
	}
	if (valid(s, e - 1, p)) {
		string u = "";
		for (int i = s; i < e; ++i) u += p[i];
		return u + balance(e,p);
	}
	string u = "";
	for (int i = s + 1; i < e - 1; ++i)
		u += p[i] == '(' ? ')' : '(';
	return '(' + balance(e, p) + ')' + u;
}
string solution(string p) {
	string answer = "";
	if (p.size()) {
		if (valid(0,p.size()-1,p)) return p;
		answer = balance(0, p);
	}
	
	return answer;
}