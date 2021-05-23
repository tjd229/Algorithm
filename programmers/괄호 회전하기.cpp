//https://programmers.co.kr/learn/courses/30/lessons/76502
//implementation
#include <string>
#include <vector>

using namespace std;
char b[2000];
int chk(int s,int n) {
	vector<char> stk;
	for (int i = 0; i < n; ++i) {
		if (b[s+i] == '[') stk.push_back('[');
		else if(b[s + i]=='(')stk.push_back('(');
		else if (b[s + i] == '{')stk.push_back('{');
		else if (b[s + i] == ')') {
			if (stk.empty()) return 0;
			if (stk.back() != '(') return 0;
			stk.pop_back();
		}
		else if (b[s + i] == ']') {
			if (stk.empty()) return 0;
			if (stk.back() != '[') return 0;
			stk.pop_back();
		}
		else if (b[s + i] == '}') {
			if (stk.empty()) return 0;
			if (stk.back() != '{') return 0;
			stk.pop_back();
		}
	}
	return stk.empty();
}
int solution(string s) {
	int answer = 0;
	int n = s.size();
	for (int i = 0; i < n; ++i)
		b[i] = b[i + n] = s[i];
	for (int i = 0; i < n; ++i) answer += chk(i,n);


	return answer;
}