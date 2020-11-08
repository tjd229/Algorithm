//graph
#include <stdio.h>
#include <vector>
using namespace std;
int a[200001];
int c[200002];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		
		vector<int> seg;
		for (i = 2; i <= n; ) {
			int c = 1; int j = i + 1;
			while (j <= n) {
				if (a[j - 1] < a[j]) {
					++j;
					++c;
				}
				else break;
			}
			i = j;
			seg.push_back(c);
		}
		int h = 0;
		c[0] = 1;
		for (i = 0; i < seg.size();) {
			c[1 + h] = 0;
			for (int j = 0; j < c[h] && i<seg.size(); ++j,++i) {
				c[h + 1] += seg[i];
			}
			++h;
		}
		printf("%d\n",h);
	}
 
	return 0;
}
