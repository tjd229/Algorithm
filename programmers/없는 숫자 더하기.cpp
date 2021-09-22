//https://programmers.co.kr/learn/courses/30/lessons/86051
//math
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int ans =0;
	for (int i = 0; i < 10; ++i) ans += i;
	for (auto x : numbers) ans -= x;
	return ans;
}