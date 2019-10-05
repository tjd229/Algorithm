//https://programmers.co.kr/learn/courses/30/lessons/60057
//string, implementation
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.size();
	
	for (int i = 1; i <= s.size(); ++i) {
		//if (s.size() % i) continue;
		string t = "";
		int cnt = 0;
		int len = 0;
		for (int j = 0; j < s.size(); j += i) {
			string sub = "";
			for (int k = 0; k < i && j+k<s.size(); ++k) {
				sub += s[j + k];
			}
			if (t.empty()) {
				t = sub;
				cnt = 1;
			}
			else if (t.size()==sub.size() && t == sub) ++cnt;
			else {
				len += i;
				if (cnt > 1) {
					while (cnt) {
						++len;
						cnt /= 10;
					}
				}
				cnt = 1;
				t = sub;
			}
		}
		len += t.size();
		if (cnt > 1) {
			while (cnt) {
				++len;
				cnt /= 10;
			}
		}
		if (answer > len) answer = len;
	}
	return answer;
}