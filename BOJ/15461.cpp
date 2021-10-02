//greedy
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#define pii pair<int,int>
using namespace std;
int main() {
	vector<tuple<int, int, int> > v;
	int i, N, G;
	set<pii > st; st.insert({0,0});
	map<int, int> milk, cows; cows[0] = 0;
	for (scanf("%d%d", &N, &G), i = 1; i <= N; ++i) {
		int id, day, delta;
		char sign;
		scanf("%d%d %c%d",&day,&id,&sign,&delta);
		if (sign == '-') delta = -delta;
		v.push_back({day,id,delta});
		st.insert({0,id});
		cows[id] = 0;
	}
	sort(v.begin(), v.end());
	milk[0] = 1 + N;
	int ans = 0;
	auto it = st.end();
	int top = (--it)->second;
	int num = 1+N;
	for (i = 0; i < v.size(); ++i) {
		int id,delta; tie(ignore,id,delta) = v[i];
		int m = cows[id];
		st.erase({m,id});
		--milk[m];
		m += delta;
		cows[id] = m;
		++milk[m];
		st.insert({m,id});
		it = st.end(); --it;
		if (top != it->second) {
			++ans;
			top = it->second;
			num = milk[ cows[top] ];
		}
		else if (num != milk[cows[top]]) {
			++ans;
			num = milk[cows[top]];
		}
	}
	printf("%d",ans);

	return 0;
}