//implementation
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[100000];
int main() {
	int N;
	while (~scanf("%d", &N)) {
		int len = 0;
		for (int i = 0; i < N; ++i) {
			int p; scanf("%d",&p);
			auto it = lower_bound(d, d + len, p);
			*it = p;
			len = max(len, int(it - d + 1));
		}
		printf("%d\n",len);
	}
	return 0;
}