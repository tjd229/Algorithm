//math
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		vector<int> v,ans;
		while (n) {
			v.push_back(n%10);
			n /= 10;
		}
		int base = 1;
		for (auto x : v) {
			if (x) ans.push_back(x*base); 
			base *= 10;
		}
		printf("%d\n",ans.size());
		for (auto x : ans) printf("%d ",x);
		printf("\n");
	}
 
	return 0;
}