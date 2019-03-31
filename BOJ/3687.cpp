//dp
#include <string>
#include <iostream>
using namespace std;
const int cnt[10] = {6,2,5,5,4,5,6,3,7,6};
string maxima[101][2],minima[101][2];
int mx_len[101][2], mn_len[101][2];
void mx(int r,int s) {
	if (r == 0) return;
	if (mx_len[r][s]) return;
	int len = 0;
	int pick = -1;
	for (int i = s; i < 10; ++i) {
		if (r - cnt[i] < 0) continue;
		mx(r - cnt[i], 0);
		int nxt = mx_len[r - cnt[i]][0];
		if (len <= nxt) {
			len = nxt;
			pick = i;
		}
	}
	if (pick != -1) {
		maxima[r][s] = char(pick + '0') + maxima[r-cnt[pick]][0];
		mx_len[r][s] = maxima[r][s].size();
	}
	else mx_len[r][s] = -10;
}
void mn(int r, int s) {
	if (r == 0) return;
	if (mn_len[r][s]) return;
	int len = 100;
	int pick = -1;
	for (int i = 9; i >=s; --i) {
		if (r - cnt[i] < 0) continue;
		mn(r - cnt[i], 0);
		int nxt = mn_len[r - cnt[i]][0];
		if (len >= nxt) {
			len = nxt;
			pick = i;
		}
	}
	if (pick != -1) {
		minima[r][s] = char(pick + '0') + minima[r - cnt[pick]][0];
		mn_len[r][s] = minima[r][s].size();
	}
	else mn_len[r][s] = 1000;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		mn(n, 1); mx(n, 1);
		cout << minima[n][1] << " " << maxima[n][1] << "\n";
	}
	return 0;
}