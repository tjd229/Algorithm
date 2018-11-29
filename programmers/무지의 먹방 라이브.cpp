//https://www.welcomekakao.com/learn/courses/30/lessons/42891
//math

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;

int solution(vector<int> food_times, long long k) {
	long long N = food_times.size();
	vector<pii > v;
	set<int> st;
	for (int i = 1; i <= N;++i) {
		v.push_back({ food_times[i-1],i});
		st.insert(i);
	}
	sort(v.begin(), v.end());
	int s = 0;
	int cycle = 0;
	while (s<v.size()) {
		if (k < N*(v[s].first - cycle)) {
			if (k >= N) k %= N;
			break;
		}
		k -= N * (v[s].first - cycle);
		cycle += (v[s].first - cycle);
		for (int piv = v[s].first; s < v.size() && v[s].first == piv; ++s) {
			st.erase(v[s].second);
			--N;
		}
	}
	if (st.empty()) return -1;
	auto it = st.begin();
	for (int i = 0; it != st.end() && i < k; ++i,++it);
	return *it;
}