//dp
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int d[1000][1000];
int max_y[1000],tmp_y[1000];
char ans[1001];
int main() {
	int LCS = 0;
	int x, y;
	cin >> s1 >> s2;
	for (int i = 0; i < s2.size(); ++i) {
		int max_x = 0;
		for (int j = 0; j < s1.size(); ++j) {
			if (s1[j] == s2[i]) d[i][j] = max_x + 1;
			tmp_y[j] = d[i][j];
			if (LCS < d[i][j]) LCS = d[i][j],x=j,y=i;
			if (max_y[j] > max_x) max_x = max_y[j];
			if (max_y[j] < tmp_y[j]) max_y[j] = tmp_y[j];
		}
	}
	cout << LCS << "\n";
	int j = s1.size() - 1, i = s2.size()-1;
	while (LCS) {
		ans[--LCS] = s1[x];
		for (int i = y - 1; i >= 0; --i) {
			for (int j = x - 1; j >= 0; --j) {
				if (d[i][j] == LCS) {
					x = j; y = i;
					i = -1;
					break;
				}
			}
		}
	}
	for (int i = 0; ans[i]; ++i) cout << ans[i];
	return 0;
}