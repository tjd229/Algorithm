//https://programmers.co.kr/learn/courses/30/lessons/72410
//string, implementation
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string last = new_id;
	string str;
	for (auto c : last) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		str += c;
	}
	last = str; str = "";
	for (auto c : last) {
		if (c >= 'a' && c <= 'z') str += c;
		else if (c == '.' || c == '-' || c == '_') str += c;
		else if (c >= '0' && c <= '9') str += c;
	}
	last = str; str = "";
	char lastc = '#';
	for (auto c : last) {
		if (c == '.') {
			if (lastc != c) str += c;
		}
		else str += c;
		lastc = c;
	}
	last = str; str = "";
	if (last.size() && last[0] == '.') {
		for (int i = 1; i < last.size(); ++i) str += last[i];
		last = str; str = "";
	}
	if (last.back() == '.')
		last.pop_back();
	if (last.empty())last = 'a';
	while (last.size() >= 16)
		last.pop_back();
	if (last.back() == '.')
		last.pop_back();
	while (last.size() <= 2)
		last += last.back();
	return last;
}