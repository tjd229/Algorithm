//https://programmers.co.kr/learn/courses/30/lessons/77885
//math
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (auto x : numbers) {
		if ((x & 1) == 0) answer.push_back(1 + x);
		else {
			long long base = 1;
			while (1) {
				if ((x&base)==0) {
					x += base;
					x -= base >> 1;
					answer.push_back(x);
					break;
				}
				base <<= 1;
			}
		}
	}
	return answer;
}