//bs
//https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>

using namespace std;
bool sim(vector<int> &v, int k,int turn) {
	int acc = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] <= turn) {
			++acc;
		}
		else acc = 0;
		if (acc >= k) return 0;
	}
	return 1;
}
int solution(vector<int> stones, int k) {
	int l = 0, r = 0;
	for (auto x : stones) {
		if (r < x) r = x;
	}
	while (l <= r) {
		int m = (l + r) >> 1;
		if (sim(stones, k, m))
			l = m + 1;
		else r = m - 1;
	}
	return l-1+1;
}