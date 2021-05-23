//https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5
//math, greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int X[101];
void decomp(int x,vector<int> &v) {
	while (x) {
		v.push_back(x%10);
		x /=10;
	}
	reverse(v.begin(), v.end());
}
int inc(vector<int> &pre, vector<int> &cur) {
	if (pre.size() < cur.size()) return 0;
	else if (pre.size() == cur.size()) {
		for (int i = 0; i < pre.size(); ++i) {
			if (pre[i] < cur[i]) return 0;
			else if (pre[i] > cur[i]) 
				break;
			
		}
		cur.push_back(0);
		return 1;
	}
	else {
		int coin = 0;
		for (int i = 0; i < cur.size(); ++i) {
			if (pre[i] < cur[i]) {
				coin = pre.size() - cur.size();
				break;
			}
			else if (pre[i] > cur[i]) {
				coin = pre.size() - cur.size() + 1;
				break;
			}
		}
		if (coin) {
			for (int i = 0; i < coin; ++i)
				cur.push_back(0);
			return coin;
		}
		vector<int> add;
		for (int i = cur.size(); i < pre.size(); ++i) 
			add.push_back(pre[i]);
		int carry = 1;
		for (int i = add.size() - 1; i >= 0 && carry; --i) {
			++add[i];
			if (add[i] == 10) {
				add[i] = 0;
				carry = 1;
			}
			else carry = 0;
		}
		if (carry) {
			for (int i = 0; i < add.size()+1; ++i)
				cur.push_back(0);
			return add.size() + 1;
		}
		for (auto x : add) cur.push_back(x);
		return add.size();
	}

}
int main() {
	int tc, T;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, N;
		int ans = 0;
		for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%d",X+i);
		vector<int> last, cur;
		decomp(X[1], last); 
		for (i = 2; i <= N; ++i) {
			decomp(X[i], cur);
			ans += inc(last, cur);
			last = cur; cur.clear();
		}
		printf("Case #%d: %d\n",tc,ans);
	}

	return 0;
}