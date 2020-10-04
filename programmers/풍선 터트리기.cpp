//greedy
//https://programmers.co.kr/learn/courses/30/lessons/68646?language=cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
	int answer = 1;
	int gmn = 1e9, piv = -1;
	for (int i = 0; i < a.size(); ++i) {
		if (gmn > a[i]) {
			gmn = a[i];
			piv = i;
		}
	}
	int lmn = 1e9;
	for (int i = a.size()-1; i >piv; --i) {
		if (lmn > a[i]) {
			lmn = a[i];
			++answer;
		}
	}
	lmn = 1e9;
	for (int i = 0; i < piv; ++i) {
		if (lmn > a[i]) {
			lmn = a[i];
			++answer;
		}
	}
	return answer;
}