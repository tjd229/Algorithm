//implementation
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int h[9];
vector<int> ans;
int main() {
	int i;
	int ban1, ban2;
	int s = 0;
	for (i = 0; i < 9; ++i) scanf("%d",h+i),s+=h[i];
	for (ban1 = 0; ban1 < 9; ++ban1) {
		for (ban2 = ban1 + 1; ban2 < 9; ++ban2) {
			int tot = s - h[ban1] - h[ban2];
			if (tot == 100) {
				for (i = 0; i < 9; ++i) {
					if (i == ban1 || i == ban2) continue;
					ans.push_back(h[i]);
				}
				sort(ans.begin(), ans.end());
				for (auto h : ans) printf("%d\n",h);
				return 0;
			}
		}
	}
	return 0;
}
