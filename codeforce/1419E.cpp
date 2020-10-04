//math
#include <stdio.h>
#include <set>
#include <vector>
#define ll long long
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		ll _n = n;
		vector<int> factor;
		set<int> divs;
		for (ll i = 2; i*i <= _n; ++i) {
			int p = -1;
			while (_n%i == 0) {
				p = i;
				_n /= i;
			}
			if(p!=-1)
				factor.push_back(p);
		}
		if (_n>1) factor.push_back(_n);
		for (ll i = 2; i*i <= n; ++i) {
			if (n%i == 0) {
				divs.insert(i);
				divs.insert(n / i);
			}
		}
		divs.insert(n);
		if (factor.size() == 2 && divs.size() == 3) {
			printf("%d %d %d\n1\n",factor[0],factor[1],factor[0]*factor[1]);
		}
		else if (factor.size() == 2) {
			vector<int> bridge,tail[2];
			int base = factor[0] * factor[1];
			divs.erase(factor[0]); divs.erase(factor[1]);
			for (auto it = divs.begin(); it != divs.end() ; ++it) {
				if (*it%base == 0 && bridge.size()<2)
					bridge.push_back(*it);
				else if (*it%factor[0] == 0) tail[0].push_back(*it);
				else tail[1].push_back(*it);
			}
			printf("%d ",factor[0]);
			for (auto x : tail[0]) printf("%d ",x);
			printf("%d %d ",bridge[0],factor[1]);
			for (auto x : tail[1]) printf("%d ", x);
			printf("%d\n0\n",bridge[1]);
		}
		else if (factor.size() == 1) {
			for (auto it = divs.begin(); it != divs.end(); ++it)
				printf("%d ",*it);
			printf("\n0\n");
		}
		else {
			vector<int> circle, core;
			factor.push_back(factor[0]);
			for (int i = 0; i < factor.size() - 1; ++i) {
				core.push_back(factor[i]);
				int bridge = factor[i] * factor[i + 1];
				core.push_back(bridge);
				divs.erase(bridge);
				divs.erase(factor[i]);
			}
			for (int i = 0; i < core.size(); ++i) {
				circle.push_back(core[i]);
				if ((i & 1) == 0) {
					int x = core[i];
					vector<int> black_list;
					for (auto it = divs.begin(); it != divs.end(); ++it) {
						if (*it%x == 0) black_list.push_back(*it);
					}
					for (auto x : black_list) {
						divs.erase(x);
						circle.push_back(x);
					}
				}
			}
			for (auto x : circle) printf("%d ",x);
			printf("\n0\n");
		}
	}
 
	return 0;
}