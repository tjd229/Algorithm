//greedy
#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int > dq[21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, N, K;
	long long ans=0;
	cin >> N >> K;
	for (i = 0; i < N; ++i) {
		string name;
		cin >> name;
		int len = name.size();
		while (dq[len].size() && i - dq[len].front() > K) dq[len].pop_front();
		ans += dq[len].size();
		dq[len].push_back(i);
		
	}
	printf("%lld",ans);
	return 0;
}