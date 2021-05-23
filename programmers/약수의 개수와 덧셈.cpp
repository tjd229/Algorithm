//https://programmers.co.kr/learn/courses/30/lessons/77884
//math
#include <string>
#include <vector>
using namespace std;
int cnt(int x) {
	int c = 0;
	for (int i = 1; i <= x; ++i) {
		if (x%i == 0) ++c;
	}
	return c;
}
int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; ++i) {
		int c = cnt(i);
		if (c & 1) answer -= i;
		else answer+=i;
	}
	return answer;
}