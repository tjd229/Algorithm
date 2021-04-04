//greedy, geometry
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,nn;
		vector<double> m, d;
		for (scanf("%d", &n), nn = n + n, i = 0; i < nn; ++i) {
			int x, y; scanf("%d%d",&x,&y);
			if (x == 0) m.push_back(abs(y));
			else d.push_back(abs(x));
		}
		sort(m.begin(), m.end()); sort(d.begin(), d.end());
		double e = 0;
		for (i = 0; i < n; ++i) {
			e += sqrt(m[i] * m[i] + d[i] * d[i]);
		}
		printf("%.9lf\n", e);
	}
 
	return 0;
}