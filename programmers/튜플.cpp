//implementation
//https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>

using namespace std;
vector<int> s2a[501];
int use[100001];
vector<int> solution(string s) {
	vector<int> answer;
	int N = 0;
	for (int i = 1; i < s.size()-1; ++i) {
		if (s[i] == '{') {
			vector<int> v;
			int num = 0;
			++i;
			while (1) {
				if (s[i] <= '9' && s[i] >= '0') {
					num = num * 10 + s[i] - '0';
				}
				else {//, }
					v.push_back(num);
					num = 0;
				}
				if (s[i] == '}') break;
				++i;
			}
			int cnt = v.size();
			s2a[cnt] = v;
			if (N < cnt) N = cnt;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (auto x : s2a[i]) {
			if (use[x] == 0) answer.push_back(x);
			use[x] = 1;
		}
	}


	return answer;
}