//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int a[101];
int use[51];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		vector<int> p;
		for (scanf("%d", &n), i = 1; i <= n + n; ++i) 
			scanf("%d",a+i);
		for (i = 1; i <= n + n; ++i) {
			if (use[a[i]] != t + 1) {
				use[a[i]] = t + 1;
				p.push_back(a[i]);
			}
		}
		for (auto x : p) printf("%d ",x);
		printf("\n");
	}
	return 0;
}
