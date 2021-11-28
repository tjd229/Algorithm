//string, greedy
#include<stdio.h>
#include <vector>
using namespace std;
char s[1000011];
int sum[3][1000011];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		scanf("%d %s",&n,s+1);
		int ans = -1;
		vector<int> pos;
		for (i = 1; i <= n; ++i) sum[0][i] = sum[1][i] = sum[2][i] = 0;
		for (i = 1; i <= n; ++i) {
			sum[s[i] - 'a'][i]++;
			if (s[i] == 'a') pos.push_back(i);
			sum[0][i] += sum[0][i - 1];
			sum[1][i] += sum[1][i - 1];
			sum[2][i] += sum[2][i - 1];
		}
		
		for (i = 0; i + 1 < pos.size(); ++i) {
			int r = pos[i + 1], l = pos[i];
			int len = r - l + 1;
			int cntb = sum[1][r] - sum[1][l - 1];
			int cntc = sum[2][r] - sum[2][l - 1];
			if (cntb < 2 && cntc < 2) {
				if (ans<0 || ans>len) ans = len;
			}
		}
		for (i = 0; i + 2 < pos.size(); ++i) {
			int r = pos[i + 2], l = pos[i];
			int len = r - l + 1;
			int cntb = sum[1][r] - sum[1][l - 1];
			int cntc = sum[2][r] - sum[2][l - 1];
			if (cntb < 3 && cntc < 3) {
				if (ans<0 || ans>len) ans = len;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
