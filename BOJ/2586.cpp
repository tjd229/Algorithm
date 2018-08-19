//greedy

#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<int> clan[(int)3e5];
int main(){
	int i;
	vector<pii > v;
	int P, F;
	int pos;
	int ans = 0;
	for (scanf("%d%d", &P, &F), i = 0; i<P; i++){
		scanf("%d", &pos);
		v.push_back({ pos, 0 });
	}
	for (i = 0; i<F; i++){
		scanf("%d", &pos);
		v.push_back({ pos, 1 });
	}
	sort(v.begin(), v.end());
	int g = 150000;
	for (auto o : v){
		if (o.second) clan[g++].push_back(o.first);
		else clan[--g].push_back(o.first);
	}
	g = 150000;
	for (; clan[g].size(); g++){
		int len = 0;
		for (i = 1; i<clan[g].size(); i += 2){
			len += clan[g][i] - clan[g][i - 1];
		}
		int mn = len;
		if (clan[g].size() & 1){
			for (--i; i; i -= 2){
				len += clan[g][i] - clan[g][i - 1] - clan[g][i - 1] + clan[g][i - 2];
				if (mn>len) mn = len;
			}
		}
		ans += mn;
	}
	for (g = 150000 - 1; clan[g].size(); g--){
		int len = 0;
		for (i = 1; i<clan[g].size(); i += 2){
			len += clan[g][i] - clan[g][i - 1];
		}
		int mn = len;
		if (clan[g].size() & 1){
			for (--i; i; i -= 2){
				len += clan[g][i] - clan[g][i - 1] - clan[g][i - 1] + clan[g][i - 2];
				if (mn>len) mn = len;
			}
		}
		ans += mn;
	}
	printf("%d", ans);
	return 0;
}
