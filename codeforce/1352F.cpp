//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n1, n2, n0; scanf("%d%d%d",&n0,&n1,&n2);
		vector<int> v;
		for (int i = 0;n0 && i <= n0; ++i) v.push_back(0);
		for (int i = 0; n2&&i <= n2; ++i) v.push_back(1);
		if (n0>0 && 0< n2) --n1;
		else if(n0+n2==0) v.push_back(1);
 
		int tog = 1-v.back();
		for (int i = 0; i < n1; ++i, tog = 1 - tog) v.push_back(tog);
		for (auto x : v) printf("%d",x);
		printf("\n");
		
	}
	return 0;
}