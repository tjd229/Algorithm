//math
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t; 
	for (scanf("%d", &t); t--;) {
		int i, a, b, c, m; scanf("%d%d%d%d",&a,&b,&c,&m);
		vector<int> v = { a,b,c };
		sort(v.begin(), v.end());
		if (a - 1 + b - 1 + c - 1 < m)
			printf("NO\n");
		else {
			if (v[2] > v[0] + v[1] + 1) {
				int d = v[2] - v[0] - v[1] - 1;
				if (d > m) printf("NO\n");
				else printf("YES\n");
			}
			else
				printf("YES\n");
		}
	}
 
	return 0;
}