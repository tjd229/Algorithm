//https://programmers.co.kr/learn/courses/30/lessons/72411
//implementation
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	map<string, int> mp[11];
	int pick[11] = { 0 };
	for (auto x : course) pick[x] = 1;

	for (auto order : orders) {
		sort(order.begin(), order.end());
		int bnd = order.size();
		bnd = 1 << bnd;
		for (int stat = 0; stat < bnd; ++stat) {
			int bitcnt = __builtin_popcount(stat);
			if (pick[bitcnt] == 0) continue;
			string combo = "";
			int k = 0; int mask = stat;
			while (mask) {
				if (mask & 1) combo += order[k];
				++k; mask >>= 1;
			}
			++mp[bitcnt][combo];
		}
	}
	for (auto x : course) {
		int mx = 0;
		for (auto it : mp[x])
			if (it.second > mx) mx = it.second;
		if (mx < 2) continue;
		for (auto it : mp[x]) {
			if (it.second == mx) answer.push_back(it.first);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}